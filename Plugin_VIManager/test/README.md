# Plugin_VIManager Tests

This directory contains Google Tests for the Plugin_VIManager component.

## Test Files

- `VIManager_test.cpp` - Tests for VIManager.cpp
- `VIManager_Logger_test.cpp` - Tests for VIManager_Logger.cpp
- `VIManager_Thread_test.cpp` - Tests for VIManager_Thread.cpp
- `Plugin_VIManager_test.cpp` - Tests for Plugin_VIManager.cpp

## Building Tests

The tests are integrated into the main CMake build system. To build and run the tests:

1. First, install all required dependencies as listed in `requirements-linux.txt` (for Linux) or `requirements-mac.txt` (for macOS) at the repository root.

2. Configure and build the project from the repository root:
   ```bash
   cd /path/to/MMDAgent-EX
   mkdir -p build
   cd build
   cmake ..
   make
   ```

3. Run the tests:
   ```bash
   # Run all VIManager tests
   ctest -R VIManager
   
   # Or run individual test executables
   ./Plugin_VIManager/test/VIManager_test
   ./Plugin_VIManager/test/VIManager_Logger_test
   ./Plugin_VIManager/test/VIManager_Thread_test
   ./Plugin_VIManager/test/Plugin_VIManager_test
   ```

## Test Structure

Each test file follows the Google Test framework conventions:

- Tests are organized using `TEST()` macros
- Test fixtures can be created using `TEST_F()` macros
- The main function initializes Google Test and runs all tests

## Adding New Tests

To add new tests:

1. Add new `TEST()` or `TEST_F()` blocks to the appropriate test file
2. Follow the naming convention: `TEST(TestSuiteName, TestName)`
3. Use Google Test assertions (EXPECT_*, ASSERT_*) to verify behavior
4. Rebuild the tests using `make` in the build directory

## Dependencies

The tests depend on:
- Google Test v1.14.0 (automatically fetched via CMake FetchContent)
- MMDAgent library
- re2 library (for regular expression support)
- Other libraries required by Plugin_VIManager

## Notes

- Tests are designed to be minimal and focus on testing public interfaces
- Some tests may require mock objects or test fixtures for complex functionality
- The tests are built only when the main project is configured with CMake
