// DO NOT EDIT CHANGES WILL OVERWITEN WHEN REGENERATED
// Generated from config "tests/testdata/action/action.yaml".

/**
 * @file Action.t.cpp
 * @brief Test for Action enumeration
 *
 * Copyright (C) 2014  Arthur D. Cherba
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "Action.h"

#define BOOST_TEST_ALTERNATIVE_INIT_API
#include <boost/test/unit_test.hpp>

using namespace ::runprofile;

namespace {

Action::Choice const idByOrigOrder[Action::NUM_ENUMS] = {
  Action::INVALID,
  Action::VERSION,
  Action::BENCHMARK,
#ifdef MACHINE
  Action::MACHINE_INFO,
#endif // MACHINE
  Action::INTERPOLATE,
  Action::HELP,
  Action::UNKNOWN,
  Action::NA,
};

// Looks up enum index by original order.
int getEnumOrigIndex(Action::Choice choice) {
  for (int i = 0; i < Action::NUM_ENUMS; ++i) {
    if (idByOrigOrder[i] == choice) {
      return i;
    }
  }
  return -1;
}

}  // namespace

BOOST_AUTO_TEST_CASE(test_action_default_reset) {

  // Create enum object with default value
  Action enumVal;
  BOOST_CHECK_EQUAL(enumVal.getId(), Action::UNKNOWN);

  // Test ==
  BOOST_CHECK_EQUAL(enumVal, Action::UNKNOWN);

  Action enum2;
  BOOST_CHECK_EQUAL(enumVal, enum2);

  BOOST_CHECK_EQUAL(Action().reset(), Action::UNKNOWN);

  Action t_0(0);
  BOOST_CHECK_EQUAL(t_0.reset(), Action::UNKNOWN);

  Action t_1(1);
  BOOST_CHECK_EQUAL(t_1.reset(), Action::UNKNOWN);

  Action t_2(2);
  BOOST_CHECK_EQUAL(t_2.reset(), Action::UNKNOWN);

#ifdef MACHINE
  Action t_3(3);
  BOOST_CHECK_EQUAL(t_3.reset(), Action::UNKNOWN);
#endif // MACHINE

  Action t_4(4);
  BOOST_CHECK_EQUAL(t_4.reset(), Action::UNKNOWN);

  Action t_5(5);
  BOOST_CHECK_EQUAL(t_5.reset(), Action::UNKNOWN);

  Action t_6(6);
  BOOST_CHECK_EQUAL(t_6.reset(), Action::UNKNOWN);

  Action t_7(7);
  BOOST_CHECK_EQUAL(t_7.reset(), Action::UNKNOWN);

  int nDedault = 0;
  for (int i = 0; i <  Action::NUM_ENUMS-1; ++i) {
    if (Action(i) == Action::UNKNOWN) ++nDedault;
  }
  BOOST_CHECK_EQUAL(nDedault,1);

}  // BOOST_AUTO_TEST_CASE(test_action_default_reset)


BOOST_AUTO_TEST_CASE(test_action_invalid) {
  Action enumVal(-1); // Guaranteed to set enum to invalid
  BOOST_CHECK(!enumVal);

  Action enumVal2(Action::NUM_ENUMS); // Guaranteed to set enum to invalid
  BOOST_CHECK(!enumVal2);

  BOOST_CHECK_EQUAL(enumVal, Action::INVALID);
  BOOST_CHECK_EQUAL(enumVal2, Action::INVALID);
  BOOST_CHECK_EQUAL(Action().invalidate(), Action::INVALID);

  int nInvalid = 0;
  for (int i = 0; i <  Action::NUM_ENUMS-1; ++i) {
    if (Action(i) == Action::INVALID) ++nInvalid;
  }
  BOOST_CHECK_EQUAL(nInvalid,1);
}  // BOOST_AUTO_TEST_CASE(test_action_invalid)


BOOST_AUTO_TEST_CASE(test_action_constructor_idx) {
  Action enum_0(Action::INVALID);
  int idx0 = enum_0.getIndex();
  BOOST_CHECK_EQUAL(idx0, getEnumOrigIndex(Action::INVALID));
  Action t_0(idx0);
  BOOST_CHECK_EQUAL(t_0.getId(), Action::INVALID);
  BOOST_CHECK_EQUAL(t_0, Action::INVALID);
  BOOST_CHECK_EQUAL(t_0.getIndex(), idx0);
  BOOST_CHECK_EQUAL(t_0.getName(), "INVALID");
  BOOST_CHECK_EQUAL(t_0.getValue(), -1);
  BOOST_CHECK_EQUAL(t_0.getValue(), (int)(Action::VAL_OF_INVALID));
  BOOST_CHECK_EQUAL(t_0.toString(), "Invalid");

  Action enum_1(Action::VERSION);
  int idx1 = enum_1.getIndex();
  BOOST_CHECK_EQUAL(idx1, getEnumOrigIndex(Action::VERSION));
  Action t_1(idx1);
  BOOST_CHECK_EQUAL(t_1.getId(), Action::VERSION);
  BOOST_CHECK_EQUAL(t_1, Action::VERSION);
  BOOST_CHECK_EQUAL(t_1.getIndex(), idx1);
  BOOST_CHECK_EQUAL(t_1.getName(), "VERSION");
  BOOST_CHECK_EQUAL(t_1.getValue(), 77);
  BOOST_CHECK_EQUAL(t_1.getValue(), (int)(Action::VAL_OF_VERSION));
  BOOST_CHECK_EQUAL(t_1.toString(), "Version");

  Action enum_2(Action::BENCHMARK);
  int idx2 = enum_2.getIndex();
  BOOST_CHECK_EQUAL(idx2, getEnumOrigIndex(Action::BENCHMARK));
  Action t_2(idx2);
  BOOST_CHECK_EQUAL(t_2.getId(), Action::BENCHMARK);
  BOOST_CHECK_EQUAL(t_2, Action::BENCHMARK);
  BOOST_CHECK_EQUAL(t_2.getIndex(), idx2);
  BOOST_CHECK_EQUAL(t_2.getName(), "BENCHMARK");
  BOOST_CHECK_EQUAL(t_2.getValue(), 88);
  BOOST_CHECK_EQUAL(t_2.getValue(), (int)(Action::VAL_OF_BENCHMARK));
  BOOST_CHECK_EQUAL(t_2.toString(), "Benchmark");

#ifdef MACHINE
  Action enum_3(Action::MACHINE_INFO);
  int idx3 = enum_3.getIndex();
  BOOST_CHECK_EQUAL(idx3, getEnumOrigIndex(Action::MACHINE_INFO));
  Action t_3(idx3);
  BOOST_CHECK_EQUAL(t_3.getId(), Action::MACHINE_INFO);
  BOOST_CHECK_EQUAL(t_3, Action::MACHINE_INFO);
  BOOST_CHECK_EQUAL(t_3.getIndex(), idx3);
  BOOST_CHECK_EQUAL(t_3.getName(), "MACHINE_INFO");
  BOOST_CHECK_EQUAL(t_3.getValue(), 99);
  BOOST_CHECK_EQUAL(t_3.getValue(), (int)(Action::VAL_OF_MACHINE_INFO));
  BOOST_CHECK_EQUAL(t_3.toString(), "Machine Info");
#endif // MACHINE

  Action enum_4(Action::INTERPOLATE);
  int idx4 = enum_4.getIndex();
  BOOST_CHECK_EQUAL(idx4, getEnumOrigIndex(Action::INTERPOLATE));
  Action t_4(idx4);
  BOOST_CHECK_EQUAL(t_4.getId(), Action::INTERPOLATE);
  BOOST_CHECK_EQUAL(t_4, Action::INTERPOLATE);
  BOOST_CHECK_EQUAL(t_4.getIndex(), idx4);
  BOOST_CHECK_EQUAL(t_4.getName(), "INTERPOLATE");
  BOOST_CHECK_EQUAL(t_4.getValue(), 15);
  BOOST_CHECK_EQUAL(t_4.getValue(), (int)(Action::VAL_OF_INTERPOLATE));
  BOOST_CHECK_EQUAL(t_4.toString(), "Interpolate");

  Action enum_5(Action::HELP);
  int idx5 = enum_5.getIndex();
  BOOST_CHECK_EQUAL(idx5, getEnumOrigIndex(Action::HELP));
  Action t_5(idx5);
  BOOST_CHECK_EQUAL(t_5.getId(), Action::HELP);
  BOOST_CHECK_EQUAL(t_5, Action::HELP);
  BOOST_CHECK_EQUAL(t_5.getIndex(), idx5);
  BOOST_CHECK_EQUAL(t_5.getName(), "HELP");
  BOOST_CHECK_EQUAL(t_5.getValue(), 700);
  BOOST_CHECK_EQUAL(t_5.getValue(), (int)(Action::VAL_OF_HELP));
  BOOST_CHECK_EQUAL(t_5.toString(), "Help");

  Action enum_6(Action::UNKNOWN);
  int idx6 = enum_6.getIndex();
  BOOST_CHECK_EQUAL(idx6, getEnumOrigIndex(Action::UNKNOWN));
  Action t_6(idx6);
  BOOST_CHECK_EQUAL(t_6.getId(), Action::UNKNOWN);
  BOOST_CHECK_EQUAL(t_6, Action::UNKNOWN);
  BOOST_CHECK_EQUAL(t_6.getIndex(), idx6);
  BOOST_CHECK_EQUAL(t_6.getName(), "UNKNOWN");
  BOOST_CHECK_EQUAL(t_6.getValue(), 1000);
  BOOST_CHECK_EQUAL(t_6.getValue(), (int)(Action::VAL_OF_UNKNOWN));
  BOOST_CHECK_EQUAL(t_6.toString(), "Unknown");

  Action enum_7(Action::NA);
  int idx7 = enum_7.getIndex();
  BOOST_CHECK_EQUAL(idx7, getEnumOrigIndex(Action::NA));
  Action t_7(idx7);
  BOOST_CHECK_EQUAL(t_7.getId(), Action::NA);
  BOOST_CHECK_EQUAL(t_7, Action::NA);
  BOOST_CHECK_EQUAL(t_7.getIndex(), idx7);
  BOOST_CHECK_EQUAL(t_7.getName(), "NA");
  BOOST_CHECK_EQUAL(t_7.getValue(), 900);
  BOOST_CHECK_EQUAL(t_7.getValue(), (int)(Action::VAL_OF_NA));
  BOOST_CHECK_EQUAL(t_7.toString(), "Not Applicable");

}  // BOOST_AUTO_TEST_CASE(test_action_constructor_idx)


BOOST_AUTO_TEST_CASE(test_action_constructor_name) {
  Action t_0("INVALID");
  BOOST_CHECK_EQUAL(t_0.getId(), Action::INVALID);
  BOOST_CHECK_EQUAL(t_0, Action::INVALID);
  BOOST_CHECK_EQUAL(t_0.getIndex(), getEnumOrigIndex(Action::INVALID));
  BOOST_CHECK_EQUAL(t_0.getName(), "INVALID");
  BOOST_CHECK_EQUAL(t_0.getValue(), -1);
  BOOST_CHECK_EQUAL(t_0.getValue(), (int)(Action::VAL_OF_INVALID));
  BOOST_CHECK_EQUAL(t_0.toString(), "Invalid");

  Action t_1("VERSION");
  BOOST_CHECK_EQUAL(t_1.getId(), Action::VERSION);
  BOOST_CHECK_EQUAL(t_1, Action::VERSION);
  BOOST_CHECK_EQUAL(t_1.getIndex(), getEnumOrigIndex(Action::VERSION));
  BOOST_CHECK_EQUAL(t_1.getName(), "VERSION");
  BOOST_CHECK_EQUAL(t_1.getValue(), 77);
  BOOST_CHECK_EQUAL(t_1.getValue(), (int)(Action::VAL_OF_VERSION));
  BOOST_CHECK_EQUAL(t_1.toString(), "Version");

  Action t_2("BENCHMARK");
  BOOST_CHECK_EQUAL(t_2.getId(), Action::BENCHMARK);
  BOOST_CHECK_EQUAL(t_2, Action::BENCHMARK);
  BOOST_CHECK_EQUAL(t_2.getIndex(), getEnumOrigIndex(Action::BENCHMARK));
  BOOST_CHECK_EQUAL(t_2.getName(), "BENCHMARK");
  BOOST_CHECK_EQUAL(t_2.getValue(), 88);
  BOOST_CHECK_EQUAL(t_2.getValue(), (int)(Action::VAL_OF_BENCHMARK));
  BOOST_CHECK_EQUAL(t_2.toString(), "Benchmark");

#ifdef MACHINE
  Action t_3("MACHINE_INFO");
  BOOST_CHECK_EQUAL(t_3.getId(), Action::MACHINE_INFO);
  BOOST_CHECK_EQUAL(t_3, Action::MACHINE_INFO);
  BOOST_CHECK_EQUAL(t_3.getIndex(), getEnumOrigIndex(Action::MACHINE_INFO));
  BOOST_CHECK_EQUAL(t_3.getName(), "MACHINE_INFO");
  BOOST_CHECK_EQUAL(t_3.getValue(), 99);
  BOOST_CHECK_EQUAL(t_3.getValue(), (int)(Action::VAL_OF_MACHINE_INFO));
  BOOST_CHECK_EQUAL(t_3.toString(), "Machine Info");
#endif // MACHINE

  Action t_4("INTERPOLATE");
  BOOST_CHECK_EQUAL(t_4.getId(), Action::INTERPOLATE);
  BOOST_CHECK_EQUAL(t_4, Action::INTERPOLATE);
  BOOST_CHECK_EQUAL(t_4.getIndex(), getEnumOrigIndex(Action::INTERPOLATE));
  BOOST_CHECK_EQUAL(t_4.getName(), "INTERPOLATE");
  BOOST_CHECK_EQUAL(t_4.getValue(), 15);
  BOOST_CHECK_EQUAL(t_4.getValue(), (int)(Action::VAL_OF_INTERPOLATE));
  BOOST_CHECK_EQUAL(t_4.toString(), "Interpolate");

  Action t_5("HELP");
  BOOST_CHECK_EQUAL(t_5.getId(), Action::HELP);
  BOOST_CHECK_EQUAL(t_5, Action::HELP);
  BOOST_CHECK_EQUAL(t_5.getIndex(), getEnumOrigIndex(Action::HELP));
  BOOST_CHECK_EQUAL(t_5.getName(), "HELP");
  BOOST_CHECK_EQUAL(t_5.getValue(), 700);
  BOOST_CHECK_EQUAL(t_5.getValue(), (int)(Action::VAL_OF_HELP));
  BOOST_CHECK_EQUAL(t_5.toString(), "Help");

  Action t_6("UNKNOWN");
  BOOST_CHECK_EQUAL(t_6.getId(), Action::UNKNOWN);
  BOOST_CHECK_EQUAL(t_6, Action::UNKNOWN);
  BOOST_CHECK_EQUAL(t_6.getIndex(), getEnumOrigIndex(Action::UNKNOWN));
  BOOST_CHECK_EQUAL(t_6.getName(), "UNKNOWN");
  BOOST_CHECK_EQUAL(t_6.getValue(), 1000);
  BOOST_CHECK_EQUAL(t_6.getValue(), (int)(Action::VAL_OF_UNKNOWN));
  BOOST_CHECK_EQUAL(t_6.toString(), "Unknown");

  Action t_7("NA");
  BOOST_CHECK_EQUAL(t_7.getId(), Action::NA);
  BOOST_CHECK_EQUAL(t_7, Action::NA);
  BOOST_CHECK_EQUAL(t_7.getIndex(), getEnumOrigIndex(Action::NA));
  BOOST_CHECK_EQUAL(t_7.getName(), "NA");
  BOOST_CHECK_EQUAL(t_7.getValue(), 900);
  BOOST_CHECK_EQUAL(t_7.getValue(), (int)(Action::VAL_OF_NA));
  BOOST_CHECK_EQUAL(t_7.toString(), "Not Applicable");

}  // BOOST_AUTO_TEST_CASE(test_action_constructor_name)


BOOST_AUTO_TEST_CASE(test_action_constructor_name_len) {
  Action t_0("INVALID", 7);
  BOOST_CHECK_EQUAL(t_0.getId(), Action::INVALID);
  BOOST_CHECK_EQUAL(t_0, Action::INVALID);
  BOOST_CHECK_EQUAL(t_0.getIndex(), getEnumOrigIndex(Action::INVALID));
  BOOST_CHECK_EQUAL(t_0.getName(), "INVALID");
  BOOST_CHECK_EQUAL(t_0.getValue(), -1);
  BOOST_CHECK_EQUAL(t_0.getValue(), (int)(Action::VAL_OF_INVALID));
  BOOST_CHECK_EQUAL(t_0.toString(), "Invalid");

  Action t_1("VERSION", 7);
  BOOST_CHECK_EQUAL(t_1.getId(), Action::VERSION);
  BOOST_CHECK_EQUAL(t_1, Action::VERSION);
  BOOST_CHECK_EQUAL(t_1.getIndex(), getEnumOrigIndex(Action::VERSION));
  BOOST_CHECK_EQUAL(t_1.getName(), "VERSION");
  BOOST_CHECK_EQUAL(t_1.getValue(), 77);
  BOOST_CHECK_EQUAL(t_1.getValue(), (int)(Action::VAL_OF_VERSION));
  BOOST_CHECK_EQUAL(t_1.toString(), "Version");

  Action t_2("BENCHMARK", 9);
  BOOST_CHECK_EQUAL(t_2.getId(), Action::BENCHMARK);
  BOOST_CHECK_EQUAL(t_2, Action::BENCHMARK);
  BOOST_CHECK_EQUAL(t_2.getIndex(), getEnumOrigIndex(Action::BENCHMARK));
  BOOST_CHECK_EQUAL(t_2.getName(), "BENCHMARK");
  BOOST_CHECK_EQUAL(t_2.getValue(), 88);
  BOOST_CHECK_EQUAL(t_2.getValue(), (int)(Action::VAL_OF_BENCHMARK));
  BOOST_CHECK_EQUAL(t_2.toString(), "Benchmark");

#ifdef MACHINE
  Action t_3("MACHINE_INFO", 12);
  BOOST_CHECK_EQUAL(t_3.getId(), Action::MACHINE_INFO);
  BOOST_CHECK_EQUAL(t_3, Action::MACHINE_INFO);
  BOOST_CHECK_EQUAL(t_3.getIndex(), getEnumOrigIndex(Action::MACHINE_INFO));
  BOOST_CHECK_EQUAL(t_3.getName(), "MACHINE_INFO");
  BOOST_CHECK_EQUAL(t_3.getValue(), 99);
  BOOST_CHECK_EQUAL(t_3.getValue(), (int)(Action::VAL_OF_MACHINE_INFO));
  BOOST_CHECK_EQUAL(t_3.toString(), "Machine Info");
#endif // MACHINE

  Action t_4("INTERPOLATE", 11);
  BOOST_CHECK_EQUAL(t_4.getId(), Action::INTERPOLATE);
  BOOST_CHECK_EQUAL(t_4, Action::INTERPOLATE);
  BOOST_CHECK_EQUAL(t_4.getIndex(), getEnumOrigIndex(Action::INTERPOLATE));
  BOOST_CHECK_EQUAL(t_4.getName(), "INTERPOLATE");
  BOOST_CHECK_EQUAL(t_4.getValue(), 15);
  BOOST_CHECK_EQUAL(t_4.getValue(), (int)(Action::VAL_OF_INTERPOLATE));
  BOOST_CHECK_EQUAL(t_4.toString(), "Interpolate");

  Action t_5("HELP", 4);
  BOOST_CHECK_EQUAL(t_5.getId(), Action::HELP);
  BOOST_CHECK_EQUAL(t_5, Action::HELP);
  BOOST_CHECK_EQUAL(t_5.getIndex(), getEnumOrigIndex(Action::HELP));
  BOOST_CHECK_EQUAL(t_5.getName(), "HELP");
  BOOST_CHECK_EQUAL(t_5.getValue(), 700);
  BOOST_CHECK_EQUAL(t_5.getValue(), (int)(Action::VAL_OF_HELP));
  BOOST_CHECK_EQUAL(t_5.toString(), "Help");

  Action t_6("UNKNOWN", 7);
  BOOST_CHECK_EQUAL(t_6.getId(), Action::UNKNOWN);
  BOOST_CHECK_EQUAL(t_6, Action::UNKNOWN);
  BOOST_CHECK_EQUAL(t_6.getIndex(), getEnumOrigIndex(Action::UNKNOWN));
  BOOST_CHECK_EQUAL(t_6.getName(), "UNKNOWN");
  BOOST_CHECK_EQUAL(t_6.getValue(), 1000);
  BOOST_CHECK_EQUAL(t_6.getValue(), (int)(Action::VAL_OF_UNKNOWN));
  BOOST_CHECK_EQUAL(t_6.toString(), "Unknown");

  Action t_7("NA", 2);
  BOOST_CHECK_EQUAL(t_7.getId(), Action::NA);
  BOOST_CHECK_EQUAL(t_7, Action::NA);
  BOOST_CHECK_EQUAL(t_7.getIndex(), getEnumOrigIndex(Action::NA));
  BOOST_CHECK_EQUAL(t_7.getName(), "NA");
  BOOST_CHECK_EQUAL(t_7.getValue(), 900);
  BOOST_CHECK_EQUAL(t_7.getValue(), (int)(Action::VAL_OF_NA));
  BOOST_CHECK_EQUAL(t_7.toString(), "Not Applicable");

}  // BOOST_AUTO_TEST_CASE(test_action_constructor_name_len)


BOOST_AUTO_TEST_CASE(test_action_constructor_enum) {
  Action t_0(Action::INVALID);
  BOOST_CHECK_EQUAL(t_0.getId(), Action::INVALID);
  BOOST_CHECK_EQUAL(t_0, Action::INVALID);
  BOOST_CHECK_EQUAL(t_0.getIndex(), getEnumOrigIndex(Action::INVALID));
  BOOST_CHECK_EQUAL(t_0.getName(), "INVALID");
  BOOST_CHECK_EQUAL(t_0.getValue(), -1);
  BOOST_CHECK_EQUAL(t_0.getValue(), (int)(Action::VAL_OF_INVALID));
  BOOST_CHECK_EQUAL(t_0.toString(), "Invalid");

  Action t_1(Action::VERSION);
  BOOST_CHECK_EQUAL(t_1.getId(), Action::VERSION);
  BOOST_CHECK_EQUAL(t_1, Action::VERSION);
  BOOST_CHECK_EQUAL(t_1.getIndex(), getEnumOrigIndex(Action::VERSION));
  BOOST_CHECK_EQUAL(t_1.getName(), "VERSION");
  BOOST_CHECK_EQUAL(t_1.getValue(), 77);
  BOOST_CHECK_EQUAL(t_1.getValue(), (int)(Action::VAL_OF_VERSION));
  BOOST_CHECK_EQUAL(t_1.toString(), "Version");

  Action t_2(Action::BENCHMARK);
  BOOST_CHECK_EQUAL(t_2.getId(), Action::BENCHMARK);
  BOOST_CHECK_EQUAL(t_2, Action::BENCHMARK);
  BOOST_CHECK_EQUAL(t_2.getIndex(), getEnumOrigIndex(Action::BENCHMARK));
  BOOST_CHECK_EQUAL(t_2.getName(), "BENCHMARK");
  BOOST_CHECK_EQUAL(t_2.getValue(), 88);
  BOOST_CHECK_EQUAL(t_2.getValue(), (int)(Action::VAL_OF_BENCHMARK));
  BOOST_CHECK_EQUAL(t_2.toString(), "Benchmark");

#ifdef MACHINE
  Action t_3(Action::MACHINE_INFO);
  BOOST_CHECK_EQUAL(t_3.getId(), Action::MACHINE_INFO);
  BOOST_CHECK_EQUAL(t_3, Action::MACHINE_INFO);
  BOOST_CHECK_EQUAL(t_3.getIndex(), getEnumOrigIndex(Action::MACHINE_INFO));
  BOOST_CHECK_EQUAL(t_3.getName(), "MACHINE_INFO");
  BOOST_CHECK_EQUAL(t_3.getValue(), 99);
  BOOST_CHECK_EQUAL(t_3.getValue(), (int)(Action::VAL_OF_MACHINE_INFO));
  BOOST_CHECK_EQUAL(t_3.toString(), "Machine Info");
#endif // MACHINE

  Action t_4(Action::INTERPOLATE);
  BOOST_CHECK_EQUAL(t_4.getId(), Action::INTERPOLATE);
  BOOST_CHECK_EQUAL(t_4, Action::INTERPOLATE);
  BOOST_CHECK_EQUAL(t_4.getIndex(), getEnumOrigIndex(Action::INTERPOLATE));
  BOOST_CHECK_EQUAL(t_4.getName(), "INTERPOLATE");
  BOOST_CHECK_EQUAL(t_4.getValue(), 15);
  BOOST_CHECK_EQUAL(t_4.getValue(), (int)(Action::VAL_OF_INTERPOLATE));
  BOOST_CHECK_EQUAL(t_4.toString(), "Interpolate");

  Action t_5(Action::HELP);
  BOOST_CHECK_EQUAL(t_5.getId(), Action::HELP);
  BOOST_CHECK_EQUAL(t_5, Action::HELP);
  BOOST_CHECK_EQUAL(t_5.getIndex(), getEnumOrigIndex(Action::HELP));
  BOOST_CHECK_EQUAL(t_5.getName(), "HELP");
  BOOST_CHECK_EQUAL(t_5.getValue(), 700);
  BOOST_CHECK_EQUAL(t_5.getValue(), (int)(Action::VAL_OF_HELP));
  BOOST_CHECK_EQUAL(t_5.toString(), "Help");

  Action t_6(Action::UNKNOWN);
  BOOST_CHECK_EQUAL(t_6.getId(), Action::UNKNOWN);
  BOOST_CHECK_EQUAL(t_6, Action::UNKNOWN);
  BOOST_CHECK_EQUAL(t_6.getIndex(), getEnumOrigIndex(Action::UNKNOWN));
  BOOST_CHECK_EQUAL(t_6.getName(), "UNKNOWN");
  BOOST_CHECK_EQUAL(t_6.getValue(), 1000);
  BOOST_CHECK_EQUAL(t_6.getValue(), (int)(Action::VAL_OF_UNKNOWN));
  BOOST_CHECK_EQUAL(t_6.toString(), "Unknown");

  Action t_7(Action::NA);
  BOOST_CHECK_EQUAL(t_7.getId(), Action::NA);
  BOOST_CHECK_EQUAL(t_7, Action::NA);
  BOOST_CHECK_EQUAL(t_7.getIndex(), getEnumOrigIndex(Action::NA));
  BOOST_CHECK_EQUAL(t_7.getName(), "NA");
  BOOST_CHECK_EQUAL(t_7.getValue(), 900);
  BOOST_CHECK_EQUAL(t_7.getValue(), (int)(Action::VAL_OF_NA));
  BOOST_CHECK_EQUAL(t_7.toString(), "Not Applicable");

}  // BOOST_AUTO_TEST_CASE(test_action_constructor_enum)


BOOST_AUTO_TEST_CASE( test_action_from_value ) {
  Action t_0;
  t_0.setToValue(-1);
  BOOST_CHECK_EQUAL(t_0.getId(), Action::INVALID);
  BOOST_CHECK_EQUAL(t_0, Action::INVALID);
  BOOST_CHECK_EQUAL(t_0.getIndex(), getEnumOrigIndex(Action::INVALID));
  BOOST_CHECK_EQUAL(t_0.getName(), "INVALID");
  BOOST_CHECK_EQUAL(t_0.getValue(), -1);
  BOOST_CHECK_EQUAL(t_0.getValue(), (int)(Action::VAL_OF_INVALID));
  BOOST_CHECK_EQUAL(t_0.toString(), "Invalid");

  Action t_1;
  t_1.setToValue(77);
  BOOST_CHECK_EQUAL(t_1.getId(), Action::VERSION);
  BOOST_CHECK_EQUAL(t_1, Action::VERSION);
  BOOST_CHECK_EQUAL(t_1.getIndex(), getEnumOrigIndex(Action::VERSION));
  BOOST_CHECK_EQUAL(t_1.getName(), "VERSION");
  BOOST_CHECK_EQUAL(t_1.getValue(), 77);
  BOOST_CHECK_EQUAL(t_1.getValue(), (int)(Action::VAL_OF_VERSION));
  BOOST_CHECK_EQUAL(t_1.toString(), "Version");

  Action t_2;
  t_2.setToValue(88);
  BOOST_CHECK_EQUAL(t_2.getId(), Action::BENCHMARK);
  BOOST_CHECK_EQUAL(t_2, Action::BENCHMARK);
  BOOST_CHECK_EQUAL(t_2.getIndex(), getEnumOrigIndex(Action::BENCHMARK));
  BOOST_CHECK_EQUAL(t_2.getName(), "BENCHMARK");
  BOOST_CHECK_EQUAL(t_2.getValue(), 88);
  BOOST_CHECK_EQUAL(t_2.getValue(), (int)(Action::VAL_OF_BENCHMARK));
  BOOST_CHECK_EQUAL(t_2.toString(), "Benchmark");

#ifdef MACHINE
  Action t_3;
  t_3.setToValue(99);
  BOOST_CHECK_EQUAL(t_3.getId(), Action::MACHINE_INFO);
  BOOST_CHECK_EQUAL(t_3, Action::MACHINE_INFO);
  BOOST_CHECK_EQUAL(t_3.getIndex(), getEnumOrigIndex(Action::MACHINE_INFO));
  BOOST_CHECK_EQUAL(t_3.getName(), "MACHINE_INFO");
  BOOST_CHECK_EQUAL(t_3.getValue(), 99);
  BOOST_CHECK_EQUAL(t_3.getValue(), (int)(Action::VAL_OF_MACHINE_INFO));
  BOOST_CHECK_EQUAL(t_3.toString(), "Machine Info");
#endif // MACHINE

  Action t_4;
  t_4.setToValue(15);
  BOOST_CHECK_EQUAL(t_4.getId(), Action::INTERPOLATE);
  BOOST_CHECK_EQUAL(t_4, Action::INTERPOLATE);
  BOOST_CHECK_EQUAL(t_4.getIndex(), getEnumOrigIndex(Action::INTERPOLATE));
  BOOST_CHECK_EQUAL(t_4.getName(), "INTERPOLATE");
  BOOST_CHECK_EQUAL(t_4.getValue(), 15);
  BOOST_CHECK_EQUAL(t_4.getValue(), (int)(Action::VAL_OF_INTERPOLATE));
  BOOST_CHECK_EQUAL(t_4.toString(), "Interpolate");

  Action t_5;
  t_5.setToValue(700);
  BOOST_CHECK_EQUAL(t_5.getId(), Action::HELP);
  BOOST_CHECK_EQUAL(t_5, Action::HELP);
  BOOST_CHECK_EQUAL(t_5.getIndex(), getEnumOrigIndex(Action::HELP));
  BOOST_CHECK_EQUAL(t_5.getName(), "HELP");
  BOOST_CHECK_EQUAL(t_5.getValue(), 700);
  BOOST_CHECK_EQUAL(t_5.getValue(), (int)(Action::VAL_OF_HELP));
  BOOST_CHECK_EQUAL(t_5.toString(), "Help");

  Action t_6;
  t_6.setToValue(1000);
  BOOST_CHECK_EQUAL(t_6.getId(), Action::UNKNOWN);
  BOOST_CHECK_EQUAL(t_6, Action::UNKNOWN);
  BOOST_CHECK_EQUAL(t_6.getIndex(), getEnumOrigIndex(Action::UNKNOWN));
  BOOST_CHECK_EQUAL(t_6.getName(), "UNKNOWN");
  BOOST_CHECK_EQUAL(t_6.getValue(), 1000);
  BOOST_CHECK_EQUAL(t_6.getValue(), (int)(Action::VAL_OF_UNKNOWN));
  BOOST_CHECK_EQUAL(t_6.toString(), "Unknown");

  Action t_7;
  t_7.setToValue(900);
  BOOST_CHECK_EQUAL(t_7.getId(), Action::NA);
  BOOST_CHECK_EQUAL(t_7, Action::NA);
  BOOST_CHECK_EQUAL(t_7.getIndex(), getEnumOrigIndex(Action::NA));
  BOOST_CHECK_EQUAL(t_7.getName(), "NA");
  BOOST_CHECK_EQUAL(t_7.getValue(), 900);
  BOOST_CHECK_EQUAL(t_7.getValue(), (int)(Action::VAL_OF_NA));
  BOOST_CHECK_EQUAL(t_7.toString(), "Not Applicable");

}  // BOOST_AUTO_TEST_CASE( test_action_from_value )


BOOST_AUTO_TEST_CASE( test_action_from_set_id ) {
  Action t_0;
  t_0.setId(Action::INVALID);
  BOOST_CHECK_EQUAL(t_0.getId(), Action::INVALID);
  BOOST_CHECK_EQUAL(t_0, Action::INVALID);
  BOOST_CHECK_EQUAL(t_0.getIndex(), getEnumOrigIndex(Action::INVALID));
  BOOST_CHECK_EQUAL(t_0.getName(), "INVALID");
  BOOST_CHECK_EQUAL(t_0.getValue(), -1);
  BOOST_CHECK_EQUAL(t_0.getValue(), (int)(Action::VAL_OF_INVALID));
  BOOST_CHECK_EQUAL(t_0.toString(), "Invalid");

  Action t_1;
  t_1.setId(Action::VERSION);
  BOOST_CHECK_EQUAL(t_1.getId(), Action::VERSION);
  BOOST_CHECK_EQUAL(t_1, Action::VERSION);
  BOOST_CHECK_EQUAL(t_1.getIndex(), getEnumOrigIndex(Action::VERSION));
  BOOST_CHECK_EQUAL(t_1.getName(), "VERSION");
  BOOST_CHECK_EQUAL(t_1.getValue(), 77);
  BOOST_CHECK_EQUAL(t_1.getValue(), (int)(Action::VAL_OF_VERSION));
  BOOST_CHECK_EQUAL(t_1.toString(), "Version");

  Action t_2;
  t_2.setId(Action::BENCHMARK);
  BOOST_CHECK_EQUAL(t_2.getId(), Action::BENCHMARK);
  BOOST_CHECK_EQUAL(t_2, Action::BENCHMARK);
  BOOST_CHECK_EQUAL(t_2.getIndex(), getEnumOrigIndex(Action::BENCHMARK));
  BOOST_CHECK_EQUAL(t_2.getName(), "BENCHMARK");
  BOOST_CHECK_EQUAL(t_2.getValue(), 88);
  BOOST_CHECK_EQUAL(t_2.getValue(), (int)(Action::VAL_OF_BENCHMARK));
  BOOST_CHECK_EQUAL(t_2.toString(), "Benchmark");

#ifdef MACHINE
  Action t_3;
  t_3.setId(Action::MACHINE_INFO);
  BOOST_CHECK_EQUAL(t_3.getId(), Action::MACHINE_INFO);
  BOOST_CHECK_EQUAL(t_3, Action::MACHINE_INFO);
  BOOST_CHECK_EQUAL(t_3.getIndex(), getEnumOrigIndex(Action::MACHINE_INFO));
  BOOST_CHECK_EQUAL(t_3.getName(), "MACHINE_INFO");
  BOOST_CHECK_EQUAL(t_3.getValue(), 99);
  BOOST_CHECK_EQUAL(t_3.getValue(), (int)(Action::VAL_OF_MACHINE_INFO));
  BOOST_CHECK_EQUAL(t_3.toString(), "Machine Info");
#endif // MACHINE

  Action t_4;
  t_4.setId(Action::INTERPOLATE);
  BOOST_CHECK_EQUAL(t_4.getId(), Action::INTERPOLATE);
  BOOST_CHECK_EQUAL(t_4, Action::INTERPOLATE);
  BOOST_CHECK_EQUAL(t_4.getIndex(), getEnumOrigIndex(Action::INTERPOLATE));
  BOOST_CHECK_EQUAL(t_4.getName(), "INTERPOLATE");
  BOOST_CHECK_EQUAL(t_4.getValue(), 15);
  BOOST_CHECK_EQUAL(t_4.getValue(), (int)(Action::VAL_OF_INTERPOLATE));
  BOOST_CHECK_EQUAL(t_4.toString(), "Interpolate");

  Action t_5;
  t_5.setId(Action::HELP);
  BOOST_CHECK_EQUAL(t_5.getId(), Action::HELP);
  BOOST_CHECK_EQUAL(t_5, Action::HELP);
  BOOST_CHECK_EQUAL(t_5.getIndex(), getEnumOrigIndex(Action::HELP));
  BOOST_CHECK_EQUAL(t_5.getName(), "HELP");
  BOOST_CHECK_EQUAL(t_5.getValue(), 700);
  BOOST_CHECK_EQUAL(t_5.getValue(), (int)(Action::VAL_OF_HELP));
  BOOST_CHECK_EQUAL(t_5.toString(), "Help");

  Action t_6;
  t_6.setId(Action::UNKNOWN);
  BOOST_CHECK_EQUAL(t_6.getId(), Action::UNKNOWN);
  BOOST_CHECK_EQUAL(t_6, Action::UNKNOWN);
  BOOST_CHECK_EQUAL(t_6.getIndex(), getEnumOrigIndex(Action::UNKNOWN));
  BOOST_CHECK_EQUAL(t_6.getName(), "UNKNOWN");
  BOOST_CHECK_EQUAL(t_6.getValue(), 1000);
  BOOST_CHECK_EQUAL(t_6.getValue(), (int)(Action::VAL_OF_UNKNOWN));
  BOOST_CHECK_EQUAL(t_6.toString(), "Unknown");

  Action t_7;
  t_7.setId(Action::NA);
  BOOST_CHECK_EQUAL(t_7.getId(), Action::NA);
  BOOST_CHECK_EQUAL(t_7, Action::NA);
  BOOST_CHECK_EQUAL(t_7.getIndex(), getEnumOrigIndex(Action::NA));
  BOOST_CHECK_EQUAL(t_7.getName(), "NA");
  BOOST_CHECK_EQUAL(t_7.getValue(), 900);
  BOOST_CHECK_EQUAL(t_7.getValue(), (int)(Action::VAL_OF_NA));
  BOOST_CHECK_EQUAL(t_7.toString(), "Not Applicable");

}  // BOOST_AUTO_TEST_CASE( test_action_from_set_id )


BOOST_AUTO_TEST_CASE(test_action_from_set_index) {
  Action t_0;
  int idx0 = getEnumOrigIndex(Action::INVALID);
  t_0.setToIndex(idx0);
  BOOST_CHECK_EQUAL(t_0.getId(), Action::INVALID);
  BOOST_CHECK_EQUAL(t_0, Action::INVALID);
  BOOST_CHECK_EQUAL(t_0.getIndex(), idx0);
  BOOST_CHECK_EQUAL(t_0.getName(), "INVALID");
  BOOST_CHECK_EQUAL(t_0.getValue(), -1);
  BOOST_CHECK_EQUAL(t_0.getValue(), (int)(Action::VAL_OF_INVALID));
  BOOST_CHECK_EQUAL(t_0.toString(), "Invalid");

  Action t_1;
  int idx1 = getEnumOrigIndex(Action::VERSION);
  t_1.setToIndex(idx1);
  BOOST_CHECK_EQUAL(t_1.getId(), Action::VERSION);
  BOOST_CHECK_EQUAL(t_1, Action::VERSION);
  BOOST_CHECK_EQUAL(t_1.getIndex(), idx1);
  BOOST_CHECK_EQUAL(t_1.getName(), "VERSION");
  BOOST_CHECK_EQUAL(t_1.getValue(), 77);
  BOOST_CHECK_EQUAL(t_1.getValue(), (int)(Action::VAL_OF_VERSION));
  BOOST_CHECK_EQUAL(t_1.toString(), "Version");

  Action t_2;
  int idx2 = getEnumOrigIndex(Action::BENCHMARK);
  t_2.setToIndex(idx2);
  BOOST_CHECK_EQUAL(t_2.getId(), Action::BENCHMARK);
  BOOST_CHECK_EQUAL(t_2, Action::BENCHMARK);
  BOOST_CHECK_EQUAL(t_2.getIndex(), idx2);
  BOOST_CHECK_EQUAL(t_2.getName(), "BENCHMARK");
  BOOST_CHECK_EQUAL(t_2.getValue(), 88);
  BOOST_CHECK_EQUAL(t_2.getValue(), (int)(Action::VAL_OF_BENCHMARK));
  BOOST_CHECK_EQUAL(t_2.toString(), "Benchmark");

#ifdef MACHINE
  Action t_3;
  int idx3 = getEnumOrigIndex(Action::MACHINE_INFO);
  t_3.setToIndex(idx3);
  BOOST_CHECK_EQUAL(t_3.getId(), Action::MACHINE_INFO);
  BOOST_CHECK_EQUAL(t_3, Action::MACHINE_INFO);
  BOOST_CHECK_EQUAL(t_3.getIndex(), idx3);
  BOOST_CHECK_EQUAL(t_3.getName(), "MACHINE_INFO");
  BOOST_CHECK_EQUAL(t_3.getValue(), 99);
  BOOST_CHECK_EQUAL(t_3.getValue(), (int)(Action::VAL_OF_MACHINE_INFO));
  BOOST_CHECK_EQUAL(t_3.toString(), "Machine Info");
#endif // MACHINE

  Action t_4;
  int idx4 = getEnumOrigIndex(Action::INTERPOLATE);
  t_4.setToIndex(idx4);
  BOOST_CHECK_EQUAL(t_4.getId(), Action::INTERPOLATE);
  BOOST_CHECK_EQUAL(t_4, Action::INTERPOLATE);
  BOOST_CHECK_EQUAL(t_4.getIndex(), idx4);
  BOOST_CHECK_EQUAL(t_4.getName(), "INTERPOLATE");
  BOOST_CHECK_EQUAL(t_4.getValue(), 15);
  BOOST_CHECK_EQUAL(t_4.getValue(), (int)(Action::VAL_OF_INTERPOLATE));
  BOOST_CHECK_EQUAL(t_4.toString(), "Interpolate");

  Action t_5;
  int idx5 = getEnumOrigIndex(Action::HELP);
  t_5.setToIndex(idx5);
  BOOST_CHECK_EQUAL(t_5.getId(), Action::HELP);
  BOOST_CHECK_EQUAL(t_5, Action::HELP);
  BOOST_CHECK_EQUAL(t_5.getIndex(), idx5);
  BOOST_CHECK_EQUAL(t_5.getName(), "HELP");
  BOOST_CHECK_EQUAL(t_5.getValue(), 700);
  BOOST_CHECK_EQUAL(t_5.getValue(), (int)(Action::VAL_OF_HELP));
  BOOST_CHECK_EQUAL(t_5.toString(), "Help");

  Action t_6;
  int idx6 = getEnumOrigIndex(Action::UNKNOWN);
  t_6.setToIndex(idx6);
  BOOST_CHECK_EQUAL(t_6.getId(), Action::UNKNOWN);
  BOOST_CHECK_EQUAL(t_6, Action::UNKNOWN);
  BOOST_CHECK_EQUAL(t_6.getIndex(), idx6);
  BOOST_CHECK_EQUAL(t_6.getName(), "UNKNOWN");
  BOOST_CHECK_EQUAL(t_6.getValue(), 1000);
  BOOST_CHECK_EQUAL(t_6.getValue(), (int)(Action::VAL_OF_UNKNOWN));
  BOOST_CHECK_EQUAL(t_6.toString(), "Unknown");

  Action t_7;
  int idx7 = getEnumOrigIndex(Action::NA);
  t_7.setToIndex(idx7);
  BOOST_CHECK_EQUAL(t_7.getId(), Action::NA);
  BOOST_CHECK_EQUAL(t_7, Action::NA);
  BOOST_CHECK_EQUAL(t_7.getIndex(), idx7);
  BOOST_CHECK_EQUAL(t_7.getName(), "NA");
  BOOST_CHECK_EQUAL(t_7.getValue(), 900);
  BOOST_CHECK_EQUAL(t_7.getValue(), (int)(Action::VAL_OF_NA));
  BOOST_CHECK_EQUAL(t_7.toString(), "Not Applicable");

}  // BOOST_AUTO_TEST_CASE(test_action_from_set_index)


BOOST_AUTO_TEST_CASE(test_action_stream) {
  Action t_0;
  int idx0 = getEnumOrigIndex(Action::INVALID);
  t_0.setToIndex(idx0);
  BOOST_CHECK_EQUAL(t_0.getId(), Action::INVALID);
  BOOST_CHECK_EQUAL(t_0, Action::INVALID);
  BOOST_CHECK_EQUAL(t_0.getIndex(), idx0);
  BOOST_CHECK_EQUAL(t_0.getName(), "INVALID");
  BOOST_CHECK_EQUAL(t_0.getValue(), -1);
  BOOST_CHECK_EQUAL(t_0.getValue(), (int)(Action::VAL_OF_INVALID));
  BOOST_CHECK_EQUAL(t_0.toString(), "Invalid");
  {
    std::ostringstream oss;
    oss <<  t_0;
    BOOST_CHECK_EQUAL(oss.str(), "INVALID");

    Action enumFromStream;
    std::istringstream iss("INVALID");
    iss >> enumFromStream;
    BOOST_CHECK_EQUAL(enumFromStream, Action::INVALID);
  }

  Action t_1;
  int idx1 = getEnumOrigIndex(Action::VERSION);
  t_1.setToIndex(idx1);
  BOOST_CHECK_EQUAL(t_1.getId(), Action::VERSION);
  BOOST_CHECK_EQUAL(t_1, Action::VERSION);
  BOOST_CHECK_EQUAL(t_1.getIndex(), idx1);
  BOOST_CHECK_EQUAL(t_1.getName(), "VERSION");
  BOOST_CHECK_EQUAL(t_1.getValue(), 77);
  BOOST_CHECK_EQUAL(t_1.getValue(), (int)(Action::VAL_OF_VERSION));
  BOOST_CHECK_EQUAL(t_1.toString(), "Version");
  {
    std::ostringstream oss;
    oss <<  t_1;
    BOOST_CHECK_EQUAL(oss.str(), "VERSION");

    Action enumFromStream;
    std::istringstream iss("VERSION");
    iss >> enumFromStream;
    BOOST_CHECK_EQUAL(enumFromStream, Action::VERSION);
  }

  Action t_2;
  int idx2 = getEnumOrigIndex(Action::BENCHMARK);
  t_2.setToIndex(idx2);
  BOOST_CHECK_EQUAL(t_2.getId(), Action::BENCHMARK);
  BOOST_CHECK_EQUAL(t_2, Action::BENCHMARK);
  BOOST_CHECK_EQUAL(t_2.getIndex(), idx2);
  BOOST_CHECK_EQUAL(t_2.getName(), "BENCHMARK");
  BOOST_CHECK_EQUAL(t_2.getValue(), 88);
  BOOST_CHECK_EQUAL(t_2.getValue(), (int)(Action::VAL_OF_BENCHMARK));
  BOOST_CHECK_EQUAL(t_2.toString(), "Benchmark");
  {
    std::ostringstream oss;
    oss <<  t_2;
    BOOST_CHECK_EQUAL(oss.str(), "BENCHMARK");

    Action enumFromStream;
    std::istringstream iss("BENCHMARK");
    iss >> enumFromStream;
    BOOST_CHECK_EQUAL(enumFromStream, Action::BENCHMARK);
  }

#ifdef MACHINE
  Action t_3;
  int idx3 = getEnumOrigIndex(Action::MACHINE_INFO);
  t_3.setToIndex(idx3);
  BOOST_CHECK_EQUAL(t_3.getId(), Action::MACHINE_INFO);
  BOOST_CHECK_EQUAL(t_3, Action::MACHINE_INFO);
  BOOST_CHECK_EQUAL(t_3.getIndex(), idx3);
  BOOST_CHECK_EQUAL(t_3.getName(), "MACHINE_INFO");
  BOOST_CHECK_EQUAL(t_3.getValue(), 99);
  BOOST_CHECK_EQUAL(t_3.getValue(), (int)(Action::VAL_OF_MACHINE_INFO));
  BOOST_CHECK_EQUAL(t_3.toString(), "Machine Info");
  {
    std::ostringstream oss;
    oss <<  t_3;
    BOOST_CHECK_EQUAL(oss.str(), "MACHINE_INFO");

    Action enumFromStream;
    std::istringstream iss("MACHINE_INFO");
    iss >> enumFromStream;
    BOOST_CHECK_EQUAL(enumFromStream, Action::MACHINE_INFO);
  }
#endif // MACHINE

  Action t_4;
  int idx4 = getEnumOrigIndex(Action::INTERPOLATE);
  t_4.setToIndex(idx4);
  BOOST_CHECK_EQUAL(t_4.getId(), Action::INTERPOLATE);
  BOOST_CHECK_EQUAL(t_4, Action::INTERPOLATE);
  BOOST_CHECK_EQUAL(t_4.getIndex(), idx4);
  BOOST_CHECK_EQUAL(t_4.getName(), "INTERPOLATE");
  BOOST_CHECK_EQUAL(t_4.getValue(), 15);
  BOOST_CHECK_EQUAL(t_4.getValue(), (int)(Action::VAL_OF_INTERPOLATE));
  BOOST_CHECK_EQUAL(t_4.toString(), "Interpolate");
  {
    std::ostringstream oss;
    oss <<  t_4;
    BOOST_CHECK_EQUAL(oss.str(), "INTERPOLATE");

    Action enumFromStream;
    std::istringstream iss("INTERPOLATE");
    iss >> enumFromStream;
    BOOST_CHECK_EQUAL(enumFromStream, Action::INTERPOLATE);
  }

  Action t_5;
  int idx5 = getEnumOrigIndex(Action::HELP);
  t_5.setToIndex(idx5);
  BOOST_CHECK_EQUAL(t_5.getId(), Action::HELP);
  BOOST_CHECK_EQUAL(t_5, Action::HELP);
  BOOST_CHECK_EQUAL(t_5.getIndex(), idx5);
  BOOST_CHECK_EQUAL(t_5.getName(), "HELP");
  BOOST_CHECK_EQUAL(t_5.getValue(), 700);
  BOOST_CHECK_EQUAL(t_5.getValue(), (int)(Action::VAL_OF_HELP));
  BOOST_CHECK_EQUAL(t_5.toString(), "Help");
  {
    std::ostringstream oss;
    oss <<  t_5;
    BOOST_CHECK_EQUAL(oss.str(), "HELP");

    Action enumFromStream;
    std::istringstream iss("HELP");
    iss >> enumFromStream;
    BOOST_CHECK_EQUAL(enumFromStream, Action::HELP);
  }

  Action t_6;
  int idx6 = getEnumOrigIndex(Action::UNKNOWN);
  t_6.setToIndex(idx6);
  BOOST_CHECK_EQUAL(t_6.getId(), Action::UNKNOWN);
  BOOST_CHECK_EQUAL(t_6, Action::UNKNOWN);
  BOOST_CHECK_EQUAL(t_6.getIndex(), idx6);
  BOOST_CHECK_EQUAL(t_6.getName(), "UNKNOWN");
  BOOST_CHECK_EQUAL(t_6.getValue(), 1000);
  BOOST_CHECK_EQUAL(t_6.getValue(), (int)(Action::VAL_OF_UNKNOWN));
  BOOST_CHECK_EQUAL(t_6.toString(), "Unknown");
  {
    std::ostringstream oss;
    oss <<  t_6;
    BOOST_CHECK_EQUAL(oss.str(), "UNKNOWN");

    Action enumFromStream;
    std::istringstream iss("UNKNOWN");
    iss >> enumFromStream;
    BOOST_CHECK_EQUAL(enumFromStream, Action::UNKNOWN);
  }

  Action t_7;
  int idx7 = getEnumOrigIndex(Action::NA);
  t_7.setToIndex(idx7);
  BOOST_CHECK_EQUAL(t_7.getId(), Action::NA);
  BOOST_CHECK_EQUAL(t_7, Action::NA);
  BOOST_CHECK_EQUAL(t_7.getIndex(), idx7);
  BOOST_CHECK_EQUAL(t_7.getName(), "NA");
  BOOST_CHECK_EQUAL(t_7.getValue(), 900);
  BOOST_CHECK_EQUAL(t_7.getValue(), (int)(Action::VAL_OF_NA));
  BOOST_CHECK_EQUAL(t_7.toString(), "Not Applicable");
  {
    std::ostringstream oss;
    oss <<  t_7;
    BOOST_CHECK_EQUAL(oss.str(), "NA");

    Action enumFromStream;
    std::istringstream iss("NA");
    iss >> enumFromStream;
    BOOST_CHECK_EQUAL(enumFromStream, Action::NA);
  }

}  // BOOST_AUTO_TEST_CASE(test_action_stream)


bool init_unit_test() {
  return true;
}
