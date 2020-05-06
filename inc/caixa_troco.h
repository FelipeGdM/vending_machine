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

#ifndef __CAIXA_TROCO_H__
#define __CAIXA_TROCO_H__

/**
 * @memberof "Caixa Troco"
 * @brief Função de inicialização do componente
 */
void caixa_troco_init();

/**
 * @memberof "Caixa Troco"
 * @brief Confere se existe dinheiro na caixa de troco
 *
 * @param quantia Quantia de dinheiro a ser conferida
 * @return 0 se existe troco suficiente, 1 caso contrário
 */
uint8_t caixa_troco_existe_troco(dinheiro_t quantia);

/**
 * @memberof "Caixa Troco"
 * @brief Libera uma quantia de dinheiro correspondente ao troco da compra
 *
 * @param troco Quantia a ser emitida
 * @return 0 se operação for bem sucedida, 1 caso contrário
 */
uint8_t caixa_troco_emite_troco(dinheiro_t troco);

/**
 * @memberof "Caixa Troco"
 * @brief Acrescenta uma quantia de dinheiro ao troco disponível
 *
 * @param quantia Quantidade de dinheiro a ser inserido
 * @return 0 se operação for bem sucedida, 1 caso contrário
 */
uint8_t caixa_troco_insere_troco(dinheiro_t quantia);

#endif // __CAIXA_TROCO_H__
