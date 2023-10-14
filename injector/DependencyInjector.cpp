#include "DependencyInjector.hpp"

DependencyInjector *DependencyInjector::dependencyInjector = NULL;

DependencyInjector::DependencyInjector()
{
    DependencyInjector::downloadService = new DownloadService();
    DependencyInjector::languageService = new LanguageReaderService();
    DependencyInjector::environmentService = new EnvironmentService();
    DependencyInjector::installerService = new InstallerService();
}
