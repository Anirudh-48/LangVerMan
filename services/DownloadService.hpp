#ifndef DownloadService_hpp
#define DownloadService_hpp
#include "../constants/AppConstants.cpp"
#include "../json/json11.hpp"
class DownloadService
{

public:
    json11::Json languageMap;

    DownloadService();
    void setLanguageJson(json11::Json languageMap);
    void download(std::string language, std::string version);
};
#endif