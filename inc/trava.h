/**
 * @file trava.h
 * @class Trava
 * @author Felipe Gomes de Melo <felipegmelo@usp.br>
 * @brief Métodos de interface com a trava de manutenção da vending machine
 * @date 04/2020
 *
 * @copyright MIT License - Copyright (c) 2020
 *
 */

#include <stdbool.h>

#ifndef __TRAVA_H__
#define __TRAVA_H__

/**
 * @memberof Trava
 *
 * @private
 *
 * @brief Indica se a trava está aberta.
 *
 * Caso a trava seja aberta, a máquina irá para o estado de manutenção
 * assim que passar pelo estado de início
 *
 */
static bool trava_aberta;

/**
 * @memberof Trava
 * @brief Função de inicialização do componente
 *
 */
void trava_init();

/**
 * @memberof Trava
 * @brief Retorna o estado da trava
 *
 * @return true Se a trava estiver aberta
 * @return false Caso a trava esteja fechada
 */
bool trava_estado();

#endif // __TRAVA_H__
