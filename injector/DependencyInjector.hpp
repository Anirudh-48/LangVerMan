#ifndef DependencyInjector_hpp
#define DependencyInjector_hpp
#include "../services/LanguageReaderService.hpp"
#include "../services/DownloadService.hpp"
#include "../constants/AppConstants.cpp"
#include "../json/json11.hpp"

class DependencyInjector
{
private:
    // EnvironmentService *environmentService = NULL;
    static DependencyInjector *dependencyInjector;

protected:
    DependencyInjector();

public:
    DownloadService *downloadService = NULL;
    LanguageReaderService *languageService = NULL;

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