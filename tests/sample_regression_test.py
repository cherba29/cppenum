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

import contextlib
import difflib
import os
import shutil
import tempfile
import unittest

from cppenum import gen


def GetFileContents(file_path):
  with open(file_path) as f:
    return f.read()


@contextlib.contextmanager
def TempDir():
  path = tempfile.mkdtemp()
  yield path
  shutil.rmtree(path)


def AssertDiffEqual(expected, actual):
  """Like unittest.assertEqual with a diff in the exception message."""
  if expected != actual:
    unified_diff = difflib.unified_diff(expected.splitlines(),
                                        actual.splitlines())
    raise AssertionError('\n'.join(unified_diff))


def _MakeTest(testdata_dir, sample):
  sample_dir = os.path.join(testdata_dir, sample)
  expected_files = set([sample + suffix for suffix in ['.cpp', '.h', '.t.cpp']])
  def TestGen(self):
    with TempDir() as tmp_dir_path:
      status = gen.main(
          ['--config', os.path.join(sample_dir, sample + '.yaml'),
           '--output_dir', tmp_dir_path,
           '--log_level', 'DEBUG'])
      self.assertFalse(status)
      actual_files = set(os.listdir(tmp_dir_path))
      self.assertEquals(expected_files, actual_files)
      for file_name in sorted(expected_files):
        AssertDiffEqual(
            GetFileContents(os.path.join(sample_dir, file_name)),
            GetFileContents(os.path.join(tmp_dir_path, file_name)))

  TestGen.__name__ = 'testGen_{0}'.format(sample)
  return TestGen


def _MakeTestsFrom(testdata_dir, test_class):

  samples = os.listdir(testdata_dir)

  for sample in samples:
    test_func = _MakeTest(testdata_dir, sample)
    setattr(test_class, test_func.__name__, test_func)


class RegressionTests(unittest.TestCase):
  pass


_MakeTestsFrom(
    os.path.join(os.path.dirname(__file__), 'testdata') ,RegressionTests)
