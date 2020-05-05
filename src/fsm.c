/**
 * @file fsm.c
 * @author Felipe Gomes de Melo <felipegmelo@usp.br>
 * @brief Implementação de uma máquina de estados finitos (finite state machine)
 * @date 04/2020
 *
 * @copyright MIT License - Copyright (c) 2020
 *
 */

#include "sistema.h"

static acao_t fsm_acao_transicao_estados[NUM_ESTADOS][NUM_EVENTOS];
static estado_t fsm_proximo_estado_transicao_estados[NUM_ESTADOS][NUM_EVENTOS];

void fsm_init(){
    uint8_t i;
    uint8_t j;

    for (i = 0; i < NUM_ESTADOS; i++) {
        for (j = 0; j < NUM_EVENTOS; j++) {
            fsm_acao_transicao_estados[i][j] = NENHUMA_ACAO;
            fsm_proximo_estado_transicao_estados[i][j] = i;
        }
    }

} // fsm_init

acao_t fsm_obter_acao(estado_t estado, evento_t codigo_evento) {
    return fsm_acao_transicao_estados[estado][codigo_evento];
} // fsm_obter_acao

estado_t fsm_obter_proximo_estado(estado_t estado, evento_t codigo_evento) {
    return fsm_proximo_estado_transicao_estados[estado][codigo_evento];
} // obterAcao


