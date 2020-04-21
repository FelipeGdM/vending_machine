/**
 * @file diplay.c
 * @author Felipe Gomes de Melo <felipegmelo@usp.br>
 * @brief 
 * @date 04/2020
 * 
 * @copyright MIT License - Copyright (c) 2020
 * 
 */

#include "display.h"
#include <stdio.h>

void display_exibe_msg(char* msg, int8_t len){

    while(len>=0){
        putchar(*msg++);
        len--;
    }
}
