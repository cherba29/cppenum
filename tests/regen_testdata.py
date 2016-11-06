# Copyright 2015 Google Inc. All Rights Reserved.
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

import os

from cppenum import gen

_SAMPLE_LIST = [
    'action',
]

_TESTDATA_DIR = os.path.join(os.path.dirname(__file__), 'testdata')


if __name__ == '__main__':
  for sample in _SAMPLE_LIST:
    sample_dir = os.path.join(_TESTDATA_DIR, sample)
    status = gen.main(
        ['--config', os.path.join(sample_dir, sample + '.yaml'),
         '--output_dir', sample_dir,
         '--log_level', 'DEBUG'])
    if status:
      raise Exception('Failed to generate sample [{0}]'.format(sample))
