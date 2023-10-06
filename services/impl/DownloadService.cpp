#include "../DownloadService.hpp"

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
    std::string url;
    for (auto &item : languageMap[LANGUAGES][language][VERSIONS].array_items())
    {
        if (item["version"] == version)
            url = item["x64Url"].string_value();
    }
    std::cout << url;
    system("cmd.exe /c ECHO %PROCESSOR_ARCHITECTURE% > architecture.txt");
    if (url != "")
    {
        std::string command = "mkdir " + language + " & cd " + language + " & curl -X GET \"" + url + "\" -o " + language + "-" + version + url.substr(url.size() - 4);
        std::cout << command;
        auto res = system(command.data());
        std::cout << res;
    }
    else
    {
        std::cerr << "the requested version cannot be found!";
    }
}