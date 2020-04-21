/**
 * @file teclado.h
 * @author Felipe Gomes de Melo <felipegmelo@usp.br>
 * @brief Métodos para interação com teclado de entrada do usuário
 * @date 04/2020
 *
 * @copyright MIT License - Copyright (c) 2020
 *
 */

#ifndef __TECLADO_H__
#define __TECLADO_H__

#include <stdint.h>

/**
 * @brief Função de inicialização do componente
 *
 */
void teclado_init();

/**
 * @brief
 *
 * @param buffer
 */
void teclado_le_entrada(char* buffer);

/**
 * @brief Lê o código de produto digitado pelo usuário
 *
 * @return uint8_t Código do produto digitado
 */
uint8_t teclado_le_prod_id();

#endif // __TECLADO_H__