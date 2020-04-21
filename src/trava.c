/**
 * @file trava.c
 * @author Felipe Gomes de Melo <felipegmelo@usp.br>
 * @brief Métodos de interface com a trava de manutenção da vending machine
 * @date 04/2020
 *
 * @copyright MIT License - Copyright (c) 2020
 *
 */

#include "trava.h"

static bool trava_aberta;

void trava_init() {
    trava_aberta = false;
}
