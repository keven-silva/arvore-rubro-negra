#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "util.h"
#include "inserir.h"
#include "remover.h"

#define QTD_ARVORES 1000 // Quantidade de arvores
#define QTD_NOS 10000// Quantiadde de nos em cada arvore
#define QTD_REMOCOES 1000 // Quantidade de remocoes
#define RAND_LIMITE 100000 // Valor para limitar o rand()


void testeBaseInserir();
void testeBaseRemover();

void testeDeInsercao();
void testeDeRemocao();