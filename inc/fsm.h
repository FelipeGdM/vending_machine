/**
 * @file fsm.h
 * @author Felipe Gomes de Melo <felipegmelo@usp.br>
 * @brief Implementação de uma máquina de estados finitos (finite state machine)
 * @date 04/2020
 *
 * @copyright MIT License - Copyright (c) 2020
 *
 */

#ifndef __FSM_H__
#define __FSM_H__

#include <stdint.h>
#include "sistema.h"

void fsm_init();
acao_t fsm_obter_acao(estado_t estado, evento_t codigo_evento);
estado_t fsm_obter_proximo_estado(estado_t estado, evento_t codigo_evento);

#endif // __FSM_H__
