#ifndef OPERACOES_H
#define OPERACOES_H

/// FUNÇÕES__MANIPULAMENTO_DE_INFORMAÇÕES
void cadastro_de_contas();
void atualizar_dados();


/// FUNÇÃO__CONTROLE_DE_INFORMAÇÕES
void exibir_cadastros();
int busca_conta(int numero_conta);


/// FUNÇÃO__CONTROLE_DE_SENHAS
int validar_senha_acesso(int posicao, int senha);
int validar_senha_retirada(int posicao, int senha);


/// FUNÇÃO__CONTROLE_DE_VALORES
void adicionar_saldo();
void realizar_saque(int posicao);


/// FUNÇÃO__CONTROLE_DA_POUPANÇA
void depositar_na_poupanca(int posicao);
void retirar_da_poupanca(int posicao);

#endif
