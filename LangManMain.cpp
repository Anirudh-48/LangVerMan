#include "./json/json11.hpp"
#include "./injector/DependencyInjector.hpp"
using namespace std;

int main(int argc, char *argv[])
{
    string jsonString = "";
    string error = "";
    int index = ((string)argv[0]).find_last_of("/\\");
    string path = ((string)argv[0]).substr(0, index);
    DependencyInjector *instance = DependencyInjector::getInstance();

    instance->languageService->readFileData(path);
    instance->downloadService->setLanguageJson(instance->languageService->getLanguageObject());
    json11::Json languageMap = instance->languageService->getLanguageObject();

    if ((string)argv[1] == (string) "-i" && (string)argv[3] == (string) "-v")
    {
        std::cout << "downloading service..\n";
        instance->downloadService->download((string)argv[2], (string)argv[4]);
    }
    else
    {
        std::cout << "check args...";
    }
    return 0;
}