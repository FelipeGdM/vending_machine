/**
 * @file estoque.h
 * @class Estoque
 * @author Felipe Gomes de Melo <felipegmelo@usp.br>
 * @brief 
 * @date 04/2020
 * 
 * @copyright MIT License - Copyright (c) 2020
 * 
 */

#include "estoque.h"
#include "sistema.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h>

static produto_t banco_dados[ESTOQUE_TAM];

void estoque_init(){

    for(uint8_t i = 0; i < ESTOQUE_TAM; i++){
        banco_dados[i].id = ID_INVALIDO;
    }

    estoque_produto_add(1, 100, "Amendoim");
    estoque_produto_add(2, 1500, "Fone de ouvido");
    estoque_produto_add(4, 150, "Batata");
    estoque_produto_add(5, 200, "Laranja");

};

uint8_t estoque_encontra_pos_livre(){
    for(uint8_t i = 0; i < ESTOQUE_TAM; i++){
        if(banco_dados[i].id == ID_INVALIDO)
            return i;
    }

    return ESTOQUE_CHEIO;
}

uint8_t estoque_produto_add(uint8_t id, uint16_t preco, char* nome){

    uint8_t index = estoque_encontra_pos_livre();

    if(index == ESTOQUE_CHEIO)
        return ESTOQUE_CHEIO;

    // Só insere o produto se o id fornecido ainda não existe
    if(estoque_index_from_id(id) == ID_NAO_ENCONTRADO){
        banco_dados[index].id = id;
        banco_dados[index].preco = preco;
        memcpy(banco_dados[index].nome, nome, NOME_TAM);
    }else{
        return ID_JA_EXISTE;
    }

    return 0;
};

void estoque_dump(){

    printf(" ID\t | Qtde\t\t | Nome\t \n");
    for(uint8_t i = 0; i < 40; i++)
        printf("-");
    printf("\n");

    for(uint8_t i = 0; i < ESTOQUE_TAM; i++){
        if(banco_dados[i].id != ID_INVALIDO){
            printf("%02hhu\t | R$ %u.%02u\t | %s\n",
                banco_dados[i].id, banco_dados[i].preco/100, banco_dados[i].preco % 100,
                banco_dados[i].nome);
        }
    }
};

uint8_t estoque_index_from_id(uint8_t id){
    for(uint8_t i = 0; i < ESTOQUE_TAM; i++){
        if(banco_dados[i].id == id)
            return i;
    }

    return ID_NAO_ENCONTRADO;
};


uint8_t estoque_compra_valida(uint8_t id, dinheiro_t entrada){

    uint8_t index = estoque_index_from_id(id);
    if(index == ID_NAO_ENCONTRADO)
        return ID_NAO_ENCONTRADO;

    if(entrada.reais*100 + entrada.centavos >= banco_dados[index].preco)
        return OK;

    return DINHEIRO_INSUFICIENTE;
}

uint8_t estoque_calcula_troco(uint8_t id, dinheiro_t entrada, dinheiro_t* troco){

    uint8_t index = estoque_index_from_id(id);
    if(index == ID_NAO_ENCONTRADO)
        return ID_NAO_ENCONTRADO;

    if(entrada.centavos < banco_dados[index].preco % 100){
        entrada.centavos += 100;
        entrada.reais--;
    }

    troco->centavos = entrada.centavos - banco_dados[index].preco % 100;
    troco->reais = entrada.reais - banco_dados[index].preco / 100;

    return OK;
}
