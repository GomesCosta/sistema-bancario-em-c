#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "conta.h"
#include "operacoes.h"

int main()
{
    int opcao;
    srand(time(NULL));

    do
    {
        printf("\n=== BANCO VIDA ===\n");
        printf("1 - Criar conta\n");
        printf("2 - Depositar\n");
        printf("3 - Sacar\n");
        printf("4 - Atualizar dados da conta\n");
        printf("5 - Listar contas\n");
        printf("6 - Depositar na Poupança\n");
        printf("7 - Sacar da Poupança\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
            case 1:
                cadastro_de_contas();
                break;

            case 2:
                adicionar_saldo();
                break;

            case 3:
            {
                int numero_conta;
                int senha;
                int posicao;

                printf("Digite o numero da conta: ");
                scanf("%d", &numero_conta);

                posicao = busca_conta(numero_conta);

                if (posicao == -1)
                {
                    printf("Conta nao encontrada.\n");
                    break;
                }

                printf("Digite a senha de retirada: ");
                scanf("%d", &senha);

                if (validar_senha_retirada(posicao, senha))
                {
                    realizar_saque(posicao);
                }
                else
                {
                    printf("Saque nao autorizado.\n");
                }

                break;
            }

            case 4:
                atualizar_dados();
                break;

            case 5:
                exibir_cadastros();
                break;

           case 6:
{
    int numero_conta;
    int posicao;

    printf("Digite o numero da conta: ");
    scanf("%d", &numero_conta);

    posicao = busca_conta(numero_conta);

    if (posicao == -1)
    {
        printf("Conta nao encontrada.\n");
        break;
    }

    depositar_na_poupanca(posicao);
    break;
}

case 7:
{
    int numero_conta;
    int posicao;

    printf("Digite o numero da conta: ");
    scanf("%d", &numero_conta);

    posicao = busca_conta(numero_conta);

    if (posicao == -1)
    {
        printf("Conta nao encontrada.\n");
        break;
    }

    retirar_da_poupanca(posicao);
    break;
}

            case 0:
                printf("Encerrando o sistema...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}
