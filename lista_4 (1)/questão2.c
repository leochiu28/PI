#include <stdio.h>
#include <string.h>

void processar_agua(int m, int n, char mat[m][n]) {
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 'o') {
                if (mat[i + 1][j] == '.') {
                    mat[i + 1][j] = 'o';
                }
                else if (mat[i + 1][j] == '#') {
                    int d = j;
                    while (d < n && mat[i + 1][d] == '#') {
                        mat[i][d] = 'o';
                        d++;
                    }
                    if (d < n) {
                        mat[i][d] = 'o';
                        if (mat[i + 1][d] == '.') {
                            mat[i + 1][d] = 'o';
                        }
                    }

                    int e = j;
                    while (e >= 0 && mat[i + 1][e] == '#') {
                        mat[i][e] = 'o';
                        e--;
                    }
                    if (e >= 0) {
                        mat[i][e] = 'o';
                        if (mat[i + 1][e] == '.') {
                            mat[i + 1][e] = 'o';
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    char matriz[m][n];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf(" %c", &matriz[i][j]);
        }
    }

    processar_agua(m, n, matriz);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}