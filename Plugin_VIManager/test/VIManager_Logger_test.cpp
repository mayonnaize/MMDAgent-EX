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

// Test VIManager_Logger constructor and destructor
TEST(VIManagerLoggerTest, ConstructorDestructor) {
    VIManager_Logger logger;
    
    // Constructor and destructor should not crash
    SUCCEED();
}

// Test VIManager_Logger multiple instances
TEST(VIManagerLoggerTest, MultipleInstances) {
    VIManager_Logger logger1;
    VIManager_Logger logger2;
    VIManager_Logger logger3;
    
    // Multiple instances should be safe to create
    SUCCEED();
}

// Test VIManager_Logger setup with nullptr
TEST(VIManagerLoggerTest, SetupWithNull) {
    VIManager_Logger logger;
    
    // Setup with nullptr should not crash
    logger.setup(nullptr);
    
    SUCCEED();
}

// Test VIManager_Logger render with null parameters
TEST(VIManagerLoggerTest, RenderWithNullParams) {
    VIManager_Logger logger;
    
    // Render with null list should not crash
    logger.render(nullptr, 0, 800.0f, 600.0f);
    
    SUCCEED();
}

// Test VIManager_Logger render with various screen sizes
TEST(VIManagerLoggerTest, RenderWithVariousScreenSizes) {
    VIManager_Logger logger;
    
    // Test with different screen dimensions
    logger.render(nullptr, 0, 1920.0f, 1080.0f);
    logger.render(nullptr, 0, 1280.0f, 720.0f);
    logger.render(nullptr, 0, 640.0f, 480.0f);
    
    SUCCEED();
}

// Test VIManager_Logger render after setup
TEST(VIManagerLoggerTest, RenderAfterSetup) {
    VIManager_Logger logger;
    
    logger.setup(nullptr);
    logger.render(nullptr, 0, 800.0f, 600.0f);
    
    SUCCEED();
}

int main(int argc, char **argv) {
#if _MSC_VER
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
