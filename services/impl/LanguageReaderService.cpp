#include "../LanguageReaderService.hpp"

LanguageReaderService::LanguageReaderService()
{
    LanguageReaderService::languageObject = json11::Json::object();
}
LanguageReaderService::LanguageReaderService(json11::Json languageObject)
{
    LanguageReaderService::languageObject = languageObject;
}

void LanguageReaderService::readFileData(std::string path)
{
    LanguageReaderService::input = std::fstream(path + (std::string)DATA_PATH);
    LanguageReaderService::outputStream << input.rdbuf();
    std::string error = "";
    LanguageReaderService::languageObject = json11::Json(json11::Json::parse(outputStream.str(), error, json11::JsonParse::STANDARD));
}
json11::Json LanguageReaderService::getLanguageObject()
{
    return LanguageReaderService::languageObject;
};