#ifndef INCLUDED_RUNPROFILE_ACTION
#define INCLUDED_RUNPROFILE_ACTION

// DO NOT EDIT CHANGES WILL OVERWITEN WHEN REGENERATED
// Generated from config "tests/testdata/action/action.yaml".

/**
 * @file Action.h
 * @brief Declaration of Action enumeration class
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

#include <iosfwd>

namespace runprofile {

/**
 * @brief Class abstraction of Action enumeration.
 * @code
 * Action enm;
 *
 * std::cout << "Default Value: " << enm << std::endl;
 * switch (enm.getId()) {
 *   case Action::INVALID:
 *     std::cout << "Got Id: " << enm.getId() << " display: " << enm.toString()
 *               << " value: " << enm.toValue() << std::endl;
 *     break;
 *   case Action::VERSION:
 *     std::cout << "Got Id: " << enm.getId() << " display: " << enm.toString()
 *               << " value: " << enm.toValue() << std::endl;
 *     break;
 *   case Action::BENCHMARK:
 *     std::cout << "Got Id: " << enm.getId() << " display: " << enm.toString()
 *               << " value: " << enm.toValue() << std::endl;
 *     break;
#ifdef MACHINE
 *   case Action::MACHINE_INFO:
 *     std::cout << "Got Id: " << enm.getId() << " display: " << enm.toString()
 *               << " value: " << enm.toValue() << std::endl;
 *     break;
#endif // MACHINE
 *   case Action::INTERPOLATE:
 *     std::cout << "Got Id: " << enm.getId() << " display: " << enm.toString()
 *               << " value: " << enm.toValue() << std::endl;
 *     break;
 *   case Action::HELP:
 *     std::cout << "Got Id: " << enm.getId() << " display: " << enm.toString()
 *               << " value: " << enm.toValue() << std::endl;
 *     break;
 *   case Action::UNKNOWN:
 *     std::cout << "Got Id: " << enm.getId() << " display: " << enm.toString()
 *               << " value: " << enm.toValue() << std::endl;
 *     break;
 *   case Action::NA:
 *     std::cout << "Got Id: " << enm.getId() << " display: " << enm.toString()
 *               << " value: " << enm.toValue() << std::endl;
 *     break;
 * }
 * @endcode
 */

class Action {
  typedef void (Action::*bool_type)() const;  // private boolean type as ptr to mem fun
public:
  typedef int value_type;

  enum Choice {
     INVALID      = -1 /**< Additional value, set to when object cannot be initialized */
   , VERSION      = 1 /**< Show version */
   , BENCHMARK    = 2 /**< Run benchmarks */
#ifdef MACHINE
   , MACHINE_INFO = 3 /**< Produce machine information */
#endif // MACHINE
   , INTERPOLATE  = 4 /**< Run interpolation */
   , HELP         = 5 /**< Show help */
   , UNKNOWN      = 6 /**< Default non-selection option */
   , NA           = 7 /**< Non applicable option */
  };
  static const int NUM_ENUMS =
      7
#ifdef MACHINE
    + 1
#endif // MACHINE
  ;
  static const int VAL_OF_INVALID      = -1; /**< Additional value, set to when object cannot be initialized, value -1 */
  static const int VAL_OF_VERSION      = 77; /**< Show version, value 77 */
  static const int VAL_OF_BENCHMARK    = 88; /**< Run benchmarks, value 88 */
#ifdef MACHINE
  static const int VAL_OF_MACHINE_INFO = 99; /**< Produce machine information, value 99 */
#endif // MACHINE
  static const int VAL_OF_INTERPOLATE  = 15; /**< Run interpolation, value 15 */
  static const int VAL_OF_HELP         = 700; /**< Show help, value 700 */
  static const int VAL_OF_UNKNOWN      = 1000; /**< Default non-selection option, value 1000 */
  static const int VAL_OF_NA           = 900; /**< Non applicable option, value 900 */

  static const char* NAME_OF_INVALID;      /**< value INVALID */
  static const char* NAME_OF_VERSION;      /**< value VERSION */
  static const char* NAME_OF_BENCHMARK;    /**< value BENCHMARK */
#ifdef MACHINE
  static const char* NAME_OF_MACHINE_INFO; /**< value MACHINE_INFO */
#endif // MACHINE
  static const char* NAME_OF_INTERPOLATE;  /**< value INTERPOLATE */
  static const char* NAME_OF_HELP;         /**< value HELP */
  static const char* NAME_OF_UNKNOWN;      /**< value UNKNOWN */
  static const char* NAME_OF_NA;           /**< value NA */


  /**
   * @brief Initialize Enumerator to default value
   */
  Action() : val_(UNKNOWN) {}

  /**
   * @brief Initialize Enumeration with given enum
   */
  Action(Choice val) : val_(val) {}

