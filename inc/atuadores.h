/**
 * @file atuadores.h
 * @author Felipe Gomes de Melo <felipegmelo@usp.br>
 * @brief Métodos para controle dos atuadores da vending machine
 * @date 04/2020
 *
 * @copyright MIT License - Copyright (c) 2020
 *
 */

#ifndef __ATUADORES_H__
#define __ATUADORES_H__

#include <stdint.h>
#include <stdio.h>

/**
 * @brief Envia o comando de liberação do produto indicado
 *
 * @param prod_id Id do produto a ser liberado
 */
void atuadores_libera_produto(uint8_t prod_id);

#endif // __ATUADORES_H__