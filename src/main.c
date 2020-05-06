/**
 * @file main.c
 * @class Machina
 * @author Felipe Gomes de Melo <felipegmelo@usp.br>
 * @brief
 * @date 04/2020
 *
 * @copyright MIT License - Copyright (c) 2020
 *
 */

#include <stdio.h>
#include <stdint.h>
#include "sistema.h"
#include "atuadores.h"
#include "display.h"
#include "teclado.h"
#include "utils.h"
#include "fsm.h"
#include "estoque.h"
#include "boca_caixa.h"
#include "caixa_troco.h"
#include "trava.h"

dinheiro_t troco_inserido;
dinheiro_t entrada;
uint8_t prod_id;

/**
 * @memberof Machina
 *
 * @brief Inicializa componentes da vending machine
 *
 */
void machina_init(){
    fsm_init();
    estoque_init();
    boca_caixa_init();
    atuadores_init();
    display_init();
    teclado_init();
    trava_init();
    caixa_troco_init();
}

fsm_evento_t executar_acao(fsm_acao_t acao){

    uint8_t opcao;
    dinheiro_t troco_emitido;
    switch (acao){
    case MOSTRA_OPCOES:
        display_exibe_msg("\n");
        display_exibe_msg("Digite 1 para ver as opções\n");
        display_exibe_msg("Digite 2 para inserir dinheiro\n");
        display_exibe_msg("Digite 3 para abrir a máquina e entrar no modo de manutenção\n");
        display_exibe_msg("Opção: ");
        scanf("%hhu", &opcao);

        switch (opcao){
        case 1:
            estoque_dump();
            return INICIALIZACAO;
        case 2:
            return COMPRA_INICIADA;
        case 3:
            return MAQUINA_ABERTA;
        default:
            display_exibe_msg("Opção inválida!\n");
            return INICIALIZACAO;

        }

    case PEDE_DINHEIRO:
        display_exibe_msg("Digite quantos reais e quantos centavos você irá inserir\n");
        display_exibe_msg("Reais:    ");

        if(boca_caixa_recebe_notas(&entrada) != OK){
            return FALHA_HARDWARE;
        }

        display_exibe_msg("Centavos: ");

        if(boca_caixa_recebe_moedas(&entrada) != OK){
            return FALHA_HARDWARE;
        }

        display_exibe_msg("=> Quantia recebida: ");
        display_dinheiro(entrada);
        display_exibe_msg("\n");

        return DINHEIRO_INSERIDO;

    case PEDE_PROD_ID:
        display_exibe_msg("Digite o ID do produto (para cancelar digite 00)\n");
        display_exibe_msg("ID: ");

        if(teclado_le_prod_id(&prod_id) != OK){
            return FALHA_HARDWARE;
        }

        return PROD_ID_INSERIDO;

    case CONFERE_COMPRA:
        if(estoque_compra_valida(prod_id, entrada) == OK){
            return COMPRA_VALIDADA;
        }else{
            if(prod_id == 0){
                display_exibe_msg("Compra cancelada pelo usuário!\n");
            }else{
                display_exibe_msg("O dinheiro inserido é insuficiente para compra!\n");
            }
            return COMPRA_CANCELADA;
        }

    case LIBERA_PRODUTO:
        atuadores_libera_produto(prod_id);

        return PRODUTO_LIBERADO;

    case LIBERA_TROCO:
        estoque_calcula_troco(prod_id, entrada, &troco_emitido);
        caixa_troco_emite_troco(troco_emitido);

        return TROCO_LIBERADO;

    case FINALIZA_COMPRA:
        return INICIALIZACAO;

    case CANCELA_COMPRA:
        return INICIALIZACAO;

    case ENTRA_MANUTENCAO:
        display_exibe_msg("Insira a quantia de troco a ser adicionada\n");
        display_exibe_msg("Reais:    ");

        if(boca_caixa_recebe_notas(&troco_inserido) != OK){
            return FALHA_HARDWARE;
        }

        display_exibe_msg("Centavos: ");

        if(boca_caixa_recebe_moedas(&troco_inserido) != OK){
            return FALHA_HARDWARE;
        }

        if(troco_inserido.reais != 0 || troco_inserido.centavos != 0){
            display_exibe_msg("=> Troco recebido: ");
            display_dinheiro(troco_inserido);
            display_exibe_msg("\n");
            return TROCO_INSERIDO;
        }else{
            return MAQUINA_FECHADA;
        }

    case ATUALIZA_TROCO:
        caixa_troco_insere_troco(&troco_inserido);
        return MAQUINA_ABERTA;

    case SAI_MANUTENCAO:
        return MAQUINA_FECHADA;
    }

    return 0;
}

int main() {

    fsm_acao_t codigo_acao;
    fsm_estado_t estado;
    fsm_evento_t codigo_evento;
    fsm_evento_t evento_interno;

    estado = INICIO;
    evento_interno = INICIALIZACAO;

    machina_init();
    printf ("Vending machine ligada!\n");
    estoque_dump();
    while (true) {
        if (codigo_evento != NENHUM_EVENTO){
            codigo_acao = fsm_obter_acao(estado, codigo_evento);
            estado = fsm_obter_proximo_estado(estado, codigo_evento);
            codigo_evento = executar_acao(codigo_acao);
        }else{
            codigo_evento = INICIALIZACAO;
        }
    } // while true
} // main
