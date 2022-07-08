#include <stdio.h>
#include <stdlib.h>
#include "struct.h"


void RotacaoD(No *z, No *externo, No **ptRaiz);
void RotacaoE(No *z, No *externo, No **ptRaiz);
void Moverpai(No **u, No **v, No *externo, No **ptRaiz);
void imprimiArvores(No *pt, No *externo); 
void imprimirOrdem(No *pt, No *externo);
int contaNos(No *pt, No *externo);
No *buscarNo(No *z, int key, No *externo);  
No *criarNo(int key, No *externo);
No *sucessor(No *z, No* externo); 
No *noExterno();