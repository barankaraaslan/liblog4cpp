// My beautiful logging library

#include <iostream>
#include <string>

#include <liblog4cpp/log4cpp.hpp>

void log4cpp::log(std::string message) {
    std::cout << "log4cpp::" << message << std::endl;
}