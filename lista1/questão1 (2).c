#include <stdio.h>

int main() {
    int total;
    float x, y, z;
    
    scanf("%d %f %f %f", &total, &x, &y, &z);

    float div0x = (total * x) / 100;
    float div0y = (total * y) / 100;
    float div0z = (total * z) / 100;

    if (div0x == (int)div0x && div0y == (int)div0y && div0z == (int)div0z) {
        printf("Cada homem ficou com %d, %d e %d reais, respectivamente\n", (int)div0x, (int)div0y, (int)div0z);
        int resto0 = total - ((int)div0x + (int)div0y + (int)div0z);
        if (3 + resto0 >= 7) {
            printf("Ela conseguiu! Rebeka voltou para casa e apanhou da mae por sumir noite passada!\n");
        } else {
            printf("E parece que Rebeka vai ter que voltar andando...\n");
        }
    } 
    else {
        // Caso 1: Investimento de 1 real
        int novototal1 = total + 1;
        float div1x = (novototal1 * x) / 100;
        float div1y = (novototal1 * y) / 100;
        float div1z = (novototal1 * z) / 100;

        if (div1x == (int)div1x && div1y == (int)div1y && div1z == (int)div1z && (novototal1 - ((int)div1x + (int)div1y + (int)div1z)) >= 2) {
            printf("Cada homem ficou com %d, %d e %d reais, respectivamente\n", (int)div1x, (int)div1y, (int)div1z);
            int resto1 = novototal1 - ((int)div1x + (int)div1y + (int)div1z);
            if ((3 - 1) + resto1 >= 7) {
                printf("Ela conseguiu! Rebeka voltou para casa e apanhou da mae por sumir noite passada!\n");
            } else {
                printf("E parece que Rebeka vai ter que voltar andando...\n");
            }
        }
        else {
            // Caso 2: Investimento de 2 reais
            int novototal2 = total + 2;
            float div2x = (novototal2 * x) / 100;
            float div2y = (novototal2 * y) / 100;
            float div2z = (novototal2 * z) / 100;

            if (div2x == (int)div2x && div2y == (int)div2y && div2z == (int)div2z && (novototal2 - ((int)div2x + (int)div2y + (int)div2z)) >= 3) {
                char letra1, letra2, letra3;
                scanf(" %c %c %c", &letra1, &letra2, &letra3);
                printf("%d\n", (letra1 - 'a' + 1) + (letra2 - 'a' + 1) + (letra3 - 'a' + 1));
                
                printf("Cada homem ficou com %d, %d e %d reais, respectivamente\n", (int)div2x, (int)div2y, (int)div2z);
                int resto2 = novototal2 - ((int)div2x + (int)div2y + (int)div2z);
                if ((3 - 2) + resto2 >= 7) {
                    printf("Ela conseguiu! Rebeka voltou para casa e apanhou da mae por sumir noite passada!\n");
                } else {
                    printf("E parece que Rebeka vai ter que voltar andando...\n");
                }
            }
            else {
                // Caso 3: Investimento de 3 reais
                int novototal3 = total + 3;
                float div3x = (novototal3 * x) / 100;
                float div3y = (novototal3 * y) / 100;
                float div3z = (novototal3 * z) / 100;

                if (div3x == (int)div3x && div3y == (int)div3y && div3z == (int)div3z && (novototal3 - ((int)div3x + (int)div3y + (int)div3z)) >= 4) {
                    int id1, id2, id3;
                    scanf("%d %d %d", &id1, &id2, &id3);
                    if (id1 % 3 == 0 || id2 % 3 == 0 || id3 % 3 == 0) {
                        printf("%d\n", (id1 / 3) + (id2 / 3) + (id3 / 3));
                    }
                    
                    printf("Cada homem ficou com %d, %d e %d reais, respectivamente\n", (int)div3x, (int)div3y, (int)div3z);
                    int resto3 = novototal3 - ((int)div3x + (int)div3y + (int)div3z);
                    if (resto3 >= 7) {
                        printf("Ela conseguiu! Rebeka voltou para casa e apanhou da mae por sumir noite passada!\n");
                    } else {
                        printf("E parece que Rebeka vai ter que voltar andando...\n");
                    }
                }
                else {
                    // Se nenhum caso funcionou
                    printf("Nao foi dessa vez que Rebeka pode ajudar...\n");
                    printf("E parece que Rebeka vai ter que voltar andando...\n");
                }
            }
        }
    }

    return 0;
}