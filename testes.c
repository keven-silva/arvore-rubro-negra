#include "testes.h"


void testeBaseInserir(No *externo)
{
    int i, j;
    int list[] = { 11, 2, 14, 1, 7, 3, 15, 5, 8, 4, 121, 213, 13, 50, 48, 51, 21, 56, 18, 16, 17, 172, 112, 120, 121, 128, 29, 564, 105, 1858, 
    20, 28, 6, 10, 12, 19, 335, 336, 332, 330, 301, 230, 450, 563, 452, 422, 453, 458, 251, 198, 197, 192, 198, 185, 173, 25, 27, 82, 46, 47,
    118, 1111, 2222, 489, 562, 11112, 1775, 4652, 76512, 110, 601, 128, 451, 471, 473, 476, 474, 547, 548, 521, 71, 79, 78, 72, 22, 33, 44, 
    365, 4210,652, 5662, 6601, 55456, 4512, 8548, 7162, 4205, 1655, 131, 6532};
    
    ptRaiz = (No**)malloc(sizeof(No*) * QTD_ARVORES);

    for (i = 0; i < QTD_ARVORES; i++) {
        ptRaiz[i] = externo;    
    }

    for(i = 0; i < QTD_ARVORES; i++) 
    { 
        for ( j = 0; j < (sizeof(list) / sizeof(list[0])); j++)
        {
            No *z = criarNo(list[j], externo);
            InserirRN(z, externo, &(ptRaiz[i]));
        }

        int count = contaNos(ptRaiz[i], externo);
        printf("\nQTD: %d\n", count);
        
        imprimirOrdem(ptRaiz[i], externo);
        printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    }	
}


void testeBaseRemover(No *externo)
{
    int i, j;
    int list[] = {13, 14, 11, 21, 19, 6532, 6601, 453, 198, 29};
    
    for(i = 0; i < QTD_ARVORES; i++) 
    { 
        for ( j = 0; j < (sizeof(list) / sizeof(list[0])); j++)
        {
            No *z = buscarNo(ptRaiz[i], list[j], externo);
            RemoverRN(z, externo, &(ptRaiz[i]));

        }

        int count = contaNos(ptRaiz[i], externo);
        printf("QTD: %d\n", count);
        
        imprimirOrdem(ptRaiz[i], externo);
    }
}


void testeDeInsercao(No *externo) 
{
    int i;

    ptRaiz = (No**)malloc(sizeof(No*) * QTD_ARVORES);

    for (i = 0; i < QTD_ARVORES; i++) {
        ptRaiz[i] = externo;    
    }
    
    for(i = 0; i < QTD_ARVORES; i++) 
    {
        int nos = 0;

        while (nos < QTD_NOS) 
        {
            int key =(rand() * (rand() % RAND_MAX)) % RAND_LIMITE;
            No *z = criarNo(key, externo);
            InserirRN(z, externo, &(ptRaiz[i]));
            nos = contaNos(ptRaiz[i], externo);
        }

        // imprimirOrdem(ptRaiz[i], externo);
        printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    }
}


void testeDeRemocao(No *externo) 
{
    int i;
    int nos; 
    for(i = 0; i < QTD_ARVORES; i++) 
    { 
        nos = QTD_NOS;

        while (nos > (QTD_NOS - QTD_REMOCOES)) 
        {
            int key = (rand() * (rand() % RAND_MAX)) % RAND_LIMITE;
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