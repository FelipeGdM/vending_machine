/**
 * @file main.c
 * @class Machina
 * @author Felipe Gomes de Melo <felipegmelo@usp.br>
 * @brief
 * @date 04/2020
 *
 * @copyright MIT License - Copyright (c) 2020
 *
 */

#include <stdio.h>
#include "definicoes_sistema.h"
#include "atuadores.h"
#include "display.h"
#include "teclado.h"
#include "utils.h"

/**
 * @memberof Machina
 *
 * @brief Inicializa componentes da vending machine
 *
 */
void machina_init(){
    atuadores_init();
    display_init();
    teclado_init();
    trava_init();
}

int main(){

    char bom_dia[] = "Digite o produto que deve ser liberado: ";

    display_exibe_msg(bom_dia, len(bom_dia));
    uint8_t prod_id = teclado_le_prod_id();
    atuadores_libera_produto(prod_id);

    return 0;
}
