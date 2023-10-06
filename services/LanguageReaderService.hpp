#ifndef LanguageReaderService_hpp
#define LanguageReaderService_hpp

#include "../constants/AppConstants.cpp"
#include <fstream>
#include <sstream>
#include "../json/json11.hpp"

class LanguageReaderService
{
private:
    std::fstream input;
    json11::Json languageObject;
    std::ostringstream outputStream;

public:
    LanguageReaderService();
    LanguageReaderService(json11::Json languageObject);
    void readFileData(std::string path);
    json11::Json getLanguageObject();
};

#endif