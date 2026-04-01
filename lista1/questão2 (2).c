#include <stdio.h>

int main(){

    long long N;
    long long A, B;
    scanf("%lld", &N);
    scanf("%lld %lld", &A, &B);

    //P.A

    //soma de 1 até N
    long long pa = (N*(N+1))/2;

    //soma dos multiplos
    long long k1 = N/A;
    long long k2 = N/B;
    long long k3 = N/(A*B);

    long long Sa = A*((k1*(k1+1))/2);
    
    long long Sb = B*((k2*(k2+1))/2);
    
    long long S1 = pa - Sa - Sb;

    long long  Sab = (A*B)*((k3*(k3+1))/2);

    long long resultado = S1 + Sab;

    printf("%lld\n", resultado);

    if(resultado%2 == 0){

        printf("Lá ele!!!");

    }else{

        printf("Opa xupenio AULAS...");
    }

    return 0;
}