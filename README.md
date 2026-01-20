# Simulador de gerenciamento de cinema
- Projeto feito na cadeira de introdução a programção 1 para praticar a linguagem C
- A ideia do projeto e facilitar a gestão de uma sala de cinema.

# Funcionalidades
- Disponibilizar reservas de assentos (podendo ser ingressos meia entrada ou inteira).
- Mostrar os assentos disponiveis.
- Imprimir o valor arrecadado pela sala.
- Mostrar a quantia de ingressos meia e inteira.
- Salvar como arquivo a quantidade de ingressos, o valor arrecadado e o mapa de assentos da sala.
- Ler arquivos que foram criados previamente pelo programa, atualizando os dados atuais;
  
## Observação
- Defini a sala como tendo 10 fileiras e 10 colunas de assentos, porém isso pode ser facilmente ajustado.
- Também defini o valor do ingresso meia entrada como 7.5, e a inteira como 15, mas isso também pode ser alterado. 
- Coloquei um nome e genêro generico para o filme, o que pode ser modificado.

---

## Como rodar o projeto

### 🔹 Opção 1 — Usuário final (Windows)

Se você **apenas deseja executar o programa**, sem modificar o código:

1. Baixe o arquivo executável:
- gerenciador.exe
2. Execute:
- com **duplo clique**, ou
- pelo terminal:
```bash
  ./gerenciador.exe
```
 Não é necessário instalar compilador, VS Code ou dependências.
 
### 🔹 Opção 2 — Compilar a partir do código (desenvolvedores)

Indicada para quem deseja **estudar, modificar ou evoluir o projeto**.

#### Requisitos
- GCC  
- make
- Windows (MSYS2/MinGW), Linux ou macOS

#### Compilação
Na pasta raiz do projeto, execute:

```bash
  make
  make run
```
