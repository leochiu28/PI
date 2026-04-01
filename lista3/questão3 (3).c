#include <stdio.h>
#include <string.h>

int main()
{
    char string[101];
    char palavras_extraidas[101];
    int inicio_palavras[100];
    
    int pares = 0;
    int total_palavras = 0;
    
    fgets(string, 101, stdin );
    string[strcspn(string, "\n")] = '\0'; 
    
    
    int j = 0;
    for(int i = 0; string[i]!= '\0';i++){
        if((string[i] >= 65 && string[i] <= 90) || (string[i] >= 97 && string[i] <= 122)){
            
            if(i == 0 || !((string[i-1] >= 65 && string[i-1] <= 90) || (string[i-1] >= 97 && string[i-1] <= 122))){
                inicio_palavras[total_palavras] = j;
                total_palavras = total_palavras + 1; 
            }
            palavras_extraidas[j++] = string[i];
        
            
        }else{
            if(j > 0 && palavras_extraidas[j-1] != '\0'){
                palavras_extraidas[j++] = '\0';
            }  
        }   
    }
    palavras_extraidas[j] = '\0';
    
    int achou_primeiro = 0;
    
    for(int i = 0; i<total_palavras; i++){
        for(int k = i+1; k <total_palavras; k++){
            
            int letras_iguais = 0;
            int indice_palavra1= inicio_palavras[i];
            int indice_palavra2 = inicio_palavras[k];           

            int diferenca1 = strlen(&palavras_extraidas[indice_palavra1]);
            int diferenca2 = strlen(&palavras_extraidas[indice_palavra2]);
            int diferenca = diferenca1 - diferenca2;
            
            if(diferenca < 0){
                diferenca = diferenca*(-1);// uma forma de deixar em modulo
            }
            
            if(diferenca == 0){// verifica se a palavra esta igual 
                if (diferenca1>1){
                    for (int x = 0; palavras_extraidas[indice_palavra1 + x] != '\0'; x++){
                        char letra1 = palavras_extraidas[indice_palavra1 + x];
                        
                        if (letra1 >= 65 && letra1 <= 90){
                            letra1 += 32;
                        }
                        
                        for(int y = 0; palavras_extraidas[indice_palavra2 + y] != '\0'; y++){
                            char letra2 = palavras_extraidas[indice_palavra2 + y];
                            
                            if(letra2 >=65 && letra2 <= 90){
                                letra2 += 32;
                            }
                            
                            if(letra1 == letra2){
                                letras_iguais ++;
                            }
                        }
                        
                    }
                    if( letras_iguais + 1 == strlen(&palavras_extraidas[indice_palavra1]) && letras_iguais != strlen(&palavras_extraidas[indice_palavra1]) && letras_iguais){
                        if(achou_primeiro == 0){
                            printf("Pares de palavras vizinhas encontrados:\n");
                            
                        }
                        printf("%s e %s\n", &palavras_extraidas[indice_palavra1], &palavras_extraidas[indice_palavra2]);
                        pares++;
                        achou_primeiro++;
                    }
                }else{
                    if(achou_primeiro == 0){
                        printf("Pares de palavras vizinhas encontrados:\n");
                    }
                    printf("%s e %s\n", &palavras_extraidas[indice_palavra1], &palavras_extraidas[indice_palavra2]);
                    pares++;
                    achou_primeiro ++;
                }
                
            }else if(diferenca == 1){
                int x = 0;
                int y = 0;
                int terminado = 0;
                int palavra_diferente = 0;
                int palavra_diferente_indice;

                while(palavra_diferente == 0){
                    if(letras_iguais == diferenca2){
                        if(achou_primeiro == 0){
                            printf("Pares de palavras vizinhas encontrados:\n");
                        }
                        printf("%s e %s\n", &palavras_extraidas[indice_palavra1], &palavras_extraidas[indice_palavra2]);
                        pares++;
                        achou_primeiro ++;
                        terminado ++;
                        palavra_diferente++;
                    }
                    char letra1 = palavras_extraidas[indice_palavra1 + x];
                    char letra2 = palavras_extraidas[indice_palavra2 + y];
                    if (letra1 >= 65 && letra1 <= 90){
                        letra1 += 32;
                    }
                    if(letra2>=65 && letra2 <=90){
                        letra2 +=32;
                    }
                    if(letra1 == letra2){
                        letras_iguais ++;
                    }else{
                        palavra_diferente++;
                        palavra_diferente = x;
                    }
                }if(palavra_diferente>0 && terminado == 0){
                    if(diferenca1>diferenca2){
                        for(int c = palavra_diferente +1; palavras_extraidas[indice_palavra1 + c]<'\0';c++){
                            char letra1 = palavras_extraidas[indice_palavra1 + c];
                            if (letra1 >= 65 && letra1 <= 90){
                                letra1 +=32;
                            }
                            for(int d = palavra_diferente; palavras_extraidas[indice_palavra2 + d]< '\0'; d++){
                                char letra2 = palavras_extraidas[indice_palavra2 + d];
                                if (letra2 >= 65 && letra1 <= 90){
                                    letra2 +=32;
                                }
                                if(letra1 == letra2){
                                    letras_iguais++;
                                }
                            }
                        }
                        if(letras_iguais == diferenca2){
                            if(achou_primeiro == 0){
                                printf("Pares de palavras vizinhas encontrados:\n");
                            }printf("%s e %s\n", &palavras_extraidas[indice_palavra1], &palavras_extraidas[indice_palavra2]);
                            pares++;
                            achou_primeiro++;
                        }
                    }else{
                        for(int c = palavra_diferente +1; palavras_extraidas[indice_palavra2 + c]<'\0';c++){
                            char letra2 = palavras_extraidas[indice_palavra2 + c];
                            if (letra2 >= 65 && letra2 <= 90){
                                letra2 +=32;
                            }
                            for(int d = palavra_diferente; palavras_extraidas[indice_palavra1 + d]< '\0'; d++){
                                char letra1 = palavras_extraidas[indice_palavra1 + d];
                                if (letra1 >= 65 && letra1 <= 90){
                                    letra1 +=32;
                                }
                                if(letra1 == letra2){
                                    letras_iguais++;
                                }
                            }
                        }
                        if(letras_iguais == diferenca1){
                            if(achou_primeiro == 0){
                                printf("Pares de palavras vizinhas encontrados:\n");
                            }printf("%s e %s\n", &palavras_extraidas[indice_palavra1], &palavras_extraidas[indice_palavra2]);
                            pares++;
                            achou_primeiro++;
                        }
                    }
                }
            }
        }
    }
    
    if (pares > 0) {
    printf("\nTotal de pares: %d\n", pares);
    }else{
        printf("Nao existem palavras vizinhas na frase.");
    }

    
    
    return 0;
}

   