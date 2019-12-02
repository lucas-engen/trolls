/**
 * @file blink.c
 * @author Lucas Vieira (lucas.engen.cc@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-12-02
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "blink.h"
#include <stdio.h>
#include <windows.h>

void __stdcall blink_thread(void *reserved)
{
    HWND window;
    struct blink_params *bp = NULL;

    bp = (struct blink_params*)reserved;
    if(!bp)
        return;

    while (!can_stop)
    {
        // Obtém a janela mais acima na hierarquia
        window = GetForegroundWindow();
        if(!window)
            continue;

        // Pisca a janela
        ShowWindow(window, 0);
        Sleep(bp->delay);
        ShowWindow(window, 1);
        Sleep(bp->delay);
    }

    if (bp)
        free(bp);
}

void stop_blinking()
{
    can_stop = true;
}

void __stdcall read_keyboard(void *reserved)
{
    short keyState;
    DWORD delay = 100;

    while(true)
    {
        keyState = GetAsyncKeyState(VK_ESCAPE);
        keyState >>= 8;

#ifdef _debug
        fprintf(stdout, "KeyState: %d (%x)\n", keyState, keyState & 0x80);
#endif

        if (keyState & 0x80)
        {
            stop_blinking();
            MessageBoxW(0, L"O programa foi fechado com sucesso", L"Informação", MB_ICONINFORMATION);

            break;
        }

        Sleep(delay);
    }
}

void ShowWarning()
{
    MessageBoxW(0, L"Aperte ESC para finalizar este programa", L"Atenção", MB_ICONWARNING);
}