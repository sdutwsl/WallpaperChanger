#include "stdafx.h"
#include"Engine.h"
#include <Windows.h>

namespace WallpaperChanger
{
	BOOL SetWallpaper(std::string &strPicFile, DWORD dwStyle)
	{
		CoInitialize(0);
		HRESULT hr;
		IActiveDesktop* pIAD;
		//创建接口的实例
		hr = CoCreateInstance(CLSID_ActiveDesktop, NULL, CLSCTX_INPROC_SERVER,
			IID_IActiveDesktop, (void**)&pIAD);
		if (!SUCCEEDED(hr)) return FALSE;
		//将文件名改为宽字符串,这是IActiveDesktop::SetWallpaper的要求
		WCHAR wszWallpaper[MAX_PATH];

		LPTSTR lpStr = const_cast<char*>(strPicFile.c_str());
		MultiByteToWideChar(CP_ACP, 0, lpStr, -1, wszWallpaper, MAX_PATH);
		//设置墙纸
		hr = pIAD->SetWallpaper(wszWallpaper, 0);
		if (!SUCCEEDED(hr)) return FALSE;
		//设置墙纸的样式
		WALLPAPEROPT wpo;
		wpo.dwSize = sizeof(wpo);
		wpo.dwStyle = dwStyle;
		hr = pIAD->SetWallpaperOptions(&wpo, 0);
		if (!SUCCEEDED(hr)) return FALSE;
		//应用墙纸的设置
		hr = pIAD->ApplyChanges(AD_APPLY_ALL);
		if (!SUCCEEDED(hr)) return FALSE;

		//释放接口的实例
		pIAD->Release();
		return TRUE;
	}
}