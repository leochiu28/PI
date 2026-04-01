#include <stdio.h>
#include <stdlib.h>

int main() {
    long long x;
    int N;

    if (scanf("%lld %d", &x, &N) != 2) return 0;

    int canal_escolhido = -1;
    int minuto_estimado = -1;
    long long termo_proximo = -1;
    long long menor_distancia = -1;

    for (int i = 1; i <= N; i++) {
        long long f1, f2;
        scanf("%lld %lld", &f1, &f2);

        long long anterior = f1;
        long long atual = f2;
        int minuto_atual = 1;
        int busca_ativa = 1;

        while (busca_ativa) {
            long long valor_f;
            
            if (minuto_atual == 1) {
                valor_f = anterior;
            } else if (minuto_atual == 2) {
                valor_f = atual;
            } else {
                valor_f = anterior + atual;
                anterior = atual;
                atual = valor_f;
            }

            long long distancia = llabs(x - valor_f);
            int trocar = 0;

            if (canal_escolhido == -1) {
                trocar = 1;
            } else if (distancia < menor_distancia) {
                trocar = 1;
            } else if (distancia == menor_distancia) {
                if (valor_f < termo_proximo) {
                    trocar = 1;
                } else if (i > canal_escolhido) {
                    trocar = 1;
                }
            }

            if (trocar) {
                menor_distancia = distancia;
                canal_escolhido = i;
                minuto_estimado = minuto_atual;
                termo_proximo = valor_f;
            }

            if (valor_f > x && minuto_atual > 2) {
                busca_ativa = 0;
            } else {
                minuto_atual++;
            }
        }
    }

    int soma = 0;
    long long temp_vip = llabs(termo_proximo);
    
    while (temp_vip > 0) {
        soma += temp_vip % 10;
        temp_vip /= 10;
    }

    if (soma > 10) {
        printf("Xupenio, para ir ao lulupalooza vc deve entrar no canal %d e sera chamado mais ou menos no minuto %d e com o VIP garantido!!!\n", canal_escolhido, minuto_estimado);
    } else {
        printf("Xupenio, para ir ao lulupalooza vc deve entrar no canal %d e sera chamado mais ou menos no minuto %d, mas o ingresso VIP não vai rolar :(\n", canal_escolhido, minuto_estimado);
    }

    return 0;
}