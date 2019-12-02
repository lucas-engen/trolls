/**
 * @file main.c
 * @author Lucas Vieira (lucas.engen.cc@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-12-02
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "blink.h"
#include <windows.h>

int main()
{
    HANDLE thread, kbd_thread;
    struct blink_params bp;
    DWORD thread_id, kbd_thread_id;

    // Oculta a janela do console
    ShowWindow(GetConsoleWindow(), 0);
    
    // Aguarda um tempo
    Sleep(100);

    // Muda o foco atual
    SetForegroundWindow(GetDesktopWindow());

    ShowWarning();

    // Configura o delay
    bp.delay = 1000;

    // Cria a thread principal
    thread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)blink_thread, &bp, 0, &thread_id);
    if(!thread)
        return 1;

    // Cria a thread para leitura do teclado
    kbd_thread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)read_keyboard, NULL, 0, &kbd_thread_id);
    if(!kbd_thread)
        return 1;

    // Aguarda até que a thread seja finalizada
    WaitForSingleObject(thread, INFINITE);

    // Fecha a thread para ler o teclado
    WaitForSingleObject(kbd_thread, INFINITE);

    return 0;
}