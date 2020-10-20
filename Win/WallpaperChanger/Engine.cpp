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
		//�����ӿڵ�ʵ��
		hr = CoCreateInstance(CLSID_ActiveDesktop, NULL, CLSCTX_INPROC_SERVER,
			IID_IActiveDesktop, (void**)&pIAD);
		if (!SUCCEEDED(hr)) return FALSE;
		//���ļ�����Ϊ���ַ���,����IActiveDesktop::SetWallpaper��Ҫ��
		WCHAR wszWallpaper[MAX_PATH];

		LPTSTR lpStr = const_cast<char*>(strPicFile.c_str());
		MultiByteToWideChar(CP_ACP, 0, lpStr, -1, wszWallpaper, MAX_PATH);
		//����ǽֽ
		hr = pIAD->SetWallpaper(wszWallpaper, 0);
		if (!SUCCEEDED(hr)) return FALSE;
		//����ǽֽ����ʽ
		WALLPAPEROPT wpo;
		wpo.dwSize = sizeof(wpo);
		wpo.dwStyle = dwStyle;
		hr = pIAD->SetWallpaperOptions(&wpo, 0);
		if (!SUCCEEDED(hr)) return FALSE;
		//Ӧ��ǽֽ������
		hr = pIAD->ApplyChanges(AD_APPLY_ALL);
		if (!SUCCEEDED(hr)) return FALSE;

		//�ͷŽӿڵ�ʵ��
		pIAD->Release();
		return TRUE;
	}
}