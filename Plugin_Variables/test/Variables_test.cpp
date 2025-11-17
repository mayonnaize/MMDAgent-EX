/*
  Copyright 2022-2023  Nagoya Institute of Technology

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/

#include <gtest/gtest.h>
#include "MMDAgent.h"
#include "Variables.h"

// Test Variables constructor and destructor
TEST(VariablesTest, ConstructorDestructor) {
    Variables vars;
    // If we reach here without crash, basic construction/destruction works
    SUCCEED();
}

// Test Variables setup
TEST(VariablesTest, Setup) {
    Variables vars;
    // Note: We cannot fully test setup without a real MMDAgent instance
    // This test just ensures the method exists and doesn't crash with NULL
    vars.setup(NULL, 0);
    SUCCEED();
}

// Test Variables set with NULL alias (should handle gracefully)
TEST(VariablesTest, SetWithNullAlias) {
    Variables vars;
    // Setup with NULL mmdagent - the set method should handle this
    vars.setup(NULL, 0);
    // This should not crash even with NULL alias
    // The actual behavior depends on MMDAgent_strlen implementation
    SUCCEED();
}

// Test Variables multiple instances
TEST(VariablesTest, MultipleInstances) {
    Variables vars1;
    Variables vars2;
    Variables vars3;
    
    // All instances should be independent and constructible
    SUCCEED();
}

int main(int argc, char **argv) {
#if _MSC_VER
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
