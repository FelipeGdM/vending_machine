/**
 * @file display.h
 * @author Felipe Gomes de Melo <felipegmelo@usp.br>
 * @brief Métodos para controle da interface de texto da vending machine
 * @date 04/2020
 *
 * @copyright MIT License - Copyright (c) 2020
 *
 */

#ifndef __DISPLAY_H__

#include <stdint.h>

/**
 * @brief Função de inicialização do componente
 *
 */
void display_init();

/**
 * @brief Exibe uma mensagem para o usuário por meio do display
 *
 * @param msg Mensagem a ser mostrada
 * @param len Tamanho da mensagem
 */
void display_exibe_msg(char* msg, int8_t len);

#endif // __DISPLAY_H__