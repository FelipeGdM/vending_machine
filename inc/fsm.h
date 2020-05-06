/**
 * @file fsm.h
 * @class FSM
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

/**
 * @memberof FSM
 *
 * @brief Lista de estados possíveis para a FSM do controlador
 */
typedef enum{
    INICIO,
    AGUARDA_DINHEIRO,       ///< Máquina aguarda código do produto
    AGUARDA_PROD_ID,        ///< Máquina aguarda código do produto
    VALIDACAO_COMPRA,       ///< Máquina confere se a combinação de id e dinheiro é válida
    LIBERACAO_PRODUTO,      ///< Máquina irá liberar o produto
    LIBERACAO_TROCO,        ///< Máquina irá liberar o troco
    CANCELAMENTO_COMPRA,    ///< Máquina irá cancelar a compra e retornar ao início
    MANUTENCAO,             ///< Estado de manutenção da máquina
    ATUALIZACAO_TROCO,
    ULTIMO_ESTADO
} fsm_estado_t;

/**
 * @memberof FSM
 *
 * @brief Lista de eventos possíveis
 */
typedef enum{
    NENHUM_EVENTO = -1,
    INICIALIZACAO,
    COMPRA_INICIADA,     ///< Cliente escolheu iniciar a compra
    DINHEIRO_INSERIDO,   ///< Cliente inseriu dinheiro na máquina
    PROD_ID_INSERIDO,    ///< Cliente inseriu código do produto
    COMPRA_VALIDADA,     ///< Cliente cancelou a compra
    COMPRA_CANCELADA,    ///< Cliente cancelou a compra
    PRODUTO_LIBERADO,    ///< Máquina liberou produto
    TROCO_LIBERADO,      ///< Máquina liberou troco
    MAQUINA_ABERTA,      ///< Repositor abriu a máquina para manutenção
    MAQUINA_FECHADA,     ///< Repositor fechou a máquina
    TROCO_INSERIDO,      ///< Repositor inseriu dinheiro na caixa de troco
    ULTIMO_EVENTO
} fsm_evento_t;

/**
 * @memberof FSM
 *
 * @brief Lista de ações de transição de estado
 */
typedef enum{
    NENHUMA_ACAO = -1,
    MOSTRA_OPCOES,      ///< Ação inicial, não utilizada em uma máquina física
    PEDE_DINHEIRO,      ///< Pede ao cliente inserir o dinheiro necessário
    PEDE_PROD_ID,       ///< Pede ao cliente inserir o código do produto
    CONFERE_COMPRA,     ///< Executa verificação da validade da compra
    LIBERA_PRODUTO,     ///< Libera o produto pedido
    LIBERA_TROCO,       ///< Libera o troco necessário
    FINALIZA_COMPRA,    ///< Finaliza a compra e retorna ao estado inicial
    CANCELA_COMPRA,     ///< Cancela a compra e retorna ao estado inicial
    ENTRA_MANUTENCAO,   ///< Entra no estado de manutenção
    ATUALIZA_TROCO,     ///< Atualiza a informação de troco disponível
    SAI_MANUTENCAO,     ///< Sai do estado de manutenção
    ULTIMA_ACAO
} fsm_acao_t;

/**
 * @brief Quantidade de estados existentes
 */
#define NUM_ESTADOS ((int) ULTIMO_ESTADO)

/**
 * @brief Quantidade de eventos existentes
 */
#define NUM_EVENTOS ((int) ULTIMO_EVENTO)

/**
 * @brief Quantidade de ações existentes
 */
#define NUM_ACOES ((int) ULTIMA_ACAO)

/**
 * @memberof FSM
 *
 * @brief Função de inicialização da máquina de estados
 *
 */
void fsm_init();

/**
 * @memberof FSM
 *
 * @brief Retorna qual ação deve ser executada a partir de um estado e um evento
 *
 * @param estado Estado atual
 * @param codigo_evento Evento ocorrido
 * @return Ação a ser executada
 */
fsm_acao_t fsm_obter_acao(fsm_estado_t estado, fsm_evento_t codigo_evento);

/**
 * @memberof FSM
 *
 * @brief Retorna qual o próximo estado a partir do estado atual e um evento
 *
 * @param estado Estado atual
 * @param codigo_evento Evento ocorrido
 * @return Ação a ser executada
 */
fsm_estado_t fsm_obter_proximo_estado(fsm_estado_t estado, fsm_evento_t codigo_evento);

#endif // __FSM_H__
