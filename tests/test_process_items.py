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

class ProcessItemsTest(unittest.TestCase):
    def test_process_items(self):
        data = gen.load_enum_config("tests/testdata/process_items/process_items.yaml")
        items, ifdefs = gen.process_items(data["items"], data["data_type"])
        self.assertEqual(len(items), 21)
        self.assertEqual(len(ifdefs), 0)
        for i in range(0, len(items)):
            self.assertEqual(items[i].name, "ITEM_" + str(i + 1) )
            self.assertEqual(items[i].id, i + 1)
            self.assertEqual(items[i].valName, "VAL_OF_ITEM_" + str(i + 1))
            self.assertEqual(items[i].value, i + 1)
            self.assertEqual(items[i].display, "Item " + str(i + 1))
            self.assertEqual(items[i].documentation, "")
            self.assertEqual(items[i].open_ifdef, None)
            self.assertEqual(items[i].close_ifdef, None)

if __name__ == '__main__':
    unittest.main()
