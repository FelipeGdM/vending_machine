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
#include "sistema.h"
#include "atuadores.h"
#include "display.h"
#include "teclado.h"
#include "utils.h"
#include "fsm.h"
#include "estoque.h"
#include "boca_caixa.h"
#include "trava.h"

/**
 * @memberof Machina
 *
 * @brief Inicializa componentes da vending machine
 *
 */
void machina_init(){
    fsm_init();
    boca_caixa_init();
    atuadores_init();
    display_init();
    teclado_init();
    trava_init();
}

int obter_evento(){
    return NENHUM_EVENTO;
    // int retval = NENHUM_EVENTO;

    // teclas = ihm_obterTeclas();
    // if (decodificarAcionar())
    //     return ACIONAR;
    // if (decodificarDesacionar())
    //     return DESACIONAR;
    // if (decodificarTimeout())
    //     return TIMEOUT;
    // if (decodificarDisparar())
    //     return DISPARAR;

    // return retval;
} // obter_evento


int main() {

    acao_t codigo_acao;
    estado_t estado;
    evento_t codigo_evento;
    evento_t evento_interno;

    estado = INICIO;
    evento_interno = NENHUM_EVENTO;

    machina_init();
    printf ("Vending machine ligada!\n");
    while (true) {
        if (evento_interno == NENHUM_EVENTO) {
            codigo_evento = obter_evento();
        } else {
            codigo_evento = evento_interno;
        }
        if (codigo_evento != NENHUM_EVENTO)        {
            codigo_acao = fsm_obter_acao(estado, codigo_evento);
            estado = fsm_obter_proximo_estado(estado, codigo_evento);
            // evento_interno = executarAcao(codigo_acao);
            printf("Estado: %d Evento: %d Acao:%d\n", estado, codigo_evento, codigo_acao);
        }
    } // while true
} // main
