/**
 * @file display.h
 * @class Display
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
 * @brief Imprime na tela uma quantia de dinheiro formatada com R$
 *
 */
#define display_dinheiro(dinheiro) printf("R$ %hhu.%02hhu", dinheiro.reais, dinheiro.centavos)

/**
 * @brief Imprime na tela uma quantia de dinheiro a partir de um ponteiro
 * formatada com R$
 */
#define display_p_dinheiro(dinheiro) printf("R$ %hhu.%02hhu", dinheiro->reais, dinheiro->centavos)

/**
 * @memberof Display
 *
 * @brief Função de inicialização do componente
 *
 */
void display_init();

/**
 * @memberof Display
 *
 * @brief Exibe uma mensagem para o usuário por meio do display
 *
 * @param msg Mensagem a ser mostrada
 */
void display_exibe_msg(char* msg);

#endif // __DISPLAY_H__