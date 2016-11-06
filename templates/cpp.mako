<%namespace name="shared" file="shared.mako"/>\
/**
 * @file ${name}.h
 * @brief Implementation of ${name} Enumeration class
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

// DO NOT EDIT CHANGES WILL OVERWITEN WHEN REGENERATED
// Generated from template "${self.filename}".

#include "${name}.h"

#include <iostream>
#include <string>
#include <cstring>
% if data_type == 'double' or data_type == 'float':
#include <limits>
% endif

% for namespace in namespaces:
namespace ${namespace} {
% endfor

namespace { // Local helper data and functions

/**
 * @brief Structure to map enum name to id
 */
struct entry {
  const char* name;
  int size;
  ${name}::Choice id;
};

// Enum string name to ID map sorted by name
entry const entries[${name}::NUM_ENUMS] = {
% for item in sorted(items, key=lambda x: x.idName):
<%shared:open_ifdef name="${item.open_ifdef}"/>\
  { "${(item.name.upper() + '",').ljust(maxIdSize + 2)} sizeof("${(item.name.upper() + '")-1,').ljust(maxIdSize + 5)} ${name}::${item.idName.ljust(maxIdSize)} },
<%shared:close_ifdef name="${item.close_ifdef}"/>\
% endfor
};


${name}::Choice const idByOrigOrder[${name}::NUM_ENUMS] = {
% for item in items:
<%shared:open_ifdef name="${item.open_ifdef}"/>\
  ${name}::${item.idName},
<%shared:close_ifdef name="${item.close_ifdef}"/>\
% endfor
};


/**
 * @brief Structure to map enum value to id
 */
struct Val2Id {
  ${value_type} value;
  ${name}::Choice id;
};

// Value to ID map, sorted by value
Val2Id const values[${name}::NUM_ENUMS] = {
 // ${'Value'.ljust(maxValSize)} Enum id
% for item in items:
% if item.value == 'NaN':
<%shared:open_ifdef name="${item.open_ifdef}"/>\
  { std::numeric_limits<${data_type}>::quiet_NaN(), ${name}::${item.name} }, // NaN is smaller than anything
<%shared:close_ifdef name="${item.close_ifdef}"/>\
% endif
% endfor
% for item in sorted(items, key=lambda x: x.value):
% if item.value != 'NaN':
<%shared:open_ifdef name="${item.open_ifdef}"/>\
  { ${(str(item.value) + ',').ljust(maxValSize+1)} ${name}::${item.idName.ljust(maxIdSize)} },
<%shared:close_ifdef name="${item.close_ifdef}"/>\
% endif
% endfor
};

% if data_type == 'double':
inline absval(double val) { return val < 0 ? -val:val; }

int compare(double a, double b) {
  if (a == b) return 0;
  if (a != a) {
    if (b != b) return 0;
    else return -1;
  } else if (b != b) return 1;
  double aa = absval(a);
  double bb = absval(b);
  double scaled_epsilon = ( (aa > bb ? bb : aa) * std::numeric_limits<double>::epsilon());
  if (absval(a-b) < scaled_epsilon) return 0;
  if ((a-b) > scaled_epsilon) return -1;
  return 1;
}
% endif

inline int compare(const char* a, const char* b) { return ::strcmp(a,b); }

template <typename T>
inline int compare(T a, T b) { if (a<b) return -1; else return (a==b)?0:1; }

} // anonymous namespace

% if data_type != 'int':
% for item in items:
<%shared:open_ifdef name="${item.open_ifdef}"/>\
${value_type} ${name}::${item.valName.ljust(maxValIdSize)} = ${
    (str(item.value) + ';').ljust(maxValSize+1)} /**< ${item.documentation} */
<%shared:close_ifdef name="${item.close_ifdef}"/>\
% endfor
% endif

% for item in items:
<%shared:open_ifdef name="${item.open_ifdef}"/>\
const char* ${name}::${('NAME_OF_' + item.name.upper()).ljust(maxIdSize+8)} = "${item.name.upper()}";
<%shared:close_ifdef name="${item.close_ifdef}"/>\
% endfor


// get name for current enum value
char const* ${name}::getName() const {
  switch (val_) {
% for item in items:
<%shared:open_ifdef name="${item.open_ifdef}"/>\
    case ${(item.idName + ':').ljust(maxIdSize+1)} return "${item.name}";
<%shared:close_ifdef name="${item.close_ifdef}"/>\
% endfor
    defau${'lt:'.ljust(maxIdSize+1)} return "${invalid.name}";
  }
}

