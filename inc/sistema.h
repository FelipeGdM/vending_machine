#ifndef DEFINICOES_SISTEMA_H_INCLUDED
#define DEFINICOES_SISTEMA_H_INCLUDED

#define true  1
#define false 0

#include <stdint.h>

#define OK 0
#define FALHA_HARDWARE 1

typedef struct{
    uint8_t reais;
    uint8_t centavos;
}dinheiro_t;

#endif // DEFINICOES_SISTEMA_H_INCLUDED
