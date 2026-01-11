#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "conta.h"
#include "operacoes.h"

/* ===================== CADASTRO ===================== */

void cadastro_de_contas()
{
    if (contador >= TAM)
    {
        printf("\nCAPACIDADE MAXIMA ATINGIDA!\n");
        return;
    }

    printf("\n--- CADASTRO DA CONTA ---\n");

    printf("Nome do titular: ");
    getchar(); // limpa buffer
    fgets(pessoas[contador].titular, sizeof(pessoas[contador].titular), stdin);
    pessoas[contador].titular[strcspn(pessoas[contador].titular, "\n")] = '\0';

    printf("Crie sua senha de acesso (8 numeros): ");
    scanf("%d", &pessoas[contador].senha_acesso);

    printf("Crie sua senha de retirada (4 numeros): ");
    scanf("%d", &pessoas[contador].senha_retirada);

    pessoas[contador].numero_conta = 10000 + rand() % 90000;
    pessoas[contador].valor = 0;

    pessoas[contador].valor = 0;
    pessoas[contador].poupanca = 0;


    printf("\nConta criada com sucesso!\n");
    printf("Numero da conta: %d\n", pessoas[contador].numero_conta);

    contador++;
}

/* ===================== BUSCA ===================== */

int busca_conta(int numero_conta)
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

/* ===================== DEPÓSITO ===================== */

void adicionar_saldo()
{
    int numero_conta;
    float valor_deposito;

    if (contador == 0)
    {
        printf("\nNenhuma conta cadastrada.\n");
        return;
    }

    printf("\nDigite o numero da conta: ");
    scanf("%d", &numero_conta);

    int posicao = busca_conta(numero_conta);

    if (posicao == -1)
    {
        printf("Conta nao encontrada!\n");
        return;
    }

    printf("Digite o valor do deposito: ");
    scanf("%f", &valor_deposito);

    if (valor_deposito <= 0)
    {
        printf("Valor invalido.\n");
        return;
    }

    pessoas[posicao].valor += valor_deposito;

    printf("\nDeposito realizado com sucesso!\n");
    printf("Saldo atual: %.2f\n", pessoas[posicao].valor);
}

/* ===================== EXIBIR ===================== */

void exibir_cadastros()
{
    if (contador == 0)
    {
        printf("\nNenhum cliente cadastrado.\n");
        return;
    }

    printf("\n---- CLIENTES CADASTRADOS ----\n");

    for (int i = 0; i < contador; i++)
    {
        printf("\nTitular: %s", pessoas[i].titular);
        printf("\nNumero da conta: %d", pessoas[i].numero_conta);
        printf("\nSaldo corrente: %.2f", pessoas[i].valor);
        printf("\nSaldo poupanca: %.2f\n", pessoas[i].poupanca);

    }
}

/* ===================== ATUALIZAÇÃO ===================== */

void atualizar_dados()
{
    int numero_conta, opcao, senha;

    printf("Digite o numero da conta: ");
    scanf("%d", &numero_conta);

    int posicao = busca_conta(numero_conta);

    if (posicao == -1)
    {
        printf("Conta nao encontrada.\n");
        return;
    }

    printf("Digite a senha de acesso: ");
    scanf("%d", &senha);

    if (!validar_senha_acesso(posicao, senha))
    {
        printf("Senha incorreta!\n");
        return;
    }

    printf("\n--- ATUALIZACAO ---\n");
    printf("1 - Nome do titular\n");
    printf("2 - Senha de acesso\n");
    printf("3 - Senha de retirada\n");
    printf("0 - Voltar\n");
    printf("Escolha: ");
    scanf("%d", &opcao);
    getchar();

    switch (opcao)
    {
        case 1:
            printf("Novo nome: ");
            fgets(pessoas[posicao].titular, sizeof(pessoas[posicao].titular), stdin);
            pessoas[posicao].titular[strcspn(pessoas[posicao].titular, "\n")] = '\0';
            printf("Nome atualizado com sucesso!\n");
            break;

        case 2:
            printf("Nova senha de acesso: ");
            scanf("%d", &pessoas[posicao].senha_acesso);
            printf("Senha de acesso atualizada!\n");
            break;

        case 3:
            printf("Nova senha de retirada: ");
            scanf("%d", &pessoas[posicao].senha_retirada);
            printf("Senha de retirada atualizada!\n");
            break;

        case 0:
            printf("Voltando ao menu...\n");
            break;

        default:
            printf("Opcao invalida.\n");
    }
}

/* ===================== VALIDAÇÃO ===================== */

int validar_senha_acesso(int posicao, int senha)
{
    return pessoas[posicao].senha_acesso == senha;
}

int validar_senha_retirada(int posicao, int senha)
{
    return pessoas[posicao].senha_retirada == senha;
}

/* ===================== SAQUE ===================== */

void realizar_saque(int posicao)
{
    float valor;

    printf("Digite o valor do saque: ");
    scanf("%f", &valor);

    if (valor <= 0)
    {
        printf("Valor invalido.\n");
        return;
    }

    if (pessoas[posicao].valor < valor)
    {
        printf("Saldo insuficiente.\n");
        return;
    }

    pessoas[posicao].valor -= valor;

    printf("Saque realizado com sucesso!\n");
    printf("Saldo atual: %.2f\n", pessoas[posicao].valor);
}

void depositar_na_poupanca(int posicao)
{

    float valor;
    printf("Insira o valor do deposito :");
    scanf("%f",&valor);

    if (valor <= 0 )
    {
        printf("Valor invalido ! \n");
        return;
    }
    else
    {
        pessoas[posicao].poupanca = pessoas[posicao].poupanca  + valor;
        printf("Operação realizada com sucesso !\n");
    }
}

void retirar_da_poupanca(int posicao)
{
    float valor;
    int senha;

    printf("Digite a senha de retirada: ");
    scanf("%d", &senha);

    if (!validar_senha_retirada(posicao, senha))
    {
        printf("Senha incorreta!\n");
        return;
    }

    printf("Insira o valor que deseja retirar: ");
    scanf("%f", &valor);

    if (valor <= 0)
    {
        printf("Valor invalido!\n");
        return;
    }

    if (valor > pessoas[posicao].poupanca)
    {
        printf("Saldo insuficiente na poupanca!\n");
        return;
    }

    
    pessoas[posicao].poupanca -= valor;

    printf("Saque da poupanca realizado com sucesso!\n");
    printf("Saldo da poupanca: %.2f\n", pessoas[posicao].poupanca);
}


