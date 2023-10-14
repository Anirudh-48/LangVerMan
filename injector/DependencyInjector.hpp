#ifndef DependencyInjector_hpp
#define DependencyInjector_hpp
#include "../services/LanguageReaderService.hpp"
#include "../services/DownloadService.hpp"
#include "../services/EnvironmentService.hpp"
#include "../services/InstallerService.hpp"
#include "../json/json11.hpp"

class DependencyInjector
{
private:
    static DependencyInjector *dependencyInjector;
    static std::string path;

protected:
    DependencyInjector();

public:
    DownloadService *downloadService = NULL;
    InstallerService *installerService = NULL;
    LanguageReaderService *languageService = NULL;
    EnvironmentService *environmentService = NULL;
    static DependencyInjector *getInstance()
    {
        if (dependencyInjector == NULL)
        {
            dependencyInjector = new DependencyInjector();
        }
        return dependencyInjector;
    };
};
#endif