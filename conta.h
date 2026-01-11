#ifndef CONTA_H
#define CONTA_H

#define TAM 100

struct Conta
{
    char titular[50];
    int numero_conta;
    float valor;
    int senha_acesso;
    int senha_retirada;
    float poupanca ;
};

extern struct Conta pessoas[TAM];
extern int contador;



#endif
