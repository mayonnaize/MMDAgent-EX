#
#  Copyright 2022-2023  Nagoya Institute of Technology
#
#  Licensed under the Apache License, Version 2.0 (the "License");
#  you may not use this file except in compliance with the License.
#  You may obtain a copy of the License at
#
#    http://www.apache.org/licenses/LICENSE-2.0
#
#  Unless required by applicable law or agreed to in writing, software
#  distributed under the License is distributed on an "AS IS" BASIS,
#  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#  See the License for the specific language governing permissions and
#  limitations under the License.
#

cmake_minimum_required(VERSION 3.10)

project(Plugin_VIManager_Test)

# packages required to build this project
if(APPLE)
    find_package(re2 REQUIRED)
    set(RE_LIBRARIES re2::re2)
else()
    set(RE_LIBRARIES -lre2)
endif()

# Include directories
include_directories(
    .
    ..
    ../../Library_Bullet_Physics/include
    ../../Library_GLFW/include
    ../../Library_MMDFiles/include
    ../../Library_MMDAgent/include
    ../../Library_MMDAgent/src/include
    ../../Library_FreeType/include
    ../../Library_UTF8-CPP/include
    ../../Library_libpng/include
    ../../Library_cpphttplib/include
)

# Compile definitions
add_definitions(-DMMDAGENT)
add_definitions(-D_VARIADIC_MAX=10)
if(APPLE)
    add_definitions(-DGL_GLEXT_PROTOTYPES)
    add_definitions(-DMMDAGENT_DONTPICKMODEL)
    add_definitions(-DNO_OFFSCREEN_RENDERING)
else()
    add_definitions(-DGL_GLEXT_PROTOTYPES)
    add_definitions(-DMMDAGENT_DONTPICKMODEL)
endif()

# Code coverage option
option(CODE_COVERAGE "Enable code coverage" OFF)
if(CODE_COVERAGE AND CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage -fprofile-arcs -ftest-coverage")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --coverage -fprofile-arcs -ftest-coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage -lgcov")
endif()

# Link libraries
link_libraries(
    ${RE_LIBRARIES}
)

# Find or fetch Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.14.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

if(NOT WIN32)
    link_libraries(pthread)
endif()

# Test for VIManager.cpp
add_executable(VIManager_test
    VIManager_test.cpp
    ../VIManager.cpp
)

target_link_libraries(VIManager_test
    gtest_main
    MMDAGENT
    ${RE_LIBRARIES}
)

if(APPLE)
    target_compile_options(VIManager_test PRIVATE
        -std=c++17
        -Wno-deprecated-declarations
    )
else()
    target_compile_options(VIManager_test PRIVATE
        -std=c++17
        -Wno-deprecated-declarations
        -Wno-format-truncation
    )
endif()

add_test(NAME VIManager_test COMMAND VIManager_test)

# Test for VIManager_Logger.cpp
add_executable(VIManager_Logger_test
    VIManager_Logger_test.cpp
    ../VIManager_Logger.cpp
    ../VIManager.cpp
)

target_link_libraries(VIManager_Logger_test
    gtest_main
    MMDAGENT
    ${RE_LIBRARIES}
)

if(APPLE)
    target_compile_options(VIManager_Logger_test PRIVATE
        -std=c++17
        -Wno-deprecated-declarations
    )
else()
    target_compile_options(VIManager_Logger_test PRIVATE
        -std=c++17
        -Wno-deprecated-declarations
        -Wno-format-truncation
    )
endif()

add_test(NAME VIManager_Logger_test COMMAND VIManager_Logger_test)

# Test for VIManager_Thread.cpp
add_executable(VIManager_Thread_test
    VIManager_Thread_test.cpp
    ../VIManager_Thread.cpp
    ../VIManager.cpp
    ../VIManager_Logger.cpp
)

target_link_libraries(VIManager_Thread_test
    gtest_main
    MMDAGENT
    ${RE_LIBRARIES}
)

if(APPLE)
    target_compile_options(VIManager_Thread_test PRIVATE
        -std=c++17
        -Wno-deprecated-declarations
    )
else()
    target_compile_options(VIManager_Thread_test PRIVATE
        -std=c++17
        -Wno-deprecated-declarations
        -Wno-format-truncation
    )
endif()

add_test(NAME VIManager_Thread_test COMMAND VIManager_Thread_test)

# Test for Plugin_VIManager.cpp
add_executable(Plugin_VIManager_test
    Plugin_VIManager_test.cpp
    ../Plugin_VIManager.cpp
    ../VIManager.cpp
    ../VIManager_Logger.cpp
    ../VIManager_Thread.cpp
)

target_link_libraries(Plugin_VIManager_test
    gtest_main
    MMDAGENT
    ${RE_LIBRARIES}
)

if(APPLE)
    target_compile_options(Plugin_VIManager_test PRIVATE
        -std=c++17
        -Wno-deprecated-declarations
    )
else()
    target_compile_options(Plugin_VIManager_test PRIVATE
        -std=c++17
        -Wno-deprecated-declarations
        -Wno-format-truncation
    )
endif()

add_test(NAME Plugin_VIManager_test COMMAND Plugin_VIManager_test)
