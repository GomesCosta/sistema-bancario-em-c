# 🏦 Sistema Bancário em C

## 📌 Sobre o Projeto

Este projeto é um Sistema Bancário simples, desenvolvido em linguagem C , com finalidade educacional e acadêmica. Ele representa um MVP (Produto Mínimo Viável), criado para consolidar conceitos fundamentais de programação estruturada, organização em módulos e lógica computacional.

O sistema simula operações bancárias básicas e foi projetado para permitir evolução gradual, servindo como base para versões mais robustas no futuro.

---

## 🎯 Objetivos

- Praticar lógica de programação em C
- Aplicar o uso de `struct` para modelagem de dados
- Trabalhar com funções e modularização do código
- Simular operações bancárias reais de forma simples
- Construir um projeto organizado e escalável

---

## 🛠️ Tecnologias Utilizadas

- Linguagem C
- Compilador GCC
- Programação estruturada

---

## 📂 Estrutura do Projeto

```text
/banco-vida
├── main.c            # Controle do sistema e menu principal
├── conta.c           # Implementação das funções relacionadas à conta
├── conta.h           # Definição da estrutura Conta
├── operacoes.c       # Operações bancárias (saque, depósito, etc.)
├── operacoes.h       # Protótipos das operações bancárias
├── docs/
│   └── documentacao-tecnica.md  # Documentação detalhada do sistema
├── README.md
```

---

## ⚙️ Funcionalidades

- Criação de conta bancária
- Depósito de valores
- Saque com validação de saldo disponível
- Atualização de dados do cliente
- Menu interativo em modo texto

---

## ▶️ Como Compilar e Executar

### Compilação

```bash
gcc main.c conta.c operacoes.c -o banco
```

### Execução

```bash
./banco
```

---

## 📘 Documentação Técnica

A documentação técnica completa do projeto está disponível no diretório:

```text
docs/documentacao-tecnica.md
```
Ela contém:
- Arquitetura do sistema
- Estruturas de dados utilizadas
- Regras de negócio
- Fluxo de execução do programa
- Documentação detalhada das funções

---

## 🚀 Possíveis Evoluções

- Persistência de dados em arquivos (`.txt` ou `.dat`)
- Sistema de autenticação com senha
- Extrato bancário
- Suporte a múltiplas contas
- Interface gráfica
- Integração com banco de dados

---

## 👨‍💻 Autor

## Gabriel Ítalo

---

## 📄 Licença

Projeto de uso educacional, livre para estudo, modificação e aprimoramento.


