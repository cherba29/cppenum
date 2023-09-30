/**
 * @file Action.h
 * @brief Implementation of Action Enumeration class
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

// DO NOT EDIT CHANGES WILL OVERWITEN WHEN REGENERATED
// Generated from config "tests/testdata/action/action.yaml".

#include "Action.h"

#include <iostream>
#include <string>
#include <cstring>

namespace runprofile {

namespace { // Local helper data and functions

/**
 * @brief Structure to map enum name to id
 */
struct entry {
  const char* name;
  int size;
  Action::Choice id;
};

// Enum string name to ID map sorted by name
entry const entries[Action::NUM_ENUMS] = {
  { "BENCHMARK",    sizeof("BENCHMARK")-1,    Action::BENCHMARK    },
  { "HELP",         sizeof("HELP")-1,         Action::HELP         },
  { "INTERPOLATE",  sizeof("INTERPOLATE")-1,  Action::INTERPOLATE  },
  { "INVALID",      sizeof("INVALID")-1,      Action::INVALID      },
#ifdef MACHINE
  { "MACHINE_INFO", sizeof("MACHINE_INFO")-1, Action::MACHINE_INFO },
#endif // MACHINE
  { "NA",           sizeof("NA")-1,           Action::NA           },
  { "UNKNOWN",      sizeof("UNKNOWN")-1,      Action::UNKNOWN      },
  { "VERSION",      sizeof("VERSION")-1,      Action::VERSION      },
};


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


/**
 * @brief Structure to map enum value to id
 */
struct Val2Id {
  int value;
  Action::Choice id;
};

// Value to ID map, sorted by value
Val2Id const values[Action::NUM_ENUMS] = {
 // Value Enum id
  { -1,   Action::INVALID      },
  { 15,   Action::INTERPOLATE  },
  { 77,   Action::VERSION      },
  { 88,   Action::BENCHMARK    },
#ifdef MACHINE
  { 99,   Action::MACHINE_INFO },
#endif // MACHINE
  { 700,  Action::HELP         },
  { 900,  Action::NA           },
  { 1000, Action::UNKNOWN      },
};


inline int compare(const char* a, const char* b) { return ::strcmp(a,b); }

template <typename T>
inline int compare(T a, T b) { if (a<b) return -1; else return (a==b)?0:1; }

} // anonymous namespace


const char* Action::NAME_OF_INVALID      = "INVALID";
const char* Action::NAME_OF_VERSION      = "VERSION";
const char* Action::NAME_OF_BENCHMARK    = "BENCHMARK";
#ifdef MACHINE
const char* Action::NAME_OF_MACHINE_INFO = "MACHINE_INFO";
#endif // MACHINE
const char* Action::NAME_OF_INTERPOLATE  = "INTERPOLATE";
const char* Action::NAME_OF_HELP         = "HELP";
const char* Action::NAME_OF_UNKNOWN      = "UNKNOWN";
const char* Action::NAME_OF_NA           = "NA";


// get name for current enum value
char const* Action::getName() const {
  switch (val_) {
    case INVALID:      return "INVALID";
    case VERSION:      return "VERSION";
    case BENCHMARK:    return "BENCHMARK";
#ifdef MACHINE
    case MACHINE_INFO: return "MACHINE_INFO";
#endif // MACHINE
    case INTERPOLATE:  return "INTERPOLATE";
    case HELP:         return "HELP";
    case UNKNOWN:      return "UNKNOWN";
    case NA:           return "NA";
    default:           return "INVALID";
  }
}

// Get display string for current enum value
char const* Action::toString() const {
  switch (val_) {
    case INVALID:      return "Invalid";
    case VERSION:      return "Version";
    case BENCHMARK:    return "Benchmark";
#ifdef MACHINE
    case MACHINE_INFO: return "Machine Info";
#endif // MACHINE
    case INTERPOLATE:  return "Interpolate";
    case HELP:         return "Help";
    case UNKNOWN:      return "Unknown";
    case NA:           return "Not Applicable";
    default:           return "Invalid";
  }
}

// Get value corresponding to given enum value
int Action::getValue() const {
  switch (val_) {
    case INVALID:      return -1;
    case VERSION:      return 77;
    case BENCHMARK:    return 88;
#ifdef MACHINE
    case MACHINE_INFO: return 99;
#endif // MACHINE
    case INTERPOLATE:  return 15;
    case HELP:         return 700;
    case UNKNOWN:      return 1000;
    case NA:           return 900;
    default:           return -1;
  }
}

// Given value find enum id for it
Action& Action::setToValue(int val) {
  switch (val) {
    case -1:   val_ = INVALID;      return *this;
    case 77:   val_ = VERSION;      return *this;
    case 88:   val_ = BENCHMARK;    return *this;
#ifdef MACHINE
    case 99:   val_ = MACHINE_INFO; return *this;
#endif // MACHINE
    case 15:   val_ = INTERPOLATE;  return *this;
    case 700:  val_ = HELP;         return *this;
    case 1000: val_ = UNKNOWN;      return *this;
    case 900:  val_ = NA;           return *this;
  }
  val_ = INVALID;
  return *this;
}


Action& Action::fromName(char const* str) {
  // Perform binary search for string
  int start = 0;
  int end = Action::NUM_ENUMS-1;  // Index of last valid entry
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
  val_ = INVALID;
  return *this;
}

Action& Action::fromName(char const* str, int len) {
  // Perform binary search for string
  int start = 0;
  int end = Action::NUM_ENUMS-1; // Index of last valid entry
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
  val_ = INVALID;
  return *this;
}

Action& Action::setToIndex(int idx) {
  if (idx < 0 || idx >= Action::NUM_ENUMS) { // Index out of bounds?
    val_ = INVALID;
  } else {
    val_ = idByOrigOrder[idx];
  }
  return *this;
}

int Action::getIndex() const {
  switch (val_) {
    case INVALID:      return 0
;
    case VERSION:      return 0
        + 1
;
    case BENCHMARK:    return 0
        + 1
        + 1
;
#ifdef MACHINE
    case MACHINE_INFO: return 0
        + 1
        + 1
        + 1
;
#endif // MACHINE
    case INTERPOLATE:  return 0
        + 1
        + 1
        + 1
#ifdef MACHINE
        + 1
#endif // MACHINE
;
    case HELP:         return 0
        + 1
        + 1
        + 1
#ifdef MACHINE
        + 1
#endif // MACHINE
        + 1
;
    case UNKNOWN:      return 0
        + 1
        + 1
        + 1
#ifdef MACHINE
        + 1
#endif // MACHINE
        + 1
        + 1
;
    case NA:           return 0
        + 1
        + 1
        + 1
#ifdef MACHINE
        + 1
#endif // MACHINE
        + 1
        + 1
        + 1
;
    default: // Should not happen
      // ASSERT
      break;
  }
  return -1;
}

std::ostream& operator<<(std::ostream& os, Action const& enm) {
  os << enm.getName();
  return os;
}

std::ostream& operator<<(std::ostream& os, Action::Choice const& enm) {
  os << Action(enm);
  return os;
}

std::istream& operator>>(std::istream& is, Action& enm) {
  std::string val;
  is >> val;
  enm.fromName(val.c_str(),val.size());
  return is;
}



} // namespace runprofile
