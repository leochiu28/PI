#include <stdio.h>

int main()
{
    int valido = 0; 
    int N, K, P;
    int Q = 0;
    int primeiro_num = 0;

    scanf("%d %d %d", &N, &K, &P);
    
    for(int i = N; i < K; i++){
        
        int num = i; 
        int primosimpares = 0;
        int repetiu = 0;
        
        while(num > 0 && num % 2 == 0){
            num /= 2;
        }

        for (int j = 3; j * j <= num && repetiu == 0; j = j + 2){
            if(num % j == 0){
                primosimpares += 1;
                num /= j;
                
                if(num % j == 0){
                    repetiu = 1; 
                }
            }
        }
        
        if(repetiu == 0 && num > 1){
            primosimpares += 1;
        }

        if(repetiu == 0 && primosimpares == P){
            if(valido == 0){
                primeiro_num = i;
                valido = 1;
            } else {
                Q += 1;
            }
        }
    }
    
    if(valido == 0){
        printf("Poxa dudinha, me desculpa, nao achei os numeros mas vou te mandar uma foto de um gatinho fofo.\n");
    } else {
        printf("%d %d\n", primeiro_num, Q);
    }

    return 0;
}