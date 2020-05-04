#ifndef DEFINICOES_SISTEMA_H_INCLUDED
#define DEFINICOES_SISTEMA_H_INCLUDED

// #define true  1
// #define false 0

#include <stdint.h>

/**
 * @brief Lista de estados possíveis para a FSM do controlador
 */
typedef enum{
    INICIO,
    AGUARDA_PROD_ID,    ///< Máquina aguarda código do produto
    LIBERA_PRODUTO,     ///< Máquina irá liberar o produto
    LIBERA_TROCO,       ///< Máquina irá liberar o troco
    COMPRA_CANCELADA,   ///< Máquina irá cancelar a compra e retornar ao início
    MANUTENCAO,         ///< Estado de manutenção da máquina
    ATUALIZA_TROCO,
    ULTIMO_ESTADO
} estado_t;

/**
 * @brief Lista de eventos possíveis
 */
typedef enum{
    NENHUM_EVENTO = -1,
    INSERIR_DINHEIRO,   ///< Cliente inseriu dinheiro na máquina
    INSERIR_PROD_ID,    ///< Cliente inseriu código do produto
    CANCELAR_COMPRA,    ///< Cliente cancelou a compra
    LIBERAR_PRODUTO,    ///< Máquina liberou produto
    LIBERAR_TROCO,      ///< Máquina liberou troco
    ABRIR_MAQUINA,      ///< Repositor abriu a máquina para manutenção
    FECHAR_MAQUINA,     ///< Repositor fechou a máquina
    INSERIR_TROCO,      ///< Repositor inseriu dinheiro na caixa de troco
    ULTIMO_EVENTO
} evento_t;

/**
 * @brief Lista de ações de transição de estado
 */
#define NENHUMA_ACAO -1
#define A01  0
#define A02  1
#define A03  2
#define A04  3
#define A05  4
#define A06  5
#define A07  6

/**
 * @brief Quantidade de estados existente
 */
#define NUM_ESTADOS ((int) ULTIMO_ESTADO)

/**
 * @brief Quantidade de estados existente
 */
#define NUM_EVENTOS ((int) ULTIMO_EVENTO)

typedef struct{
    uint8_t reais;
    uint8_t centavos;
}dinheiro_t;

#endif // DEFINICOES_SISTEMA_H_INCLUDED
