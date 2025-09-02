# Projeto PLP - Ponteiros em C/C++

## Problema: Sistema de Ordenação de Nomes de Estudantes

### Contexto

A secretaria acadêmica da universidade precisa processar uma lista de nomes de estudantes para gerar relatórios ordenados. Este programa em C lê os nomes dos alunos, ordena-os alfabeticamente e apresenta o resultado, utilizando conceitos avançados de ponteiros e alocação dinâmica de memória.

Conceitos Abordados:

1. **Ponteiros** (*): É uma variável especial que armazena endereços de memória, "apontando" para onde outra variável está guardada. Isso Permite acesso e modificação indireta de valores.

2. **Ponteiros Duplos** (*): É um ponteiro para outro ponteiro. Permite modificar indiretamente ponteiros comuns e é útil para manipular arrays de ponteiros. Bastante usado para estruturas de dados complexas e alocação dinâmica multidimensional. A principal diferença em relação aos ponteiros "simples" está no nível de indireção: ponteiros comuns acessam valores indiretamente, enquanto ponteiros duplos acessam ponteiros indiretamente, criando assim dois níveis de referência.

3. **Aritmética de Ponteiros**: Em essência, a aritmética de ponteiros permite navegar de forma eficiente e previsível por arrays e blocos de memória, movendo-se para o próximo ou anterior elemento, não apenas para o próximo byte. Funciona como "dar passos" sobre um espaço de memória.

4. **Alocação Dinâmica de Memória**: Se baseia na "reserva" de memória para variáveis em tempo de execução. Usa-se a função ```malloc()``` para criar arrays e strings em tempo de execução.

5. **Liberação de memória**: A liberação de memória, em C acionada através da função ```free()```, é o ato de avisar explicitamente ao sistema que você terminou de usar aquele bloco de memória que pediu anteriormente. É crucial para evitar um vazamentos de memória.

### Instruções de Compilação e Execução

#### Compilação

Em Linux/macOS:

```gcc -o main main.cpp```

Em Windows:
```gcc -o main.exe main.cpp```

#### Execução

```./main```

#### Formato de entrada

* Primeira linha: um intero **N**, representando a quantidade de alunos.
* **N** seguintes linhas: strings representando os nomes dos N alunos.

#### Formato de saída
As N strings de forma ordenada.

### Exemplo de Execução:

#### Exemplo 1:

##### Entradas:

5
Kenandja
Joao
Karol
Carlos
Gabryel

##### Saídas:

Carlos
Gabryel
Joao
Karol
Kenandja

#### Exemplo 2:

##### Entradas:

3
Fred
Frederico
Bruno

##### Saídas:

Bruno
Fred
Frederico