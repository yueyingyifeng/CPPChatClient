//
// Created by HP on 2023/12/22.
//

#include "ConfigManager.h"

const char* ConfigManager::CONFIG_FILE_NAME = "ClientConfig.ini";

ConfigManager::ConfigManager() {
    configFile = new ConfigFile();
    if(configFileExist())
        loadConfigFile();
    else
        createConfigFile();
}

void ConfigManager::createConfigFile() {
    ofstream ofs(CONFIG_FILE_NAME);
    for(pair<string,string> l : ConfigFile::defaultConfigFile){
        ofs << l.first << " = " << l.second << std::endl;
    }
    ofs.close();
}

bool ConfigManager::configFileExist() {
    ifstream i(CONFIG_FILE_NAME);

    if(!i.good()){
        i.close();
        return false;
    }
    i.close();
    return true;
}

bool ConfigManager::configFileIsFine()
{
    for (char c : this->configFile->getValue(ConfigFile::MAX_WIDTH_)) {
        if (c < '0' || c > '9')
            return false;
    }
	for (char c : this->configFile->getValue(ConfigFile::PORT_)) {
		if (c < '0' || c > '9')
			return false;
	}

    int i{1};
	for (char c : this->configFile->getValue(ConfigFile::IP_)) {
        if (i % 4 == 0 && c != '.')
            return false;
		else if ((c < '0' || c > '9'))
			return false;
	}

    return true;
}

void ConfigManager::loadConfigFile() {
    ifstream ifs(CONFIG_FILE_NAME);
    string word;
    for(int n{0}; ifs >> word; ){
        try {
			configFile->readLine(word, n++);
        }
        catch (std::exception e) {
            log(e.what());
            log("created a default file for you if you type any key");
            pause();
            createConfigFile();
			return;
        }
        if(n == 3)
            n = 0;
    }
    
    ifs.close();

    if (!configFileIsFine()) {
		log("created a default file for you if you type any key");
		pause();
		createConfigFile();
        delete configFile;
        configFile = new ConfigFile;
        
    }
}

void ConfigManager::saveConfigFile(){
    ofstream ofs(CONFIG_FILE_NAME);
    for(pair<string,string> p : configFile->getConfigFile())
        ofs << p.first << " = " << p.second << std::endl;
    ofs.close();
}

ConfigFile* ConfigManager::getConfigFile()
{
    return configFile;
}

