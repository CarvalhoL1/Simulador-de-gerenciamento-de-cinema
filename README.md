# Simulador de gerenciamento de cinema
- Projeto feito na cadeira de introdução a programção 1 para praticar a linguagem C
- O sistema simula a **gestão de uma sala de cinema**, permitindo reservar assentos, controlar vendas de ingressos e salvar/recuperar dados entre execuções.


# Funcionalidades
- Reserva de assentos na sala de cinema  
- Opção de ingresso **meia entrada** ou **inteira**  
- Visualização do mapa de assentos (disponíveis e ocupados)  
- Exibição do **valor total arrecadado**  
- Contagem de ingressos vendidos (meia e inteira)  
- Salvamento de dados em arquivo:
  - mapa de assentos
  - quantidade de ingressos
  - valor arrecadado
- Leitura de arquivos salvos anteriormente, restaurando o estado da sala

## Observação
- Defini a sala como tendo 10 fileiras e 10 colunas de assentos, porém isso pode ser facilmente ajustado.
- Também defini o valor do ingresso meia entrada como 7.5, e a inteira como 15, mas isso também pode ser alterado. 
- Coloquei um nome e genêro generico para o filme, o que pode ser modificado.

---

## Como rodar o projeto

### Opção 1 — Usuário final (Windows)

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
 
### Opção 2 — Compilar a partir do código (desenvolvedores)

Indicada para quem deseja **estudar, modificar ou evoluir o projeto**.

#### Requisitos
- GCC  
- Windows (MSYS2/MinGW), Linux ou macOS

#### Compilação
Na pasta raiz do projeto, execute:

```bash
  gcc -Iinclude src/main.c src/cinema.c -o gerenciador.exe
```
e depois:
```bash
  ./gerenciador.exe
```

