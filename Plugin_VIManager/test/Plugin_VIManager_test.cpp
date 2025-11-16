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
#include "VIManager_Logger.h"
#include "VIManager_Thread.h"

// Test that plugin structures compile correctly
TEST(PluginVIManagerTest, BasicStructure) {
    // This test verifies that the plugin structure is properly set up
    // and can be compiled with all dependencies
    SUCCEED();
}

// Test VIManager component integration
TEST(PluginVIManagerTest, VIManagerComponent) {
    VIManager vim;
    
    // Basic VIManager should work within plugin context
    EXPECT_NE(vim.getCurrentVariableList(), nullptr);
    SUCCEED();
}

// Test VIManager_Logger component integration
TEST(PluginVIManagerTest, VIManagerLoggerComponent) {
    VIManager_Logger logger;
    
    // Logger should work within plugin context
    logger.setup(nullptr);
    logger.render(nullptr, 0, 800.0f, 600.0f);
    SUCCEED();
}

// Test VIManager_Thread component integration
TEST(PluginVIManagerTest, VIManagerThreadComponent) {
    VIManager_Thread thread;
    
    // Thread should work within plugin context
    EXPECT_FALSE(thread.isRunning());
    SUCCEED();
}

// Test all components together
TEST(PluginVIManagerTest, AllComponentsTogether) {
    VIManager vim;
    VIManager_Logger logger;
    VIManager_Thread thread;
    
    // All components should coexist
    EXPECT_NE(vim.getCurrentVariableList(), nullptr);
    EXPECT_FALSE(thread.isRunning());
    
    logger.setup(nullptr);
    thread.renderLog(800.0f, 600.0f);
    
    SUCCEED();
}

int main(int argc, char **argv) {
#if _MSC_VER
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
