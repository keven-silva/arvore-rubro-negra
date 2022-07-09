#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "util.h"
#include "inserir.h"
#include "remover.h"

#define QTD_ARVORES 5 // Quantidade de arvores
#define QTD_NOS 5// Quantiadde de nos em cada arvore
#define QTD_REMOCOES 2 // Quantidade de remocoes
#define RAND_LIMITE 10 // Valor para limitar o rand()


void testeBaseInserir(No *externo);
void testeBaseRemover(No *externo);

void testeDeInsercao(No *externo);
void testeDeRemocao(No *externo);