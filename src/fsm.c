/**
 * @file fsm.c
 * @author Felipe Gomes de Melo <felipegmelo@usp.br>
 * @brief Implementação de uma máquina de estados finitos (finite state machine)
 * @date 04/2020
 *
 * @copyright MIT License - Copyright (c) 2020
 *
 */

#include "fsm.h"
#include "sistema.h"

static fsm_acao_t fsm_acao_transicao_estados[NUM_ESTADOS][NUM_EVENTOS];
static fsm_estado_t fsm_proximo_estado_transicao_estados[NUM_ESTADOS][NUM_EVENTOS];

void fsm_acao_para_todo_evento(fsm_estado_t estado, fsm_acao_t acao){
    for (uint8_t j = 0; j < NUM_EVENTOS; j++)
        fsm_acao_transicao_estados[estado][j] = acao;
}

#define fsm_conecta_estado_evento_acao(estado, evento, acao) fsm_acao_transicao_estados[estado][evento] = acao
#define fsm_transicao_estado(estado, evento, prox_estado) fsm_proximo_estado_transicao_estados[estado][evento] = prox_estado;

void fsm_registra_transicao(estado_t estado, evento_t evento, acao_t acao, estado_t prox_estado){
    fsm_acao_transicao_estados[estado][evento] = acao
    fsm_proximo_estado_transicao_estados[estado][evento] = prox_estado;
}

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

fsm_acao_t fsm_obter_acao(fsm_estado_t estado, fsm_evento_t codigo_evento) {
    return fsm_acao_transicao_estados[estado][codigo_evento];
} // fsm_obter_acao

fsm_estado_t fsm_obter_proximo_estado(fsm_estado_t estado, fsm_evento_t codigo_evento) {
    return fsm_proximo_estado_transicao_estados[estado][codigo_evento];
} // fsm_obter_proximo_estado

