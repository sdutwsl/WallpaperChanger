#ifndef ENGINE_H 
#define ENGINE_H
#include <wininet.h>
#include<shlobj.h>

#include <string>
#include <windows.h>
namespace WallpaperChanger
{
	BOOL SetWallpaper(std::string &strPicFile, DWORD dwStyle);
}
#endif // ENGINE_H 
