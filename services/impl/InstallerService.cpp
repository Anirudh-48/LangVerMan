#include "../InstallerService.hpp"

void InstallerService::installLanguageVersion(std::string language, std::string version, bool isMsi)
{
    std::string command = "mkdir installs";
    system(command.data());
    command = "cd installs && mkdir " + language;
    system(command.data());
    command = " cd installs/" + language + " && mkdir " + version;
    system(command.data());
    if (isMsi)
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
        std::string installPath = path + "/installs/" + language + "/" + version;
        command = "cd / && cd " + path + "/" + language + " && msiexec /i " + language + "-" + version + ".msi ADDLOCAL=ZuluInstallation INSTALLDIR=" + installPath + " /qb";
        system(command.data());
    }
}