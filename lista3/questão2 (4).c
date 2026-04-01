#include <stdio.h>

int main() {
    int n, x, y;
    if (scanf("%d %d %d", &n, &x, &y) != 3) return 0;

    int clientes_latas[200] = {0};//lista dos cliente(indice) e suas latas

    for (int i = 0; i < y; i++) {//prenchendo as latas do sistema y
        int h, m, latas_y;
        scanf("%d:%d %d", &h, &m, &latas_y);
        int num_cliente = ((h * 60 + m) - 420) / 3;
        if (num_cliente <= n) {
            clientes_latas[num_cliente] = latas_y;
        }
    }

    if (x > 0) {
        for (int i = x; i <= n; i += x) {
            if (clientes_latas[i] == 0) {//garante que as latas y nao sejam contadas de novo
                clientes_latas[i] = 1;
            }
        }
    }

    int latas_acumuladas = 0;
    int vencedor = -1;//se as latas forem 50 o cliente anterios no looping foi o vencedor

    for (int k = 1; k <= n; k++) {//o numero de indice 1 ajuda a facilitar saber qual cliente foi
        latas_acumuladas += clientes_latas[k];
        if (latas_acumuladas >= 50) {
            vencedor = k;
            break;
        }
    }

    if (vencedor != -1) {// se houver vencedor
        int tempo_total = vencedor * 3;
        int horas = 7 + (tempo_total / 60);
        int minutos = tempo_total % 60;
        
        if (clientes_latas[vencedor] == 1) {//lata no singular
            printf("Quem levou a cesta basica foi o %d* cliente atendido por coragem, as %02d:%02d. Que comprou %d lata.\n", vencedor, horas, minutos, clientes_latas[vencedor]);
        } else {
            printf("Quem levou a cesta basica foi o %d* cliente atendido por coragem, as %02d:%02d. Que comprou %d latas.\n", vencedor, horas, minutos, clientes_latas[vencedor]);
        }
    } else {//sem vencedor
        int faltam = 50 - latas_acumuladas;
        if (faltam == 1) {
            printf("Ainda nao foram vendidas latas suficientes. Falta 1 lata.\n");
        } else {
            printf("Ainda nao foram vendidas latas suficientes. Faltam %d latas.\n", faltam);
        }
    }

    return 0;
}