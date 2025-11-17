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
#include "CountDown_Thread.h"

// Test CountDown_Thread constructor and destructor
TEST(CountDownThreadTest, ConstructorDestructor) {
    CountDown_Thread thread;
    // If we reach here without crash, basic construction/destruction works
    SUCCEED();
}

// Test CountDown_Thread isRunning before start
TEST(CountDownThreadTest, IsRunningBeforeStart) {
    CountDown_Thread thread;
    // Before starting, the thread should not be running
    bool running = thread.isRunning();
    EXPECT_FALSE(running);
}

// Test CountDown_Thread multiple instances
TEST(CountDownThreadTest, MultipleInstances) {
    CountDown_Thread thread1;
    CountDown_Thread thread2;
    CountDown_Thread thread3;
    
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
