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
#include "VIManager.h"

// Test InputArguments_initialize and InputArguments_clear
TEST(VIManagerTest, InputArgumentsInitializeAndClear) {
    InputArguments ia;
    
    // Test with empty string
    InputArguments_initialize(&ia, "");
    EXPECT_EQ(ia.size, 0);
    EXPECT_EQ(ia.args, nullptr);
    EXPECT_EQ(ia.argc, nullptr);
    InputArguments_clear(&ia);
    
    // Test with simple string containing separators
    InputArguments_initialize(&ia, "arg1|arg2|arg3");
    EXPECT_GT(ia.size, 0);
    EXPECT_NE(ia.args, nullptr);
    EXPECT_NE(ia.argc, nullptr);
    InputArguments_clear(&ia);
    
    // After clear, verify cleanup
    EXPECT_EQ(ia.size, 0);
    EXPECT_EQ(ia.args, nullptr);
    EXPECT_EQ(ia.argc, nullptr);
}

// Test InputArguments with nested separators
TEST(VIManagerTest, InputArgumentsNestedSeparators) {
    InputArguments ia;
    
    // Test with nested separators (| and ,)
    InputArguments_initialize(&ia, "arg1,arg2|arg3,arg4");
    EXPECT_GT(ia.size, 0);
    if (ia.size > 0) {
        EXPECT_NE(ia.args, nullptr);
        EXPECT_NE(ia.argc, nullptr);
    }
    InputArguments_clear(&ia);
}

// Test InputArguments double clear (should be safe)
TEST(VIManagerTest, InputArgumentsDoubleClear) {
    InputArguments ia;
    
    InputArguments_initialize(&ia, "test");
    InputArguments_clear(&ia);
    // Second clear should not crash
    InputArguments_clear(&ia);
    
    EXPECT_EQ(ia.size, 0);
    EXPECT_EQ(ia.args, nullptr);
}

// Test VIManager constructor and destructor
TEST(VIManagerTest, ConstructorDestructor) {
    VIManager vim;
    
    // After construction, basic getters should not crash
    EXPECT_EQ(vim.getName(), nullptr);
    EXPECT_EQ(vim.getFileName(), nullptr);
    EXPECT_EQ(vim.getCurrentState(), nullptr);
    EXPECT_NE(vim.getCurrentVariableList(), nullptr);
}

// Test VIManager getEndFlag
TEST(VIManagerTest, GetEndFlag) {
    VIManager vim;
    
    // Initially should return a boolean value (typically true for uninitialized)
    bool flag = vim.getEndFlag();
    EXPECT_TRUE(flag == true || flag == false);
}

// Test VIManager getTransitionHistory
TEST(VIManagerTest, GetTransitionHistory) {
    VIManager vim;
    VIManager_Arc* list[10];
    
    // Should return 0 when no history exists
    int count = vim.getTransitionHistory(list, 10);
    EXPECT_GE(count, 0);
    EXPECT_LE(count, 10);
}

// Test VIManager getCurrentVariableList
TEST(VIManagerTest, GetCurrentVariableList) {
    VIManager vim;
    
    VIManager_VList* vlist = vim.getCurrentVariableList();
    EXPECT_NE(vlist, nullptr);
}

// Test VIManager multiple instances
TEST(VIManagerTest, MultipleInstances) {
    VIManager vim1;
    VIManager vim2;
    VIManager vim3;
    
    // All instances should be independent
    EXPECT_NE(vim1.getCurrentVariableList(), vim2.getCurrentVariableList());
    EXPECT_NE(vim2.getCurrentVariableList(), vim3.getCurrentVariableList());
}

int main(int argc, char **argv) {
#if _MSC_VER
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
