#include <stdio.h>

#define N 6

/*
Nome: Protocolo de Criptografia CriptoML 

Versão: 1.0

Descrição: 
Recebe um array em hexadecimal, soma 5 aos índices pares e subtrai 3 dos índices ímpares
Há, também, a implementação da função para descriptografar.

Data: 06NOV2021

Autor: Ygor Moreira Lima

Site: ygorml.org
*/

/* Protótipo das funções */ 
int criptografaArray(array[]);
int descriptografaArray(array[]);
int imprimeArray(array[], char tipo);

/* Função main */ 
void main () {

    int payload[N] = {0xA0,0x73,0x25,0xD3,0xCA,0xFE};
    int criptografado[N] = {0xA5, 0x70, 0x2A, 0xD0, 0xCF, 0xFB};

    descriptografaArray(criptografado);
    return;

}

/* Desenvolvimento das funções */

int criptografaArray(int array[]) {

    int vetorCriptografado[N] = {};
    
    for (int i=0;i<N;i++) {
        if(i%2 == 0) {
            vetorCriptografado[i] = array[i] + 5;
        } else {
            vetorCriptografado[i] = array[i] - 3;
        }
    }

    imprimeArray(vetorCriptografado, 'c');

}

int descriptografaArray(int array[]) {

    int vetorDescriptografado[N] = {};

    for (int i=0;i<N;i++) {
        if(i%2 == 0) {
            vetorDescriptografado[i] = array[i] - 5;
        } else {
            vetorDescriptografado[i] = array[i] + 3;
        }
    }

    imprimeArray(vetorDescriptografado, 'd');

}

int imprimeArray(int arrayImprime[], char tipo) {

    if(tipo == 'c') {
        printf("Array Criptografado: \n");
    } else if(tipo == 'd') {
        printf("Array Descriptografado: \n");
    }

    for(int i=0;i<N;i++) {
        printf(" %X", arrayImprime[i]);
    }

}
