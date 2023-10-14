#include "../DownloadService.hpp"
#include <fstream>
#include <sstream>

DownloadService::DownloadService()
{
    DownloadService::languageMap = json11::Json::object();
}
void DownloadService::setLanguageJson(json11::Json languageMap)
{
    DownloadService::languageMap = languageMap;
}
void DownloadService::download(std::string language, std::string version)
{
    std::fstream file = std::fstream("path.txt");
    std::ostringstream stringData;
    stringData << file.rdbuf();
    int index = -1;
    for (int i = 0; i < stringData.str().length(); i++)
    {
        if (stringData.str()[i] == ' ')
        {
            index = i;
            break;
        }
    }
    std::string path = stringData.str().substr(0, index);
    std::string msiFilePath = path + "/" + language + "/" + language + "-" + version + ".msi";
    if (FILE *file = std::fopen(msiFilePath.data(), "r"))
    {
        return;
    }
    std::string exeFilePath = path + "/" + language + "/" + language + "-" + version + ".exe";
    if (FILE *file = std::fopen(exeFilePath.data(), "r"))
    {
        return;
    }
    std::string url;
    if (languageMap[LANGUAGES][language][VERSIONS].array_items().size() > 0)
    {
        for (auto &item : languageMap[LANGUAGES][language][VERSIONS].array_items())
        {
            if (item[VERSION] == version)
                url = item["x64Url"].string_value();
        }
        if (url != "")
        {
            std::string command = "mkdir " + language + " & cd " + language + " & curl -X GET \"" + url + "\" -o " + language + "-" + version + url.substr(url.size() - 4);
            auto res = system(command.data());
        }
        else
        {
            std::cerr << "the requested version cannot be found!";
        }
    }
    else
    {
        std::cerr << "Requested Language and version cannot be found!";
        return;
    }
}