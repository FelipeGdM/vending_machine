/**
 * @file atuadores.c
 * @author Felipe Gomes de Melo <felipegmelo@usp.br>
 * @brief Métodos para controle dos atuadores da vending machine
 * @date 04/2020
 *
 * @copyright MIT License - Copyright (c) 2020
 *
 */

#include "atuadores.h"

void atuadores_init() {
    return;
}

void atuadores_libera_produto(uint8_t prod_id) {
    printf("Produto de código #%i liberado!\n", prod_id);
    printf("Obrigado e volte sempre!\n");
}