  /**
   * @brief Initialize enumeration with given string.
   * If the parameter does not map to valid enumeration, one of
   *   "INVALID" "VERSION" "BENCHMARK" "MACHINE_INFO" "INTERPOLATE" "HELP" "UNKNOWN" "NA"
   * then the object is set to INVALID.
   * @see fromString
   */
  explicit Action(char const* name) { fromName(name); }

  /**
   * @brief Initialize enumeration with given string of specified length.
   * If the parameter does not map to valid enumeration, one of
   *   "INVALID" "VERSION" "BENCHMARK" "MACHINE_INFO" "INTERPOLATE" "HELP" "UNKNOWN" "NA"
   * then the object is set to INVALID.
   * @see fromString
   */
  Action(char const* name, int len) { fromName(name, len); }

  /**
   * @brief Initialize enumeration by index. Note this is not the ID/enum value.
   * Valid index values are in 0..NUM_ENUMS-1 range. If index outside this range
   * object is initialized to INVALID. In particular Action enum(-1); is
   * guaranteed to create enum object in invalid state.
   * @see getIndex, setToIndex
   */
  explicit Action(int index) { setToIndex(index); }

  /**
   * @brief Reset this object to default value
   */
  Action& reset() { val_ = UNKNOWN; return *this; }

  /**
   * @brief Set this object to invalid value
   */
  Action& invalidate() { val_ = INVALID; return *this; }

  /**
   * @brief return id of current enumeration value.
   */
  Choice getId() const { return val_; }

  /**
   * @brief Set value to one of the posiible enums
   */
  Action& setId(Choice c) { val_ = c; return *this; }

  /**
   * @brief return index of current enumeration value.
   */
  int getIndex() const;

  /**
   * @brief Set index of current enum value.
   * Valid index values are in 0..NUM_ENUMS-1 range. If index outside this range
   * object is initialized to INVALID
   */
  Action& setToIndex(int idx);

  /**
   * @brief return string representation of current enumeration value.
   */
  char const* getName() const;

  /**
   * @brief return display string of current enumeration value.
   */
  char const* toString() const;

  /**
   * @brief Set enumeration with given string. If
   * the parameter does not map to valid enumeration name, one of
   *   "INVALID" "VERSION" "BENCHMARK" "MACHINE_INFO" "INTERPOLATE" "HELP" "UNKNOWN" "NA"
   * then the object is set to INVALID.
   */
  Action& fromName(char const* str);
  Action& fromName(char const* str, int len);

  /**
   * @brief return int value representation of current enumeration.
   */
  int getValue() const;

  /**
   * @brief set enumeration to the int value which corresponds to given value.
   * Valid enumerated values are:
   *   "-1" "77" "88" "99" "15" "700" "1000" "900"
   * If no such enumerated value exist this object will be set to INVALID.
   */
  Action& setToValue(int val);

  /**
   * @brief Return true if this enum is set to some valid value.
   */
   operator bool_type() const { return val_ == INVALID?0:&Action::this_type_does_not_support_comparisons; }


private:
  void this_type_does_not_support_comparisons() const {}
  Choice val_;
}; // class Action

/**
 * @brief Equal if and only if enumeration ids are same
 */
inline bool operator==(Action lhs, Action rhs) { return lhs.getId() == rhs.getId(); }
inline bool operator==(Action lhs, Action::Choice rhs) { return lhs.getId() == rhs; }
inline bool operator==(Action::Choice lhs, Action rhs) { return lhs == rhs.getId(); }

/**
 * @brief Not equal if and only if enumeration ids are not same
 */
inline bool operator!=(Action lhs, Action rhs) { return lhs.getId() != rhs.getId(); }
inline bool operator!=(Action lhs, Action::Choice rhs) { return lhs.getId() != rhs; }
inline bool operator!=(Action::Choice lhs, Action rhs) { return lhs != rhs.getId(); }

inline bool operator<(Action lhs, Action rhs) { return lhs.getId() < rhs.getId(); }
inline bool operator>(Action lhs, Action rhs) { return lhs.getId() > rhs.getId(); }
inline bool operator<=(Action lhs, Action rhs) { return lhs.getId() <= rhs.getId(); }
inline bool operator>=(Action lhs, Action rhs) { return lhs.getId() >= rhs.getId(); }

/**
 * @brief Format the specified enum object value to the specified output stream and
 * return a reference to the passed in stream
 */
std::ostream& operator<<(std::ostream& os, Action const& enm);

/**
 * @brief Format the specified C enum value to the specified output stream and
 * return a reference to the passed in stream
 */
std::ostream& operator<<(std::ostream& os, Action::Choice const& enm);

/**
 * @brief Read a string from given stream and set object similar to
 * Action::fromString.
 */
std::istream& operator>>(std::istream& is, Action& enm);



} // close namespace runprofile


#endif // INCLUDED_RUNPROFILE_ACTION

