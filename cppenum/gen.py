# Copyright 2016 Arthur D Cherba. All Rights Reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#    http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import argparse
import logging
import os
import sys
import yaml

try:
  from yaml import CLoader as Loader
except ImportError:
  from yaml import Loader


import collections
from mako import exceptions
from mako import lookup
from mako import runtime


# Rendering data collected for each enumeration.
Item = collections.namedtuple('Item', [
    'name',  # Enum name.
    'idName',  # Normalized enum name, ussually upper case.
    'valName',  # Identifier for underlying enum value.
    'open_ifdef',  # None or ifdef label if it should precede this item.
    'close_ifdef',  # None or ifdef label if it should close this item.
    'id',  # Enum id.
    'documentation',  # Comment describing this enum.
    'value',  # Enum underlying value, see data_type in config.
    'display',
])

# Tuple of data sent to mako for rendering.
RenderData = collections.namedtuple('RenderData', [
    'config_file_path',  # Path to configuration filename
    'name',  # Enumeration class name.
    # Abstract data type for this enum, eg. string, double, int, etc.
    'data_type',
    # Actual type used for values,
    # for example 'const char*' for string data type.
    'value_type',
    'ifdefs',  # Number of items in each ifdef.
    'items',  # List of enum items.
    'default',  # Reference to default enum item.
    'invalid',  # Reference to invalid enum item.
    'author',
    'year',
    'maxIdSize',  # Max length of any enum name.
    'maxValIdSize',  # Max length of any enum id name.
    'maxValSize',  # Max length of any enum value.
    'namespaces',  # List of nested namespaces for this enum class.
])


def load_enum_config(filename):
  """Loads yaml file data into dictionary."""
  with open(filename, 'r') as stream:
    try:
      return yaml.load(stream, Loader=Loader)
    except ValueError as e:
      raise Exception('Failed to parse {0}, {1}'.format(filename, e))


def process_items(data_items, data_type):
  """Helper function to build enum item data for rendering."""
  items = []
  # Counts number of items for in each ifdef.
  ifdefs = collections.Counter()

  input_items = [{
      'name': 'INVALID',
      'id': -1,
      'value': '*INVALID*' if data_type == 'string' else -1,
      'display': 'Invalid',
      'documentation':
          'Additional value, set to when object cannot be initialized',
  }] + data_items

  def ifdef_change(item1, item2):
    if item1 and 'ifdef' in item1:
      if item2 and 'ifdef' in item2:
        return item2['ifdef'] if item1['ifdef'] != item2['ifdef'] else None
      return None
    else:
      return item2['ifdef'] if item2 and 'ifdef' in item2 else None

  def get_normalized_value(item, data_type):
    if 'value' not in item:
      if data_type in ['int', 'short']:
        return item['id']
      if data_type == 'string':
        return '"' + item['display'] + '"'
      raise Exception('No value specified for %s of %s' % (item, data_type))
    elif data_type == 'string':
      return '"' + str(item['value']) + '"'

    return item['value']

  for i in range(0, len(input_items)):
    curr_item = input_items[i]
    prev_item = input_items[i - 1] if i > 0 else None
    next_item = input_items[i + 1] if i < len(input_items) - 1 else None
    logging.info('%s', curr_item['name'])
    try:
      item = Item(
          name=curr_item['name'],
          idName=curr_item['name'].upper(),
          valName='VAL_OF_' + curr_item['name'].upper(),
          id=curr_item['id'],
          open_ifdef=ifdef_change(prev_item, curr_item),
          close_ifdef=ifdef_change(next_item, curr_item),
          documentation=curr_item.get('documentation', ''),
          value=get_normalized_value(curr_item, data_type),
          display=curr_item['display'])
    except KeyError as e:
      raise Exception("Could not get %s in %s" % (e, curr_item))
    ifdef = curr_item.get('ifdef', None)
    ifdefs[''] += 1
    items.append(item)
  return items, ifdefs


