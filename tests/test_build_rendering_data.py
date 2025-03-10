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

import unittest
import os
from cppenum import gen

class BuildRenderingDataTest(unittest.TestCase):
    def test_build_rendering_data(self):
        data = gen.load_enum_config("tests/testdata/process_items/process_items.yaml")
        render_data = gen.build_rendering_data("tests/testdata/process_items/process_items.yaml", data)
        self.assertEqual(render_data.config_file_path, "tests/testdata/process_items/process_items.yaml")
        self.assertEqual(render_data.data_type, "int")
        self.assertEqual(render_data.name, "process_items_test")
        self.assertEqual(len(render_data.ifdefs), 0)
        self.assertEqual(len(render_data.items), 21)
        self.assertEqual(render_data.default.name, "INVALID")
        self.assertEqual(render_data.invalid.name, "INVALID")
        self.assertEqual(render_data.author, "Arthur D. Cherba")
        self.assertEqual(render_data.year, 2014)
        self.assertEqual(render_data.maxIdSize, 16)
        self.assertEqual(render_data.maxValIdSize, 21)
        self.assertEqual(render_data.maxValSize, 2)
        self.assertEqual(render_data.namespaces, [])
        self.assertEqual(render_data.value_type, "int")

if __name__ == "__main__":
    unittest.main()
