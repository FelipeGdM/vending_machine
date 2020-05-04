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

#include "boca_caixa.h"
#include "sistema.h"
#include "utils.h"
#include <stdio.h>

void boca_caixa_init(){
    return;
}

void boca_caixa_recebe_dinheiro(dinheiro_t* entrada){
    printf("Digite quantos reais e quantos centavos você irá inserir\n");
    printf("Reais:    ");
    scanf("%hhu", &entrada->reais);
    printf("Centavos: ");
    scanf("%hhu", &entrada->centavos);

    while(entrada->centavos >= 100){
        entrada->reais++;
        entrada->centavos -= 100;
    }

    printf("=> Quantia recebida: ");
    p_dinheiro_print(entrada);
    printf("\n");

}