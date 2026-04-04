#include <stdio.h>
#include <string.h>

void caminhar(int cidade[4][4], char moves[20]){
    int m = 0;
    int n = 0;
    cidade[0][0] += 1;
    
    for(int i = 0; i<20; i++){
        
        if(moves[i] == 'c' && m > 0){
            cidade[m-1][n] +=1 ;
            m--;
            
        }else if(moves[i] == 'b' && m < 3){
            cidade[m+1][n] +=1 ;
            m++;
            
        }else if(moves[i] == 'd' && n < 3){
            cidade[m][n+1] +=1 ;
            n++;
            
        }else if(moves[i] == 'e' && n > 0){
            cidade[m][n-1] +=1;
            n--;
        }
        
    }
}


int main()
{
    int cidade[4][4];
    char moves[20];
    
    for(int i = 0; i<4; i++){ //começa com todas cordenadas igual a zero
        for(int j = 0; j<4; j++){
            cidade[i][j] = 0;
        }
    }
    
    for(int i = 0; i<20; i++){
        scanf(" %c", &moves[i]);
    }
    
    caminhar(cidade, moves); // chama a função
    int x = 0;
    int y = 0;
    int maior = cidade[0][0];
    
    for(int i = 0; i<4; i++){ // procura o valor maior
        for(int j = 0; j<4; j++){
            if(cidade[i][j] > maior){
                maior = cidade[i][j];
                
                x = j; //perceba que a coordenada x é a coluna, pois é o elemento da matriz que anda pela horizontal
                
                y = i;// ja a coordena y é a linha, pois é o elemento da mtriz que anda pela vertical
            }
        }
    }
    
    printf("Coordenada X:%d, Y:%d", x,y);
    
    return 0;
}
