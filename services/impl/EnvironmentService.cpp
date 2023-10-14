#include "../EnvironmentService.hpp"

EnvironmentService::EnvironmentService(char *path)
{
    this->environment = getenv(path);
}

std::vector<std::string> EnvironmentService::getEnvironmentValues()
{
    std::vector<std::string> environmentPaths;
    std::string value;
    for (int i = 0; i < (this->environment).length(); i++)
    {
        char c = this->environment[i];
        if (c == ';' && value.size())
        {
            environmentPaths.push_back(value);
            value = "";
        }
        else if (c != ';')
            value += c;
    }
    return environmentPaths;
}
