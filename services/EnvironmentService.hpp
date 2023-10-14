#ifndef EnvironmentService_hpp
#define EnvironmentService_hpp
#include <iostream>
#include <vector>
#include "../constants/AppConstants.cpp"
class EnvironmentService
{
private:
    std::string environment;

public:
    EnvironmentService(char *path = (char *)PATH);
    std::vector<std::string> getEnvironmentValues();
};
#endif