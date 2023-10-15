#include "../InstallerService.hpp"

void setup(std::string language, std::string version)
{
    std::string command = "mkdir installs";
    system(command.data());
    command = "cd installs && mkdir " + language;
    system(command.data());
    command = " cd installs/" + language + " && mkdir " + version;
    system(command.data());
}

std::string getPath()
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
    return stringData.str().substr(0, index);
}

void InstallerService::installLanguageVersion(std::string language, std::string version, bool isMsi)
{
    if (isMsi)
    {
        setup(language, version);
        std::string path = getPath();
        std::string installPath = path + "\\installs\\" + language + "\\" + version;
        std::string command = "cd \\ && cd " + path + "\\" + language + " && msiexec /i " + language + "-" + version + ".msi INSTALLDIR=" + installPath + " /qb";
        std::cout << command;
        system(command.data());
    }
}

void InstallerService::uninstallLanguageVersion(std::string language, std::string version, bool isMsi)
{
    if (isMsi)
    {
        std::string command = "cd \\ && cd " + getPath() + "\\" + language + " && msiexec /uninstall " + language + "-" + version + ".msi";
        system(command.data());
    }
}