#include <iostream>
#include <vector>
#include "../constants/AppConstants.cpp"

class EnvironmentService
{
private:
    std::string environment;

public:
    EnvironmentService(char *path = (char *)PATH)
    {
        this->environment = getenv(path);
    }
    std::vector<std::string> getEnvironmentValues()
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
};