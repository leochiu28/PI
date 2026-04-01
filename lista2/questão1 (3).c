#include <stdio.h>

int main()
{
    char letra_limite;
    
    scanf("%c", &letra_limite);
    
    int total_linhas = letra_limite - 'A' + 1;
    
    for(int i = 0; i < total_linhas; i++){
        
        int pontos = (total_linhas - 1) - i;
        
        for(int j = 0; j < pontos; j++){
            printf(".");
        }
        
        for(int j = 0; j <= i; j++){
            printf("%c", 'A' + j);
        }
        
        for(int j = i - 1; j >= 0; j--){
            printf("%c", 'A' + j);
        }
        
        for(int j = 0; j < pontos; j++){
            printf(".");
        }
    
        printf("\n");
    }

    return 0;
}