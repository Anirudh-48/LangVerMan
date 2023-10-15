#include "./json/json11.hpp"
#include "./injector/DependencyInjector.hpp"

std::string getUrl(json11::Json languageMap, std::string language, std::string version)
{
    for (auto &item : languageMap[LANGUAGES][language][VERSIONS].array_items())
    {
        if (item[VERSION] == version)
            return item["x64Url"].string_value();
    }
    return NO_LANG_VERSION;
}

int main(int argc, char *argv[])
{
    std::string jsonString = "";
    std::string error = "";
    int index = ((std::string)argv[0]).find_last_of("/\\");
    std::string path = ((std::string)argv[0]).substr(0, index);
    std::string command = "echo " + path + " > path.txt";
    system(command.data());
    DependencyInjector *instance = DependencyInjector::getInstance();

    instance->languageService->readFileData(path);
    instance->downloadService->setLanguageJson(instance->languageService->getLanguageObject());
    json11::Json languageMap = instance->languageService->getLanguageObject();

    if (argc > 4)
    {
        std::string flag = argv[1], language = argv[2], versionFlag = argv[3], version = argv[4];
        std::string url;
        if ((flag == (std::string) "-i" && versionFlag == (std::string) "-v"))
        {
            url = getUrl(languageMap, language, version);
            if (url != NO_LANG_VERSION)
            {
                instance->downloadService->download(language, version);
                instance->installerService->installLanguageVersion(language, version, url.substr(url.find_last_of(".msi")).length() > 0);
            }
            else
                std::cerr << NO_LANG_VERSION << '\n';
        }
        else if (((std::string)argv[1] == (std::string) "-u" && (std::string)argv[3] == (std::string) "-v"))
        {
            url = getUrl(languageMap, language, version);
            if (url != NO_LANG_VERSION)
            {
                instance->installerService->uninstallLanguageVersion(language, version, url.substr(url.find_last_of(".msi")).length() > 0);
            }
            else
                std::cerr << NO_LANG_VERSION << '\n';
        }
    }
    else
    {
        std::cerr << "check args...";
    }
    return 0;
}