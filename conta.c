#include "conta.h"

struct Conta pessoas[TAM];
int contador = 0;

int buscar_conta(int numero_conta)
{
    for (int i = 0; i < contador; i++)
    {
        if (pessoas[i].numero_conta == numero_conta)
        {
            return i;
        }
    }
    return -1;
}
