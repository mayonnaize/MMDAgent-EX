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

// Test VIManager_Thread constructor and destructor
TEST(VIManagerThreadTest, ConstructorDestructor) {
    VIManager_Thread thread;
    
    // Constructor and destructor should not crash
    SUCCEED();
}

// Test VIManager_Thread isRunning
TEST(VIManagerThreadTest, IsRunning) {
    VIManager_Thread thread;
    
    // Should return false when not started
    EXPECT_FALSE(thread.isRunning());
}

// Test VIManager_Thread renderLog
TEST(VIManagerThreadTest, RenderLog) {
    VIManager_Thread thread;
    
    // RenderLog should not crash even when not running
    thread.renderLog(800.0f, 600.0f);
    
    SUCCEED();
}

// Test VIManager_Thread updatePredictWords
TEST(VIManagerThreadTest, UpdatePredictWords) {
    VIManager_Thread thread;
    
    // updatePredictWords should not crash even when not running
    thread.updatePredictWords();
    
    SUCCEED();
}

int main(int argc, char **argv) {
#if _MSC_VER
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
