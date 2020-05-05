/**
 * @file estoque.h
 * @class Estoque
 * @author Felipe Gomes de Melo <felipegmelo@usp.br>
 * @brief Funções de controle dos dadaos guardados na memória da vending machine
 * @date 04/2020
 * 
 * @copyright MIT License - Copyright (c) 2020
 * 
 */

#ifndef __ESTOQUE_H__
#define __ESTOQUE_H__

#include <stdint.h>

/**
 * @brief Quantidade máxima de produtos que podem ser cadastrados
 */
#define ESTOQUE_TAM 16

/**
 * @brief Tamanho máximo do nome de um produto
 */
#define NOME_TAM 16

/**
 * @brief [errno] Identificador de um espaço na memória alocado mas não inicializado
 */
#define ID_INVALIDO 0xFF

/**
 * @brief [errno] O ID procurado não está cadastrado
 */
#define ID_NAO_ENCONTRADO 0xFE

/**
 * @brief [errno] Não é possível inserir um novo produto
 * pois estoque está cheio
 */
#define ESTOQUE_CHEIO 0xFD

/**
 * @brief [errno] Não é possível inserir um novo produto
 * pois o ID já está cadastrado
 */
#define ID_JA_EXISTE 0xFD

typedef struct{
    uint8_t id;          ///< Identificador do produto
    uint8_t quantidade;  ///< Quantidade de produto existente
    char nome[NOME_TAM]; ///< Identificador legível do produto
}produto_t;

/**
 * @memberof Estoque
 *
 * @brief Variável que guarda os dados do estoque
 * 
 */
static produto_t banco_dados[ESTOQUE_TAM];

/**
 * @memberof Estoque
 *
 * @brief Função de inicialização do estoque com alguns produtos base
 */
void estoque_init();

/**
 * @memberof Estoque
 *
 * @brief Adiciona uma nova entrada no estoque da vending machine
 *
 * @param id Identificador do produto. É o número que será inserido pelo cliente
 * @param quantidade Quantidade de produto inserida
 * @param nome Nome do produto
 *
 * @throw ID_JA_EXISTE se o id inserido já está cadastrado no estoque
 * @throw ESTOQUE_CHEIO se não há mais espaço disponível no estoque
 *
 * @return 0 se bem sucedido, ou o código de erro caso contrário
 */
uint8_t estoque_produto_add(uint8_t id, uint8_t quantidade, char* nome);

/**
 * @memberof Estoque
 * 
 * @brief Imprime na tela uma lista dos produtos cadastrados
 */
void estoque_dump();

/**
 * @memberof Estoque
 *
 * @brief Realiza uma busca no estoque a partir de um id de produto
 *
 * @throw ID_NAO_ENCONTRADO se o id procurado não existe
 *
 * @return Índice do produto no estoque, se o produto existir
 */
uint8_t estoque_index_from_id(uint8_t id);

#endif // __ESTOQUE_H__