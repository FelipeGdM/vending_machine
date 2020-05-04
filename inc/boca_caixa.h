/**
 * @file boca_caixa.h
 * @class "Boca Caixa"
 * @author Felipe Gomes de Melo <felipegmelo@usp.br>
 * @brief Funções para controle da interface de recebimento de dinheiro
 * @date 04/2020
 *
 * @copyright MIT License - Copyright (c) 2020
 *
 */

#ifndef __BOCA_CAIXA_H__
#define __BOCA_CAIXA_H__

#include "sistema.h"

/**
 * @memberof "Boca Caixa"
 *
 * @brief Função de inicialização do componente
 *
 */
void boca_caixa_init();

/**
 * @memberof "Boca Caixa"
 *
 * @brief Recebe uma quantia de dinheiro
 *
 * @return dinheiro_t
 */
void boca_caixa_recebe_dinheiro(dinheiro_t* entrada);

#endif // __BOCA_CAIXA_H__
