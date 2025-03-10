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
from io import StringIO
from mako import exceptions
from mako import runtime

class RenderTest(unittest.TestCase):
    def test_render_with_error(self):
        buf = StringIO()
        render_data = gen.RenderData(
            config_file_path="tests/testdata/process_items/process_items.yaml",
            data_type="int",
            name="process_items_test",
            ifdefs=[],
            items=[],
            default=None,
            invalid=None,
            author='Arthur D. Cherba',
            year=2014,
            maxIdSize=0,
            maxValIdSize=0,
            maxValSize=0,
            namespaces=[],
            value_type="int")
        template_filename = "h.mako"
        with self.assertRaises(Exception) as context:
            gen.render(buf, render_data, template_filename)
        
        try:
            gen.render(buf, render_data, template_filename)
        except Exception as e:
            self.assertEqual(True, True)

if __name__ == "__main__":
    unittest.main()
