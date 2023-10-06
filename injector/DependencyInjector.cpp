#include "DependencyInjector.hpp"

DependencyInjector *DependencyInjector::dependencyInjector = NULL;

DependencyInjector::DependencyInjector()
{
    DependencyInjector::downloadService = new DownloadService();
    DependencyInjector::languageService = new LanguageReaderService();
}
