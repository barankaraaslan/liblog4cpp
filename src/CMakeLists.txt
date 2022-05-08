# FILE_SET requires cmake 3.23
cmake_minimum_required(VERSION 3.23)

project(log4cpp VERSION 1.0.0)
add_library(log4cpp)

file(GLOB_RECURSE sources CONFIGURE_DEPENDS *[!.test].cpp)
# file(GLOB_RECURSE test_sources CONFIGURE_DEPENDS *_test.cpp)

target_sources(log4cpp PRIVATE ${sources})
# Note: If there are new header files for the public api, add those filenames to command below
target_sources(log4cpp PUBLIC FILE_SET HEADERS FILES 
    liblog4cpp/log4cpp.hpp)

enable_testing()
add_executable(log4cpp_test liblog4cpp/log4cpp.test.cpp)
target_link_libraries(log4cpp_test PRIVATE log4cpp)
add_test(NAME can_run COMMAND log4cpp_test)
add_test(NAME output_check COMMAND log4cpp_test)
set_tests_properties(output_check PROPERTIES PASS_REGULAR_EXPRESSION "log4cpp::Hello World!")

install(TARGETS log4cpp)
install(TARGETS log4cpp FILE_SET HEADERS)
include(CPack)