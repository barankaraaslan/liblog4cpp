cmake_minimum_required(VERSION 3.23)

project(log4cpp VERSION 1.0.0)
add_library(log4cpp)

file(GLOB_RECURSE sources CONFIGURE_DEPENDS *[!.test].cpp)
file(GLOB_RECURSE test_sources CONFIGURE_DEPENDS *.test.cpp)

message(${sources})
message(${test_sources})
target_sources(log4cpp PUBLIC ${sources})
# Note: If there are new header files for the public api, add those filenames to command below
target_sources(log4cpp PUBLIC FILE_SET HEADERS FILES 
    liblog4cpp/log4cpp.hpp)

install(TARGETS log4cpp)
install(TARGETS log4cpp FILE_SET HEADERS)
include(CPack)