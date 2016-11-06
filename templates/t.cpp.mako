<%namespace name="shared" file="shared.mako"/>\
// DO NOT EDIT CHANGES WILL OVERWITEN WHEN REGENERATED
// Generated from template "${self.filename}".

/**
 * @file ${name}.t.cpp
 * @brief Test for ${name} enumeration
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

#include "${name}.h"

#include <boost/test/unit_test.hpp>

% if namespaces:
using namespace ::${'::'.join(namespaces)};
% endif

namespace {

${name}::Choice const idByOrigOrder[${name}::NUM_ENUMS] = {
% for item in items:
<%shared:open_ifdef name="${item.open_ifdef}"/>\
  ${name}::${item.idName},
<%shared:close_ifdef name="${item.close_ifdef}"/>\
% endfor
};

// Looks up enum index by original order.
int getEnumOrigIndex(${name}::Choice choice) {
  for (int i = 0; i < ${name}::NUM_ENUMS; ++i) {
    if (idByOrigOrder[i] == choice) {
      return i;
    }
  }
  return -1;
}

}  // namespace

BOOST_AUTO_TEST_CASE(test_${name.lower()}_default_reset) {

  // Create enum object with default value
  ${name} enumVal;
  BOOST_CHECK_EQUAL(enumVal.getId(), ${name}::${default.idName});

  // Test ==
  BOOST_CHECK_EQUAL(enumVal, ${name}::${default.idName});

  ${name} enum2;
  BOOST_CHECK_EQUAL(enumVal, enum2);

  BOOST_CHECK_EQUAL(${name}().reset(), ${name}::${default.idName});

% for i, item in enumerate(items):
<%shared:open_ifdef name="${item.open_ifdef}"/>\
  ${name} t_${i}(${i});
  BOOST_CHECK_EQUAL(t_${i}.reset(), ${name}::${default.idName});
<%shared:close_ifdef name="${item.close_ifdef}"/>\

% endfor
  int nDedault = 0;
  for (int i = 0; i <  ${name}::NUM_ENUMS-1; ++i) {
    if (${name}(i) == ${name}::${default.idName}) ++nDedault;
  }
  BOOST_CHECK_EQUAL(nDedault,1);

}

BOOST_AUTO_TEST_CASE(test_${name.lower()}_invalid) {
  ${name} enumVal(-1); // Guaranteed to set enum to invalid
  BOOST_CHECK(!enumVal);

  ${name} enumVal2(${name}::NUM_ENUMS); // Guaranteed to set enum to invalid
  BOOST_CHECK(!enumVal2);

  BOOST_CHECK_EQUAL(enumVal, ${name}::${invalid.idName});
  BOOST_CHECK_EQUAL(enumVal2, ${name}::${invalid.idName});
  BOOST_CHECK_EQUAL(${name}().invalidate(), ${name}::${invalid.idName});

  int nInvalid = 0;
  for (int i = 0; i <  ${name}::NUM_ENUMS-1; ++i) {
    if (${name}(i) == ${name}::${invalid.idName}) ++nInvalid;
  }
  BOOST_CHECK_EQUAL(nInvalid,1);
}

BOOST_AUTO_TEST_CASE(test_${name.lower()}_constructor_idx) {
% for i, item in enumerate(items):
<%shared:open_ifdef name="${item.open_ifdef}"/>\
  ${name} enum_${i}(${name}::${item.idName});
  int idx${i} = enum_${i}.getIndex();
  BOOST_CHECK_EQUAL(idx${i}, getEnumOrigIndex(${name}::${item.idName}));
  ${name} t_${i}(idx${i});
  BOOST_CHECK_EQUAL(t_${i}.getId(), ${name}::${item.idName});
  BOOST_CHECK_EQUAL(t_${i}, ${name}::${item.idName});
  BOOST_CHECK_EQUAL(t_${i}.getIndex(), idx${i});
  BOOST_CHECK_EQUAL(t_${i}.getName(), "${item.name}");
  BOOST_CHECK_EQUAL(t_${i}.getValue(), ${item.value});
  BOOST_CHECK_EQUAL(t_${i}.getValue(), ${name}::${item.valName});
  BOOST_CHECK_EQUAL(t_${i}.toString(), "${item.display}");
<%shared:close_ifdef name="${item.close_ifdef}"/>\

% endfor
}

BOOST_AUTO_TEST_CASE(test_${name.lower()}_constructor_name) {
% for i, item in enumerate(items):
<%shared:open_ifdef name="${item.open_ifdef}"/>\
  ${name} t_${i}("${item.name}");
  BOOST_CHECK_EQUAL(t_${i}.getId(), ${name}::${item.idName});
  BOOST_CHECK_EQUAL(t_${i}, ${name}::${item.idName});
  BOOST_CHECK_EQUAL(t_${i}.getIndex(), getEnumOrigIndex(${name}::${item.idName}));
  BOOST_CHECK_EQUAL(t_${i}.getName(), "${item.name}");
  BOOST_CHECK_EQUAL(t_${i}.getValue(), ${item.value});
  BOOST_CHECK_EQUAL(t_${i}.getValue(), ${name}::${item.valName});
  BOOST_CHECK_EQUAL(t_${i}.toString(), "${item.display}");
<%shared:close_ifdef name="${item.close_ifdef}"/>\

% endfor
}

BOOST_AUTO_TEST_CASE(test_${name.lower()}_constructor_name_len) {
% for i, item in enumerate(items):
<%shared:open_ifdef name="${item.open_ifdef}"/>\
  ${name} t_${i}("${item.name}", ${len(item.name)});
  BOOST_CHECK_EQUAL(t_${i}.getId(), ${name}::${item.idName});
  BOOST_CHECK_EQUAL(t_${i}, ${name}::${item.idName});
  BOOST_CHECK_EQUAL(t_${i}.getIndex(), getEnumOrigIndex(${name}::${item.idName}));
  BOOST_CHECK_EQUAL(t_${i}.getName(), "${item.name}");
  BOOST_CHECK_EQUAL(t_${i}.getValue(), ${item.value});
  BOOST_CHECK_EQUAL(t_${i}.getValue(), ${name}::${item.valName});
  BOOST_CHECK_EQUAL(t_${i}.toString(), "${item.display}");
<%shared:close_ifdef name="${item.close_ifdef}"/>\

% endfor
}


BOOST_AUTO_TEST_CASE(test_${name.lower()}_constructor_enum) {
% for i, item in enumerate(items):
<%shared:open_ifdef name="${item.open_ifdef}"/>\
  ${name} t_${i}(${name}::${item.idName});
  BOOST_CHECK_EQUAL(t_${i}.getId(), ${name}::${item.idName});
  BOOST_CHECK_EQUAL(t_${i}, ${name}::${item.idName});
  BOOST_CHECK_EQUAL(t_${i}.getIndex(), getEnumOrigIndex(${name}::${item.idName}));
  BOOST_CHECK_EQUAL(t_${i}.getName(), "${item.name}");
  BOOST_CHECK_EQUAL(t_${i}.getValue(), ${item.value});
  BOOST_CHECK_EQUAL(t_${i}.getValue(), ${name}::${item.valName});
  BOOST_CHECK_EQUAL(t_${i}.toString(), "${item.display}");
<%shared:close_ifdef name="${item.close_ifdef}"/>\

% endfor
}

BOOST_AUTO_TEST_CASE( test_${name.lower()}_from_value ) {
% for i, item in enumerate(items):
<%shared:open_ifdef name="${item.open_ifdef}"/>\
  ${name} t_${i};
  t_${i}.setToValue(${item.value});
  BOOST_CHECK_EQUAL(t_${i}.getId(), ${name}::${item.idName});
  BOOST_CHECK_EQUAL(t_${i}, ${name}::${item.idName});
  BOOST_CHECK_EQUAL(t_${i}.getIndex(), getEnumOrigIndex(${name}::${item.idName}));
  BOOST_CHECK_EQUAL(t_${i}.getName(), "${item.name}");
  BOOST_CHECK_EQUAL(t_${i}.getValue(), ${item.value});
  BOOST_CHECK_EQUAL(t_${i}.getValue(), ${name}::${item.valName});
  BOOST_CHECK_EQUAL(t_${i}.toString(), "${item.display}");
<%shared:close_ifdef name="${item.close_ifdef}"/>\

% endfor
}

BOOST_AUTO_TEST_CASE( test_${name.lower()}_from_set_id ) {
% for i, item in enumerate(items):
<%shared:open_ifdef name="${item.open_ifdef}"/>\
  ${name} t_${i};
  t_${i}.setId(${name}::${item.idName});
  BOOST_CHECK_EQUAL(t_${i}.getId(), ${name}::${item.idName});
  BOOST_CHECK_EQUAL(t_${i}, ${name}::${item.idName});
  BOOST_CHECK_EQUAL(t_${i}.getIndex(), getEnumOrigIndex(${name}::${item.idName}));
  BOOST_CHECK_EQUAL(t_${i}.getName(), "${item.name}");
  BOOST_CHECK_EQUAL(t_${i}.getValue(), ${item.value});
  BOOST_CHECK_EQUAL(t_${i}.getValue(), ${name}::${item.valName});
  BOOST_CHECK_EQUAL(t_${i}.toString(), "${item.display}");
<%shared:close_ifdef name="${item.close_ifdef}"/>\

% endfor
}

BOOST_AUTO_TEST_CASE(test_${name.lower()}_from_set_index) {
% for i, item in enumerate(items):
<%shared:open_ifdef name="${item.open_ifdef}"/>\
  ${name} t_${i};
  int idx${i} = getEnumOrigIndex(${name}::${item.idName});
  t_${i}.setToIndex(idx${i});
  BOOST_CHECK_EQUAL(t_${i}.getId(), ${name}::${item.idName});
  BOOST_CHECK_EQUAL(t_${i}, ${name}::${item.idName});
  BOOST_CHECK_EQUAL(t_${i}.getIndex(), idx${i});
  BOOST_CHECK_EQUAL(t_${i}.getName(), "${item.name}");
  BOOST_CHECK_EQUAL(t_${i}.getValue(), ${item.value});
  BOOST_CHECK_EQUAL(t_${i}.getValue(), ${name}::${item.valName});
  BOOST_CHECK_EQUAL(t_${i}.toString(), "${item.display}");
<%shared:close_ifdef name="${item.close_ifdef}"/>\

% endfor
}

BOOST_AUTO_TEST_CASE(test_${name.lower()}_stream) {
% for i, item in enumerate(items):
<%shared:open_ifdef name="${item.open_ifdef}"/>\
  ${name} t_${i};
  int idx${i} = getEnumOrigIndex(${name}::${item.idName});
  t_${i}.setToIndex(idx${i});
  BOOST_CHECK_EQUAL(t_${i}.getId(), ${name}::${item.idName});
  BOOST_CHECK_EQUAL(t_${i}, ${name}::${item.idName});
  BOOST_CHECK_EQUAL(t_${i}.getIndex(), idx${i});
  BOOST_CHECK_EQUAL(t_${i}.getName(), "${item.name}");
  BOOST_CHECK_EQUAL(t_${i}.getValue(), ${item.value});
  BOOST_CHECK_EQUAL(t_${i}.getValue(), ${name}::${item.valName});
  BOOST_CHECK_EQUAL(t_${i}.toString(), "${item.display}");
  {
    std::ostringstream oss;
    oss <<  t_${i};
    BOOST_CHECK_EQUAL(oss.str(), "${item.name}");

    ${name} enumFromStream;
    std::istringstream iss("${item.name}");
    iss >> enumFromStream;
    BOOST_CHECK_EQUAL(enumFromStream, ${name}::${item.idName});
  }
<%shared:close_ifdef name="${item.close_ifdef}"/>\

% endfor
}
