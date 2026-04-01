#include <stdio.h>
#include <string.h>

void luz(int m, int n, char matriz[m][n]){
    
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if(matriz[i][j] == 'P'){
                int e = i;
                int d = j;
                //conferindo o lado direito
                if(d+1<n){
                    if(matriz[i][d+1] != 'P'){
                        matriz[i][d+1] = '+';
                    }
                }
                    
                    
                //conferindo lado esquerdo
                if(d-1>=0){
                    if(matriz[i][d-1] != 'P'){
                        matriz[i][d-1] = '+';
                    }
                }
                //conferindo em cima
                if(e-1>=0){
                    if(matriz[e-1][j] != 'P'){
                        matriz[e-1][j] = '+';
                        
                    }
                }
                //conferindo em baixo
                if(e+1<m){
                    if(matriz[e+1][j] != 'P'){
                        matriz[e+1][j] = '+';
                        
                    }
                }
                //conferindo diagonal dieita baixo
                if(e+1<m && d+1<n){
                    if(matriz[e+1][d+1] == '+'){
                        matriz[e+1][d+1] = '+';
                    }else{
                        matriz[e+1][d+1] = 'x';
                    }
                }
                //conferindo diagonal direita cima
                if(e-1>=0 && d+1<n){
                    if(matriz[e-1][d+1] == '+'){
                        matriz[e-1][d+1] = '+';
                    }else{
                        matriz[e-1][d+1] = 'x';
                    }
                }
                //conferindo diagonal esquerda baixo
                if(e+1<m && d-1>= 0){
                    if(matriz[e+1][d-1] == '+'){
                        matriz[e+1][d-1] = '+';
                    }else{
                        matriz[e+1][d-1] = 'x';
                    }
                }
                //conferindo diagonal esquerda cima
                if(e-1>=0 && d-1>=0){
                    if(matriz[e-1][d-1] == '+'){
                        matriz[e-1][d-1] = '+';
                    }else{
                        matriz[e-1][d-1] = 'x';
                    }
                }
                
                
                
                
            }
                
        }
    }
}





int main()
{
    int m,n;
    scanf("%d %d",&m, &n);
    
    char matriz[m][n];
    
    for(int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            scanf(" %c", &matriz[i][j]);
        }
    }
    luz(m,n,matriz);
    
    for(int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%c", matriz[i][j]);
        }
        printf("\n");
    }
    
    

    return 0;
}