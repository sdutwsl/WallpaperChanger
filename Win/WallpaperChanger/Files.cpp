#include "stdafx.h"
#include "Files.h"
namespace WallpaperChanger
{
	void GetDirectoryFiles(const std::string path, std::vector<std::string> &filenames)
	{
		WIN32_FIND_DATAA fd;
		std::string temp = path;
		std::string temp1 = path;
		HANDLE hFind = ::FindFirstFileA(temp.append("\\*.*").c_str(), &fd);

		if (hFind != INVALID_HANDLE_VALUE)
		{
			do {
				if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
				{//非目录，即文件
					filenames.push_back(temp1+"\\"+fd.cFileName);
				}
			} while (::FindNextFileA(hFind, &fd));

			::FindClose(hFind);
		}

	}
}