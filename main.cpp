#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compararStrings(const void *a, const void *b) {
    const char **str1 = (const char **)a;
    const char **str2 = (const char **)b;
    
    const char *ptr1 = *str1;
    const char *ptr2 = *str2;
    
    while (*ptr1 != '\0' && *ptr2 != '\0') {
        if (*ptr1 != *ptr2) return (*ptr1 - *ptr2);
        ptr1++;
        ptr2++;
    }
    
    if (*ptr1 == '\0' && *ptr2 != '\0') return -1;
    
    if (*ptr1 != '\0' && *ptr2 == '\0') return 1;
    
    return 0;
}

int main() {
    int n;
    
    printf("Digite o número de estudantes: ");
    scanf("%d", &n);
    getchar();                                                                      // Remover o newline do enter no final
    
    char **lista_nomes = (char **)malloc(n * sizeof(char *));

    if (lista_nomes == NULL) {                                                      // Evitar erro de "Desreferência de ponteiro NULL"
        printf("Erro na alocação de memória!\n");
        return 1;
    }
    
    printf("Digite os nomes dos estudantes:\n");

    for (int i = 0; i < n; i++) {
        char buffer[101];
        fgets(buffer, 101, stdin);                                                  // É o limite de 100 caracteres + '\0', serve pra evitar overflow
        
        buffer[strcspn(buffer, "\n")] = '\0';                                       // Remover o newline do enter no final
        
        lista_nomes[i] = (char *)malloc((strlen(buffer) + 1) * sizeof(char));

        if (lista_nomes[i] == NULL) {                                               // Evitar erro de "Desreferência de ponteiro NULL"
            printf("Erro na alocação de memória!\n");
            
            // Liberar memória antes de abortar pra evitar memory leak
            for (int j = 0; j < i; j++) free(lista_nomes[j]);
            free(lista_nomes);
            return 1;
        }
        
        strncpy(lista_nomes[i], buffer, strlen(buffer) + 1);
    }
    
    qsort(lista_nomes, n, sizeof(char *), compararStrings);
    
    printf("\nNomes ordenados:\n");

    for (int i = 0; i < n; i++) printf("%s\n", lista_nomes[i]);
    
    // Liberar memória pra evitar memory leak
    for (int i = 0; i < n; i++) free(lista_nomes[i]);
    free(lista_nomes);
    
    return 0;
}