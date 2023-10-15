#ifndef InstallerService_hpp
#define InstallerService_hpp

#include <iostream>
#include <fstream>
#include <sstream>
#include "../constants/AppConstants.cpp"

class InstallerService
{
public:
    void installLanguageVersion(std::string language, std::string version, bool isMsi);
    void uninstallLanguageVersion(std::string language, std::string version, bool isMsi);
};
#endif