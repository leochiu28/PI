#include <stdio.h>

int main()
{
    int cases;
    scanf("%d", &cases);
    
    for(int i = 0; i < cases; i++){
        
        int N;
        scanf("%d", &N);
        
        int sequencia[N];
        
        for(int j = 0; j < N; j++){  // Recebendo valores da sequencia
            scanf("%d", &sequencia[j]);
        }
        
        int indice_max = 0;
        int tamanho_max = 0;
        int indice_atual = 0;
        int contador = 0;
        
        for(int i = 1; i < N; i++){
            if(sequencia[i] < sequencia[i - 1]){
                contador += 1;
            } else { 
                if(contador > tamanho_max){
                    tamanho_max = contador; //recorde do tamanho de números
                    indice_max = indice_atual; //mostra o indice do inicio da maior sequencia
                }
                indice_atual = i; //renicia o indice a partir do proximo numero
                contador = 0; // renicia o contador de números decrescentes
            }
        }
        
        if(contador > tamanho_max){ //garente que a ultima sequencia contada seja adicionada
            tamanho_max = contador;
            indice_max = indice_atual;
        }
        
        if(tamanho_max > 0){ //sequencia não nula
            tamanho_max += 1;
            printf("%d\n", tamanho_max); 
            for(int k = indice_max; k < indice_max + tamanho_max; k++){
                if(k == indice_max + tamanho_max - 1){
                    printf("%d \n", sequencia[k]); 
                } else {
                    printf("%d ", sequencia[k]); 
                }
            }
        } else { //sequencia nula
            printf("%d\n", tamanho_max);
        }
    }

    return 0;
}