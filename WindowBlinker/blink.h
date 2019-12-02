/**
 * @file blink.h
 * @author Lucas Vieira (lucas.engen.cc@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-12-02
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef BLINK_H
#define BLINK_H

#include <stdbool.h>

typedef struct blink_params
{
    unsigned long delay;
} BPARAMS;

/**
 * @brief Thread para fazer as janelas piscarem
 * 
 * @param reserved Ponteiro para a estrutura blink_params
 */
extern void __stdcall blink_thread(void *reserved);

/**
 * @brief Força a finalização da thread principal
 * 
 */
extern void stop_blinking();

extern void __stdcall read_keyboard(void *reserved);

extern void ShowWarning();

static bool can_stop;

#endif