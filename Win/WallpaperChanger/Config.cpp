#include "stdafx.h"
#include "Config.h"
#include <string>
#include <fstream>
namespace WallpaperChanger
{
	void GetConfig(std::string fileName, Config & config)
	{
		std::ifstream configFile(fileName);
		std::string strTemp1, strTemp2;
		std::getline(configFile, strTemp1);
		std::getline(configFile, strTemp2);
		config.strPath = strTemp1.substr(strTemp1.find('=') + 1, strTemp1.length() - strTemp1.find('=') - 1);
		config.iTime = atoi(strTemp2.substr(strTemp1.find('=') + 1, strTemp1.length() - strTemp1.find('=') - 1).c_str());
	}
}
