#ifndef  CONFIG_H
#define CONFIG_H
#include <string>

namespace WallpaperChanger
{
	struct Config
	{
		int iTime;
		std::string strPath;
	};
	void GetConfig(std::string, Config&);
}

#endif //  CONFIG_H
