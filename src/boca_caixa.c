/**
 * @file boca_caixa.c
 * @class "Boca Caixa"
 * @author Felipe Gomes de Melo <felipegmelo@usp.br>
 * @brief Funções para controle da interface de recebimento de dinheiro
 * @date 04/2020
 *
 * @copyright MIT License - Copyright (c) 2020
 *
 */

#include "display.h"
#include "boca_caixa.h"
#include "sistema.h"
#include "utils.h"
#include <stdio.h>

void boca_caixa_init(){
    return;
}

uint8_t boca_caixa_recebe_notas(dinheiro_t* entrada){

    scanf("%hhu", &entrada->reais);

    return 0;
}

uint8_t boca_caixa_recebe_moedas(dinheiro_t* entrada){

    scanf("%hhu", &entrada->centavos);

    while(entrada->centavos >= 100){
        entrada->reais++;
        entrada->centavos -= 100;
    }

    return 0;
}