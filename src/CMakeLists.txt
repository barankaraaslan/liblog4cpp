# FILE_SET requires cmake 3.23
cmake_minimum_required(VERSION 3.23)

project(log4cpp)
add_library(log4cpp)

file(GLOB_RECURSE sources CONFIGURE_DEPENDS *[!.test].cpp)

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

# Rest of the file is used for packaging
install(TARGETS log4cpp EXPORT log4cppTargets FILE_SET HEADERS)
# Write Package Config file and install
install(EXPORT log4cppTargets
    FILE
        log4cppConfig.cmake
    NAMESPACE
        log4cpp::
    DESTINATION
        lib/
)
include(CPack)