find_package(GTest CONFIG REQUIRED)

add_executable(test_stack ${CMAKE_CURRENT_SOURCE_DIR}/test_stack.cpp)
target_link_libraries(test_stack PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)

add_test(NAME test_stack COMMAND test_stack)
