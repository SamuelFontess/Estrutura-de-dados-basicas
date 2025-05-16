# Especificação das Funções Implementadas

Este documento descreve as funções implementadas como parte da Atividade Prática 01 da disciplina IMD0029.

## 1. `busca_binaria`

- **Arquivo Fonte:** `src_c/busca_binaria.c`
- **Arquivo Cabeçalho:** `include_c/busca_binaria.h`

### Descrição

A função `busca_binaria` implementa o algoritmo de busca binária para encontrar a primeira "versão defeituosa" em uma sequência de `n` versões. Assume-se que se uma versão é defeituosa, todas as subsequentes também são. A função utiliza uma "API externa" `isBadVersion(int version)` que retorna `true` se a versão fornecida é defeituosa e `false` caso contrário.

### Parâmetros

- `int n`: O número total de versões (numeradas de 1 a `n`).

### Retorno

- `int`: O número da primeira versão defeituosa. Se `n` for 0 ou menor, retorna 0. Se todas as `n` versões forem boas (conforme a simulação de `isBadVersion`), a função retornará `n + 1`.

### Instruções de Uso

1. Inclua o cabeçalho `busca_binaria.h`.
2. Certifique-se de que a função `isBadVersion(int version)` esteja definida e acessível no escopo. por praticidade, a chamada desta API é feita no arquivo de teste: `test_c/test_algorithms.c`.
3. Chame a função `busca_binaria(n)` passando o número total de versões.

### Exemplo de Chamada (conforme arquivo de teste)

```c
int numero_total_versoes = 5;
bad_version = 4; // Define que a versão 4 é a primeira defeituosa
int primeira_defeituosa = busca_binaria(numero_total_versoes);
// primeira_defeituosa será 4
```

## 2. `busca_seq_ordenada`

- **Arquivo Fonte:** `src_c/busca_seq_ordenada.c`
- **Arquivo Cabeçalho:** `include_c/busca_seq_ordenada.h`

### Descrição

A função `busca_seq_ordenada` realiza uma busca sequencial por um valor `alvo` em um vetor `arr[]` que **deve estar ordenado** em ordem crescente. A busca é otimizada para parar se um elemento maior que o alvo for encontrado, já que o vetor está ordenado.

### Parâmetros

- `int arr[]`: O vetor de inteiros ordenado onde a busca será realizada.
- `int n`: O número de elementos no vetor `arr`.
- `int alvo`: O valor inteiro a ser buscado.

### Retorno

- `int`: O índice do `alvo` no vetor `arr` se encontrado; caso contrário, retorna -1.

### Instruções de Uso

1. Inclua o cabeçalho `busca_seq_ordenada.h`.
2. Certifique-se de que o vetor passado para a função esteja previamente ordenado.
3. Chame `busca_seq_ordenada(vetor, tamanho_vetor, valor_alvo)`.

## 3. `conta_especialidades_distintas`

- **Arquivo Fonte:** `src_c/busca_seq_ordenada.c` (contém esta função e `bubble_sort`)
- **Arquivo Cabeçalho:** `include_c/busca_seq_ordenada.h`

### Descrição

A função `conta_especialidades_distintas` conta quantas especialidades únicas (representadas por números inteiros) existem em um vetor `arr[]`. Para isso, a função primeiro ordena o vetor `arr[]` internamente usando `bubble_sort` e depois percorre o vetor ordenado para contar os elementos distintos.

### Parâmetros

- `int arr[]`: O vetor de inteiros representando as especialidades. **Este vetor será ordenado pela função bubble sort.**
- `int n`: O número de elementos no vetor `arr`.

### Retorno

- `int`: O número de especialidades distintas encontradas no vetor. Retorna 0 se o vetor estiver vazio.

### Instruções de Uso

1. Inclua o cabeçalho `busca_seq_ordenada.h`.
2. Chame `conta_especialidades_distintas(vetor_especialidades, numero_de_especialidades)`.
3. Esteja ciente de que o vetor original será ordenado.

### Exemplo de Chamada (conforme arquivo de teste)

```c
int especialidades[] = {4, 2, 1, 4, 2, 1};
int n_espec = sizeof(especialidades) / sizeof(especialidades[0]); // pra determinar tamanho do vetor caso seja preciso mudar o vetor e não mudar o tamanho na chamada da função
int distintas = conta_especialidades_distintas(especialidades, n_espec);
// distintas será 3 (as especialidades únicas são 1, 2, 4)
// O vetor 'especialidades' agora estará ordenado: {1, 1, 2, 2, 4, 4}
```

## 4. `bubble_sort`

- **Arquivo Fonte:** `src_c/busca_seq_ordenada.c`
- **Arquivo Cabeçalho:** `include_c/busca_seq_ordenada.h`

### Descrição

A função `bubble_sort` ordena um vetor de inteiros `arr` em ordem crescente utilizando o algoritmo Bubble Sort. É uma função auxiliar usada em `conta_especialidades_distintas`.

### Parâmetros

- `int arr[]`: O vetor de inteiros a ser ordenado.
- `int n`: O número de elementos no vetor `arr`.

### Retorno

- `void`: A função modifica o vetor `arr` diretamente.

## 5. `recursao`

- **Arquivo Fonte:** `src_c/recursao.c`
- **Arquivo Cabeçalho:** `include_c/recursao.h`

### Descrição

A função `recursao` conta quantas vezes um caractere `alvo` aparece em uma string `str`.

### Parâmetros

- `const char *str`: Um ponteiro para o início da string.
- `char alvo`: O caractere a ser contado na string.

### Retorno

- `int`: O número de ocorrências do caractere `alvo` na string `str`.

### Instruções de Uso

1. Inclua o cabeçalho `recursao.h`.
2. Chame `recursao(minha_string, caractere_alvo)`.

### Exemplo de Chamada (conforme arquivo de teste)

```c
const char *texto = "banana";
char letra = 'a';
int contagem = recursao(texto, letra);
// contagem será 3
```
