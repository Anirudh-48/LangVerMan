# LangVerMan

This is a CLI tool which can be used to manage different versions of programming languages. The tool can also be used to switch environments automatically.

In order to use the program, the following commands need to be executed:

1. g++ -c ./injector/DependencyInjector.cpp ./services/impl/LanguageReaderService.cpp ./services/impl/DownloadService.cpp ./json/json11.cpp -std=gnu++11 -static-libstdc++ -static-libgcc
2. g++ -o main json11.o LanguageReaderService.o DownloadService.o DependencyInjector.o LangManMain.cpp -std=gnu++11 -static-libstdc++ -static-libgcc
3. ./main.exe -i java -v 17.0.8

Flags and their meanings:
-i: install
-v: version

<h3>Please note that for now the tool only downloads the file. The installation functionality will be added soon!</h3>
