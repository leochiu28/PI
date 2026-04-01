#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, c, quadranteAtual, quadranteDestino;
    
    scanf("%d %d %d", &x, &y, &c);
    // indentificando o quadrante atual
    if(x>0 && y>0){
        quadranteAtual = 1;
    
        
    }else if(x<0 && y>0){
        quadranteAtual = 2;
    
        
    }else if(x<0 && y<0){
        quadranteAtual = 3;
        
    }else if(x>0 && y<0){
        quadranteAtual = 4;
    }else{
        // em caso da posi��o atual estar em algum dos eixos sendo imposs�vel de saber o quadrante
        printf("caminhada invalida\n");
        return 0;
    }
    
    // identificando destino 
    if(quadranteAtual == 1){
        quadranteDestino = 3;
        
    }else if(quadranteAtual == 2){
        quadranteDestino = 4;
        
    }else if(quadranteAtual == 3){
        quadranteDestino = 1;
        
    }else if(quadranteAtual == 4){
        quadranteDestino = 2;
        
    }
    
    // verificando se o caminho � valido
    if(c == quadranteAtual || c == quadranteDestino){
        printf("caminhada invalida");
        return 0;
    }
    
    //passos para chegar na posi��o (1,1)
    
    int passos_x = abs(x) + 1;
    int passos_y = abs(y) + 1;
    
    //os passos s�o sempre os mesmos, apenas o que muda � a ordem que vai ser usada
    // os passos que v�o ser usados primeiros � justamento o do eixo adjecente
    int inicio_y = 0;
    
    if(quadranteAtual == 1){
        if(c == 2){
            inicio_y += 1;
        }
    }else if(quadranteAtual == 2){
        if(c == 1){
            inicio_y += 1;
        }
    }else if(quadranteAtual == 3){
        if(c == 4){
            inicio_y +=1;
        }
    }else if(quadranteAtual == 4){
        if(c == 3){
            inicio_y +=1;
            
        }
    }
    
    if(inicio_y>0){
        printf("%d passos em y e %d passos em x\n", passos_y, passos_x);
    }else{
        printf("%d passos em x e %d passos em y\n", passos_x, passos_y);
    }
    
    return 0;
}