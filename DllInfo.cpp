#pragma comment(lib,"version.lib")

#include <Windows.h>

#include "DllInfo.h"

size_t DLLVersion(std::string name)
{
    DWORD  verHandle = 0;
    UINT   size = 0;
    LPBYTE lpBuffer = NULL;
    DWORD  verSize = GetFileVersionInfoSize(name.c_str(), &verHandle);
    size_t result = 0;
    if (verSize != NULL)
    {
        LPSTR verData = new char[verSize];
        if (GetFileVersionInfo(name.c_str(), verHandle, verSize, verData))
        {
            if (VerQueryValue(verData, "\\", (VOID FAR * FAR*) & lpBuffer, &size))
            {
                if (size)
                {
                    VS_FIXEDFILEINFO* verInfo = (VS_FIXEDFILEINFO*)lpBuffer;
                    if (verInfo->dwSignature == 0xfeef04bd)
                    {
                        // Doesn't matter if you are on 32 bit or 64 bit,
                        // DWORD is always 32 bits, so first two revision numbers
                        // come from dwFileVersionMS, last two come from dwFileVersionLS

                        result = (verInfo->dwFileVersionLS >> 0) & 0xffff;
                    }
                }
            }
        }
        delete[] verData;
    }
    return result;
}


void InitConstants()
{
    
}