// Get display string for current enum value
char const* ${name}::toString() const {
  switch (val_) {
% for item in items:
<%shared:open_ifdef name="${item.open_ifdef}"/>\
    case ${(item.idName + ':').ljust(maxIdSize+1)} return "${item.display}";
<%shared:close_ifdef name="${item.close_ifdef}"/>\
% endfor
    defau${'lt:'.ljust(maxIdSize+1)} return "${invalid.display}";
  }
}

// Get value corresponding to given enum value
${value_type} ${name}::getValue() const {
  switch (val_) {
% for item in items:
<%shared:open_ifdef name="${item.open_ifdef}"/>\
% if item.value == 'NaN':
    case ${(item.idName + ':').ljust(maxIdSize+1)} return std::numeric_limits<${data_type}>::quiet_NaN();
% else:
    case ${(item.idName + ':').ljust(maxIdSize+1)} return ${item.value};
% endif
<%shared:close_ifdef name="${item.close_ifdef}"/>\
% endfor
% if data_type == 'double' or data_type == 'float':
    defau${'lt:'.ljust(maxIdSize+1)} return std::numeric_limits<${data_type}>::quiet_NaN();
% else:
    defau${'lt:'.ljust(maxIdSize+1)} return ${invalid.value};
% endif
  }
}

// Given value find enum id for it
${name}& ${name}::setToValue(${value_type} val) {
% if data_type=='int' or data_type=='short':
  switch (val) {
% for item in items:
<%shared:open_ifdef name="${item.open_ifdef}"/>\
    case ${(str(item.value) + ':').ljust(maxValSize+1)} val_ = ${(item.idName + ';').ljust(maxIdSize+1)} return *this;
<%shared:close_ifdef name="${item.close_ifdef}"/>\
% endfor
  }
% else:
  // Perform binary search for value
  int start = 0;
  int end = ${name}::NUM_ENUMS-1; // Index of last valid entry
  do {
    int mid = (end + start) >> 1;
    Val2Id const& e = values[mid];
    int cmp = compare(val,e.value);
    if (cmp < 0) { // val < e.value
      end = mid-1;
    } else if (cmp > 0) { // val > e.value
      start = mid+1;
    } else {
      val_ = e.id;
      return *this;
    }
  } while (start <= end);
% endif
  val_ = ${invalid.idName};
  return *this;
}


${name}& ${name}::fromName(char const* str) {
  // Perform binary search for string
  int start = 0;
  int end = ${name}::NUM_ENUMS-1;  // Index of last valid entry
  do {
    int mid = (end + start) >> 1;
    entry const& e = entries[mid];
    int cmp = ::strcmp(str,e.name);
    if (cmp < 0) {
      end = mid-1;
    } else if (cmp > 0) {
      start = mid+1;
    } else {
      val_ = e.id; // found it
      return *this;
    }
  } while (start <= end);
  val_ = ${invalid.idName};
  return *this;
}

${name}& ${name}::fromName(char const* str, int len) {
  // Perform binary search for string
  int start = 0;
  int end = ${name}::NUM_ENUMS-1; // Index of last valid entry
  do {
    int mid = (end + start) >> 1;
    entry const& e = entries[mid];
    int cmp = ::strncmp(str,e.name,std::max(e.size,len));
    if (cmp < 0) {
      end = mid-1;
    } else if (cmp > 0) {
      start = mid+1;
    } else {
      val_ = e.id; // found it
      return *this;
    }
  } while (start <= end);
  val_ = ${invalid.idName};
  return *this;
}

${name}& ${name}::setToIndex(int idx) {
  if (idx < 0 || idx >= ${name}::NUM_ENUMS) { // Index out of bounds?
    val_ = ${invalid.idName};
  } else {
    val_ = idByOrigOrder[idx];
  }
  return *this;
}

int ${name}::getIndex() const {
  switch (val_) {
% for i, item in enumerate(items):
<%shared:open_ifdef name="${item.open_ifdef}"/>\
    case ${(item.idName + ':').ljust(maxIdSize+1)} return 0
% for j, itemj in enumerate(items):
% if j < i:
<%shared:open_ifdef name="${itemj.open_ifdef}"/>\
        + 1
<%shared:close_ifdef name="${itemj.close_ifdef}"/>\
% endif
% endfor
;
<%shared:close_ifdef name="${item.close_ifdef}"/>\
% endfor
    default: // Should not happen
      // ASSERT
      break;
  }
  return -1;
}

std::ostream& operator<<(std::ostream& os, ${name} const& enm) {
  os << enm.getName();
  return os;
}

std::ostream& operator<<(std::ostream& os, ${name}::Choice const& enm) {
  os << ${name}(enm);
  return os;
}

std::istream& operator>>(std::istream& is, ${name}& enm) {
  std::string val;
  is >> val;
  enm.fromName(val.c_str(),val.size());
  return is;
}



% for namespace in reversed(namespaces):
} // namespace ${namespace}
% endfor
