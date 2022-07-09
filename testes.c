#include "testes.h"


int main(){
    No *externo = noExterno();

    // printf("\nTeste base de insercao\n");
    // testeBaseInserir(externo);
    // printf("---------------------------------------------------------------");
    // printf("\nTeste base de remocao\n");
    // testeBaseRemover(externo);
    printf("\nTeste de insercao\n");
    testeDeInsercao(externo);
    imprimiArvores(externo);
    printf("---------------------------------------------------------------");
    printf("\nTeste de remocao\n");
    testeDeRemocao(externo);
    imprimiArvores(externo);

    return 0;
}


void testeBaseInserir(No *externo)
{
    int i;
    int list[] = { 11, 2, 14, 1, 7, 15, 5, 8, 4};
    
    ptRaiz = (No**)malloc(sizeof(No*) * sizeof(list));    
    ptRaiz[0] = externo;    

    for ( i = 0; i < (sizeof(list) / sizeof(list[0])); i++)
    {
        No *z = criarNo(list[i], externo);
        InserirRN(z, externo, &(ptRaiz[0]));
    }

    int count = contaNos(ptRaiz[0], externo);
    printf("\nQTD: %d\n", count);
    
    imprimirOrdem(ptRaiz[0], externo);
}


void testeBaseRemover(No *externo)
{
    int i;
    int list[] = {11, 4};
    

    for ( i = 0; i < (sizeof(list) / sizeof(list[0])); i++)
    {
        No *z = buscarNo(ptRaiz[0], list[i], externo);
        RemoverRN(z, externo, &(ptRaiz[0]));

    }

    int count = contaNos(ptRaiz[0], externo);
    printf("QTD: %d\n", count);
    
    imprimirOrdem(ptRaiz[0], externo);
}


// Prepara as arvores a serem criadas
void testeDeInsercao(No *externo) 
{
    int i;

    // alocando memória para as raizes
    ptRaiz = (No**)malloc(sizeof(No*) * QTD_ARVORES);
    // Inicializando cada raiz para apontar para NULL
    for (i = 0; i < QTD_ARVORES; i++) {
        ptRaiz[i] = externo;    
    }
    
    // Inserindo a quantidade definida de nós em cada árvore
    for(i = 0; i < QTD_ARVORES; i++) 
    {
        int nos = 0;

        // Enquanto nao ocorrerem as N insercoes, o laco continua
        while (nos < QTD_NOS) 
        {
            int key = rand() % RAND_LIMITE;
            No *z = criarNo(key, externo);
            InserirRN(z, externo, &(ptRaiz[i]));
            nos = contaNos(ptRaiz[i], externo);
        }
    }
}


// Procedimento que realiza as remocoes exigidas
void testeDeRemocao(No *externo) 
{
    int i;
    int nos; // contador
    for(i = 0; i < QTD_ARVORES; i++) { 
     // Variavel para o resultado de alteracao de altura
        nos = QTD_NOS; // contador

        // Enquanto nao ocorrerem as N remocoes, o laco continua
        while (nos > (QTD_NOS - QTD_REMOCOES)) {
            int key = rand() % RAND_LIMITE;
            No *z = buscarNo(ptRaiz[i], key, externo);
            
            if (z->chave != 0) 
            {
                RemoverRN(z, externo, &(ptRaiz[i]));
                nos = contaNos(ptRaiz[i], externo);    
            }else
            {
                printf("Chave: %d, não existe na arvore: %d\n", z->chave, i);
            }
                        
        }
    }
}