def build_rendering_data(config_filename, data):
  """Given yaml data constructs dictionary for easy rendering."""
  items, ifdefs = process_items(data['items'], data['data_type'])

  invalid_item = [item for item in items if item.name == 'INVALID'][0]
  if 'default' in data:
    default_item = [item for item in items if item.name == data['default']]
    if not default_item:
      raise Exception(
          'default item {0} is specified but not found in the list'
          .format(data['default']))
    default_item = default_item[0]
  else:
    default_item = invalid_item
  namespaces = []
  if 'namespaces' in data:
    logging.info(type(data['namespaces']))
    if type(data['namespaces']) == str:
      namespaces = [data['namespaces']]
    elif type(data['namespaces']) == list:
      namespaces = data['namespaces']
  logging.info('namespaces %s', namespaces)
  common_prefix = os.path.commonprefix([__file__, config_filename])
  config_file_path = os.path.relpath(
      config_filename, common_prefix).replace('\\', '/')
  return RenderData(
      config_file_path=config_file_path,
      data_type=data['data_type'],
      name=data['name'],
      ifdefs=sorted(ifdefs.most_common(), key=lambda pair: pair[0]),
      # sort by ifdef name.
      items=items,
      default=default_item,
      invalid=invalid_item,
      author='Arthur D. Cherba',
      year=2014,
      maxIdSize=max([len(item.idName) for item in items]),
      maxValIdSize=len('VAL_OF_') + max([len(item.name) for item in items]),
      maxValSize=max([len(str(item.value)) for item in items]),
      namespaces=namespaces,
      value_type=data['data_type'] if data[
        'data_type'] != 'string' else 'const char*')


def render(buf, render_data, template_filename):
  """Using given template renders data into given buffer."""
  root_dir = os.path.dirname(os.path.dirname(__file__))
  lookup_dirs = [os.path.join(root_dir, 'templates')]
  template_lookup = lookup.TemplateLookup(directories=lookup_dirs)
  try:
    template = template_lookup.get_template(template_filename)
    template.render_context(runtime.Context(buf, **render_data._asdict()))
  except:
    traceback = exceptions.RichTraceback()
    for (filename, lineno, function, line) in traceback.traceback:
      print("File %s, line %s, in %s" % (filename, lineno, function))
      print(line, '\n')
    print('%s: %s' % (str(traceback.error.__class__.__name__), traceback.error))


def main(argv=None):
  if argv is None:
    argv = sys.argv[1:]
  parser = argparse.ArgumentParser(description='C++ enum generator.')
  parser.add_argument('--config', required=True,
                      help='YAML format config for enumeration.')
  parser.add_argument('--output_dir', default='./',
                      help='Output dir for .cpp, .h and .t.cpp.')
  parser.add_argument('--log_level', default='WARNING', help='Logging level.')
  args = parser.parse_args(argv)

  # Configure log level based on command line parameter.
  numeric_level = getattr(logging, args.log_level.upper(), None)
  if not isinstance(numeric_level, int):
    raise ValueError('Invalid log level: %s' % args.log_level)
  logging.basicConfig(level=numeric_level)

  logging.info("Loading config from %s", args.config)
  if not args.config:
    raise Exception("Enum config filename is required argument.")
  data = load_enum_config(args.config)
  logging.info(data)

  render_data = build_rendering_data(args.config, data)

  base_filename = os.path.basename(args.config)
  base_filename, _ = os.path.splitext(base_filename)

  # Render header, implementation and test files for this enum definition.
  for template in ['h', 'cpp', 't.cpp']:
    filename = os.path.join(args.output_dir, base_filename + '.' + template)
    logging.info("Rendering %s", filename)
    with open(filename, 'w') as buf:
      render(buf, render_data, template + '.mako')

  return 0


if __name__ == '__main__':
  status = main()
  sys.exit(status)
