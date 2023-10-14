#include "./json/json11.hpp"
#include "./injector/DependencyInjector.hpp"

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

    if (argc > 4 && ((std::string)argv[1] == (std::string) "-i" && (std::string)argv[3] == (std::string) "-v"))
    {
        instance->downloadService->download((std::string)argv[2], (std::string)argv[4]);
        instance->installerService->installLanguageVersion((std::string)argv[2], (std::string)argv[4], true);
    }
    else
    {
        std::cerr << "check args...";
    }
    return 0;
}