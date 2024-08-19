# Gerenciador de Concursos da Mega-Sena com Tabela de Dispersão
Alissa de Lima Araújo

Este projeto consiste em um gerenciador de concursos da Mega-Sena utilizando uma tabela de dispersão (hash table) para armazenar e acessar os dados dos concursos. O sistema implementa funcionalidades como inserção, busca, remoção, visualização de concursos e a geração de estatísticas dos números sorteados. O projeto foi desenvolvido em linguagem C, com foco na modularidade e organização do código.

### Funcionalidades:
1. Inserir Concurso
    - Permite ao usuário inserir um novo concurso na tabela de dispersão. Cada concurso é identificado por um número único e contém a data do sorteio e os seis números sorteados. O sistema garante que não haja duplicação de números de concurso.

2. Buscar Concurso
    - Permite ao usuário buscar um concurso específico na tabela de dispersão usando o número do concurso. A busca retorna a data do sorteio e os números sorteados.

3. Remover Concurso
    Permite ao usuário remover um concurso da tabela de dispersão usando o número do concurso. A remoção garante que o concurso seja excluído corretamente da tabela.

4. Visualizar Todos os Concursos
    - Permite a visualização de todos os concursos armazenados na tabela de dispersão, exibindo o número do concurso, a data do sorteio e os números sorteados.

5. Carregar Concursos de um Arquivo
    - Permite o carregamento de concursos a partir de um arquivo de dados (CSV ou TSV) contendo resultados históricos dos sorteios da Mega-Sena.

Apresentar Estatísticas
- Quantidade de sorteios de um número específico.
- Dez números mais sorteados.
- Dez números menos sorteados.
- Quantidade de concursos em um determinado ano.

### Estrutura
#### main.c
Contém a função principal e a interface de usuário para interação com as funcionalidades do sistema.

#### hash_table.c
Implementa as funções relacionadas à tabela de dispersão, incluindo a criação, inserção, busca, remoção e visualização dos concursos.

#### hash_table.h
Declaração das estruturas e funções utilizadas na tabela de dispersão.

#### concurso.c
Implementa as funções relacionadas à manipulação dos concursos, como criação, inserção, busca e remoção.

#### concurso.h
Declaração das estruturas e funções relacionadas aos concursos.

#### leitor.c
Implementa as funções para ler os arquivos CSV e TSV

#### leitor.h
Declaração das funções de leitura dos arquivos

#### Makefile
Script de automação para a compilação do projeto. Permite a compilação de todos os arquivos e a geração do executável.

### Estruturas:
#### Tabela de Dispersão
- Implementada utilizando uma estrutura de hash com tratamento de colisões através de encadeamento (chaining). Cada entrada na tabela de dispersão é uma lista ligada que contém os concursos.

#### Concurso
- Estrutura que armazena o número do concurso, a data do sorteio e os números sorteados.

### Compilar e executar:
```console
make
```