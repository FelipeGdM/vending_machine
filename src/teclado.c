/**
 * @file teclado.c
 * @author Felipe Gomes de Melo <felipegmelo@usp.br>
 * @brief 
 * @date 04/2020
 * 
 * @copyright MIT License - Copyright (c) 2020
 * 
 */

#include <stdio.h>
#include <stdint.h>
#include "teclado.h"

void teclado_le_entrada(char* buffer){
    scanf("%s", buffer);
}

uint8_t teclado_le_prod_id(){
    uint8_t output;
    scanf("%hhu", &output);
    return output;
}