<%namespace name="shared" file="shared.mako"/>\
#ifndef INCLUDED_${'_'.join(namespaces).upper()}${'_' if namespaces else ''}${name.upper()}
#define INCLUDED_${'_'.join(namespaces).upper()}${'_' if namespaces else ''}${name.upper()}

// DO NOT EDIT CHANGES WILL OVERWITEN WHEN REGENERATED
// Generated from config "${config_file_path}".

/**
 * @file ${name}.h
 * @brief Declaration of ${name} enumeration class
 *
 * Copyright (C) ${year}  ${author}
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
% if data_type == 'string':
#include <string>
% endif

% for namespace in namespaces:
namespace ${namespace} {
% endfor

/**
 * @brief Class abstraction of ${name} enumeration.
 * @code
 * ${name} enm;
 *
 * std::cout << "Default Value: " << enm << std::endl;
 * switch (enm.getId()) {
% for item in items:
<%shared:open_ifdef name="${item.open_ifdef}"/>\
 *   case ${name}::${item.idName}:
 *     std::cout << "Got Id: " << enm.getId() << " display: " << enm.toString()
 *               << " value: " << enm.toValue() << std::endl;
 *     break;
<%shared:close_ifdef name="${item.close_ifdef}"/>\
% endfor
 * }
 * @endcode
 */

class ${name} {
  typedef void (${name}::*bool_type)() const;  // private boolean type as ptr to mem fun
public:
  typedef ${value_type} value_type;

  enum Choice {
% for i, item in enumerate(items):
<%shared:open_ifdef name="${item.open_ifdef}"/>\
   ${',' if i > 0 else ' '} ${item.idName.ljust(maxIdSize)} = ${item.id} /**< ${item.documentation} */
<%shared:close_ifdef name="${item.close_ifdef}"/>\
% endfor
  };
  static const int NUM_ENUMS =
% for idx, (ifdef, count) in enumerate(ifdefs):
% if ifdef:
#ifdef ${ifdef}
% endif
    ${'+' if idx > 0 else ' '} ${count}
% if ifdef:
#endif // ${ifdef}
% endif
% endfor
  ;
% if data_type == 'int':
% for item in items:
<%shared:open_ifdef name="${item.open_ifdef}"/>\
  static const ${value_type} ${item.valName.ljust(maxValIdSize)} = ${item.value}; /**< ${item.documentation}, value ${item.value} */
<%shared:close_ifdef name="${item.close_ifdef}"/>\
% endfor
% else:
% for item in items:
<%shared:open_ifdef name="${item.open_ifdef}"/>\
  static ${value_type} ${(item.valName + ';').ljust(maxValIdSize + 1)} /**< ${item.documentation}, value ${item.value} */
<%shared:close_ifdef name="${item.close_ifdef}"/>\
% endfor
%endif

% for item in items:
<%shared:open_ifdef name="${item.open_ifdef}"/>\
  static const char* ${('NAME_OF_' + item.name + ';').upper().ljust(maxIdSize + 9)} /**< value ${item.name.upper()} */
<%shared:close_ifdef name="${item.close_ifdef}"/>\
% endfor


  /**
   * @brief Initialize Enumerator to default value
   */
  ${name}() : val_(${default.idName}) {}

  /**
   * @brief Initialize Enumeration with given enum
   */
  ${name}(Choice val) : val_(val) {}

  /**
   * @brief Initialize enumeration with given string.
   * If the parameter does not map to valid enumeration, one of
   *   "${'" "'.join([item.name.upper() for item in items])}"
   * then the object is set to INVALID.
   * @see fromString
   */
  explicit ${name}(char const* name) { fromName(name); }

  /**
   * @brief Initialize enumeration with given string of specified length.
   * If the parameter does not map to valid enumeration, one of
   *   "${'" "'.join([item.name.upper() for item in items])}"
   * then the object is set to INVALID.
   * @see fromString
   */
  ${name}(char const* name, int len) { fromName(name, len); }

