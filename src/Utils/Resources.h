#ifndef RESOURCES_H_
#define RESOURCES_H_

#include <string>

#ifdef __unix__
    static const std::string kResourceFolder = "./resources/";
#elif _WIN32
    static const std::string kResourceFolder = ".\\resources\\";
#endif

#endif // RESOURCES_H_
