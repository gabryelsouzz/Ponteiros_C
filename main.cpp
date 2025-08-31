#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compararStrings(const void *a, const void *b) {

    /*  
        Função que compara duas strings de tamanho indeterminado. 
        Implementada a fim de ser utilizada como parâmetro para
        a função qsort();

        args:
            a: ponteiro genérico para a primeira string
            b: ponteiro genérico para a segunda string

        return:
            um numérico inteiro tal que:
                0 se a == b
                valor positivo se a > b
                valor negativo se a < b
    */

    // Type casting dos ponteiros genéricos para ponteiros de string
    const char **str1 = (const char **)a;
    const char **str2 = (const char **)b;
    
    // Ponteiros auxiliares para percorrer as strings. Iniciam na 
    // posição 0 de cada string 
    const char *ptr1 = *str1;
    const char *ptr2 = *str2;
    
    // Percorre as strings enquanto não chegar ao fim de nenhuma
    while (*ptr1 != '\0' && *ptr2 != '\0') {

        // Compara os caracteres atuais
        if (*ptr1 != *ptr2) return (*ptr1 - *ptr2);

        // Incrementa os ponteiros para o próximo caractere
        ptr1++;
        ptr2++;
    }
    
    // Caso uma seja prefixo da outra, retorna a menor, se for o caso
    if (*ptr1 == '\0' && *ptr2 != '\0') return -1;
    if (*ptr1 != '\0' && *ptr2 == '\0') return 1;
    
    // "Se" ambas são iguais
    return 0;
}


void copiarString(char *destino, const char *origem) {
    /*
        Função que copia uma string de origem para um destino.
        Implementada para evitar o uso de strcpy() da string.h,
        que pode causar problemas de segurança se o destino
        não for grande o suficiente.

        args:
            destino: ponteiro para a string destino
            origem: ponteiro para a string origem

        return:
            void
    */

    while (*origem != '\0') {
        *destino = *origem;
        destino++;
        origem++;
    }
    
    *destino = '\0'; // Adiciona o caractere nulo ao final
}


int buscarCaractere(const char *str, char c) {
    /*
        Função que busca a primeira ocorrência de um caractere
        em uma string.

        args:
            str: ponteiro para a string onde será feita a busca
            c: caractere a ser buscado

        return:
            índice da primeira ocorrência do caractere na string,
            ou -1 se o caractere não for encontrado
    */

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) return i;
    }
    
    return -1; // Caractere não encontrado
}


int main() {
    /*
        Programa que lê uma lista de nomes de estudantes, armazena
        em um array dinâmico e ordena em ordem alfabética utilizando
        a função qsort() da stdlib.h

        Utiliza alocação dinâmica para armazenar os nomes, e libera
        a memória ao final da execução para evitar memory leak.
    */

    int n; // represenação do número de entradas
    
    printf("Digite o número de estudantes: ");
    scanf("%d", &n);
    getchar();                                                                      // Remover o newline do enter no final
    
    char **lista_nomes = (char **)malloc(n * sizeof(char *));                       // Alocação dinâmica do array de strings

    // "Se a alocação falhar". Evita erro de "Desreferência de ponteiro NULL"
    if (lista_nomes == NULL) {
        printf("Erro na alocação de memória!\n");
        return 1;
    }
    
    printf("Digite os nomes dos estudantes:\n");

    for (int i = 0; i < n; i++) {
        char buffer[101];                                                           // Buffer auxiliar para ler o nome (limite de 100 caracteres, '\0' indica o fim da string)
        fgets(buffer, 101, stdin);                                                  
        
        buffer[buscarCaractere(buffer, '\n')] = '\0';                               // Remove o newline ('\n') do final, se houver
        
        lista_nomes[i] = (char *)malloc((strlen(buffer) + 1) * sizeof(char));       // !!!! Alocação dinâmica para cada string (+1 para o caractere nulo '\0')

        // "Se a alocação falhar". Evita erro de "Desreferência de ponteiro NULL"
        if (lista_nomes[i] == NULL) {
            printf("Erro na alocação de memória!\n");
            
            // Liberar memória antes de abortar pra evitar memory leak
            for (int j = 0; j < i; j++) free(lista_nomes[j]);
            free(lista_nomes);
            return 1;
        }
        
        copiarString(lista_nomes[i], buffer);
    }
    
    qsort(lista_nomes, n, sizeof(char *), compararStrings);                         // !!!! Utiliza o swap de ponteiros para strings. Demonstração ao fim do código.
    
    printf("\nNomes ordenados:\n");

    for (int i = 0; i < n; i++) printf("%s\n", lista_nomes[i]);
    
    // Liberar memória pra evitar memory leak
    for (int i = 0; i < n; i++) free(lista_nomes[i]);
    free(lista_nomes);
    
    return 0;
}

void swapStrings(char **a, char **b) {

    /*
        Função que troca duas strings utilizando ponteiros para ponteiros. 
        Implementada para demonstrar o swap de ponteiros na função qsort().
        A string a passa a ser apontada pela string b e vice-versa.

        args:
            a: ponteiro para a primeira string
            b: ponteiro para a segunda string

        return:
            void
    */

    char *temp = *a;
    *a = *b;
    *b = temp;
}