  /**
   * @brief Initialize enumeration by index. Note this is not the ID/enum value.
   * Valid index values are in 0..NUM_ENUMS-1 range. If index outside this range
   * object is initialized to INVALID. In particular ${name} enum(-1); is
   * guaranteed to create enum object in invalid state.
   * @see getIndex, setToIndex
   */
  explicit ${name}(int index) { setToIndex(index); }

  /**
   * @brief Reset this object to default value
   */
  ${name}& reset() { val_ = ${default.idName}; return *this; }

  /**
   * @brief Set this object to invalid value
   */
  ${name}& invalidate() { val_ = ${invalid.idName}; return *this; }

  /**
   * @brief return id of current enumeration value.
   */
  Choice getId() const { return val_; }

  /**
   * @brief Set value to one of the posiible enums
   */
  ${name}& setId(Choice c) { val_ = c; return *this; }

  /**
   * @brief return index of current enumeration value.
   */
  int getIndex() const;

  /**
   * @brief Set index of current enum value.
   * Valid index values are in 0..NUM_ENUMS-1 range. If index outside this range
   * object is initialized to INVALID
   */
  ${name}& setToIndex(int idx);

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
   *   "${'" "'.join([item.name.upper() for item in items])}"
   * then the object is set to INVALID.
   */
  ${name}& fromName(char const* str);
  ${name}& fromName(char const* str, int len);

  /**
   * @brief return ${data_type} value representation of current enumeration.
   */
  ${value_type} getValue() const;

  /**
   * @brief set enumeration to the ${data_type} value which corresponds to given value.
   * Valid enumerated values are:
   *   "${'" "'.join([str(item.value) if item.value is not None else '*?*' for item in items])}"
   * If no such enumerated value exist this object will be set to INVALID.
   */
  ${name}& setToValue(${value_type} val);

  /**
   * @brief Return true if this enum is set to some valid value.
   */
   operator bool_type() const { return val_ == ${invalid.idName}?0:&${name}::this_type_does_not_support_comparisons; }


private:
  void this_type_does_not_support_comparisons() const {}
  Choice val_;
}; // class ${name}

/**
 * @brief Equal if and only if enumeration ids are same
 */
inline bool operator==(${name} lhs, ${name} rhs) { return lhs.getId() == rhs.getId(); }
inline bool operator==(${name} lhs, ${name}::Choice rhs) { return lhs.getId() == rhs; }
inline bool operator==(${name}::Choice lhs, ${name} rhs) { return lhs == rhs.getId(); }

/**
 * @brief Not equal if and only if enumeration ids are not same
 */
inline bool operator!=(${name} lhs, ${name} rhs) { return lhs.getId() != rhs.getId(); }
inline bool operator!=(${name} lhs, ${name}::Choice rhs) { return lhs.getId() != rhs; }
inline bool operator!=(${name}::Choice lhs, ${name} rhs) { return lhs != rhs.getId(); }

inline bool operator<(${name} lhs, ${name} rhs) { return lhs.getId() < rhs.getId(); }
inline bool operator>(${name} lhs, ${name} rhs) { return lhs.getId() > rhs.getId(); }
inline bool operator<=(${name} lhs, ${name} rhs) { return lhs.getId() <= rhs.getId(); }
inline bool operator>=(${name} lhs, ${name} rhs) { return lhs.getId() >= rhs.getId(); }

/**
 * @brief Format the specified enum object value to the specified output stream and
 * return a reference to the passed in stream
 */
std::ostream& operator<<(std::ostream& os, ${name} const& enm);

/**
 * @brief Format the specified C enum value to the specified output stream and
 * return a reference to the passed in stream
 */
std::ostream& operator<<(std::ostream& os, ${name}::Choice const& enm);

/**
 * @brief Read a string from given stream and set object similar to
 * ${name}::fromString.
 */
std::istream& operator>>(std::istream& is, ${name}& enm);



% for namespace in reversed(namespaces):
} // close namespace ${namespace}
% endfor


#endif // INCLUDED_${'_'.join(namespaces).upper()}${'_' if namespaces else ''}${name.upper()}

