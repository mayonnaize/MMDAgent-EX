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
#include "CountDown_Thread.h"

// Mock test to verify the plugin header constants are defined
TEST(PluginVariablesTest, ConstantsAreDefined) {
    // Test that important constants are defined
    EXPECT_STREQ(VARIABLES_VALUESETEVENT, "VALUE_EVENT_SET");
    EXPECT_STREQ(VARIABLES_VALUEUNSETEVENT, "VALUE_EVENT_UNSET");
    EXPECT_STREQ(VARIABLES_VALUEEVALEVENT, "VALUE_EVENT_EVAL");
    EXPECT_STREQ(VARIABLES_VALUEGETEVENT, "VALUE_EVENT_GET");
    
    EXPECT_STREQ(VARIABLES_EQ, "EQ");
    EXPECT_STREQ(VARIABLES_NE, "NE");
    EXPECT_STREQ(VARIABLES_LE, "LE");
    EXPECT_STREQ(VARIABLES_LT, "LT");
    EXPECT_STREQ(VARIABLES_GE, "GE");
    EXPECT_STREQ(VARIABLES_GT, "GT");
    EXPECT_STREQ(VARIABLES_TRUE, "TRUE");
    EXPECT_STREQ(VARIABLES_FALSE, "FALSE");
}

// Test that countdown thread constants are defined
TEST(PluginVariablesTest, CountDownConstantsAreDefined) {
    EXPECT_STREQ(COUNTDOWNTHREAD_TIMERSTARTEVENT, "TIMER_EVENT_START");
    EXPECT_STREQ(COUNTDOWNTHREAD_TIMERSTOPEVENT, "TIMER_EVENT_STOP");
    EXPECT_STREQ(COUNTDOWNTHREAD_TIMERCANCELLEDEVENT, "TIMER_EVENT_CANCELLED");
}

// Test that we can create Variables and CountDown_Thread instances
TEST(PluginVariablesTest, CanCreateInstances) {
    Variables vars;
    CountDown_Thread thread;
    
    // If we reach here, instances were created successfully
    SUCCEED();
}

int main(int argc, char **argv) {
#if _MSC_VER
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
