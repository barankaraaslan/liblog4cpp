// My beautiful logging library

#include <iostream>
#include <string>

#include <liblog4cpp/log4cpp.hpp>

void log4cpp::log(std::string message) {
    std::cout << "Logged by my beautiful library ::" << message << std::endl;
}