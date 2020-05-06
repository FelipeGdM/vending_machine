/**
 * @file caixa_troco.h
 * @class "Caixa Troco"
 * @author Felipe Gomes de Melo <felipegmelo@usp.br>
 * @brief Métodos de interface da caixa de troco da vending machine
 * @date 05/2020
 * 
 * @copyright MIT License - Copyright (c) 2020
 * 
 */

#include "display.h"
#include "sistema.h"

static dinheiro_t troco_interno;

void caixa_troco_init(){
    troco_interno.reais = 10;
    troco_interno.centavos = 0;
}

uint8_t caixa_troco_existe_troco(dinheiro_t quantia){
    return quantia.reais > troco_interno.reais ||
        (quantia.reais == troco_interno.reais && quantia.centavos >= troco_interno.centavos);
};

uint8_t caixa_troco_emite_troco(dinheiro_t troco){
    display_exibe_msg("=> Libera ");
    display_dinheiro(troco);
    display_exibe_msg("de troco\n");

    troco_interno.reais -= troco.reais;
    troco_interno.centavos -= troco.centavos;

    return 0;
};

uint8_t caixa_troco_insere_troco(dinheiro_t quantia){

    troco_interno.reais += quantia.reais;
    troco_interno.centavos += quantia.centavos;

    return 0;
};
