#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "struct.h"


void RotacaoD(No *z, No *externo, No **ptRaiz);
void RotacaoE(No *z, No *externo, No **ptRaiz);
void MoverPai(No *u, No *v, No *externo, No **ptRaiz);
void imprimiArvores(No *externo); 
void imprimirOrdem(No *pt, No *externo);
int contaNos(No *pt, No *externo);
bool verificarRN(No *z, No *externo); 
No *buscarNo(No *z, int key, No *externo);  
No *criarNo(int key, No *externo);
No *sucessor(No *z, No *externo); 
No *noExterno();