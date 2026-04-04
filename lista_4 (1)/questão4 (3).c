#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void backtracking(int n, int m, int i, int j, char mapa[][m], int visitados[][m], int index, int *menor)
{
    if (index >= *menor) return;
    if (index >= visitados[i][j]) return;
    visitados[i][j] = index;
    if (mapa[i][j] == 'd')
    {
        if (*menor > index)
        {
            *menor = index;
        }
        
        return;
    }
    else
    {
        if (j + 1 < m && mapa[i][j+1] != '#')
        {
            backtracking(n, m, i, j + 1, mapa, visitados, index + 1, menor);
        }
        if (i + 1 < n && mapa[i+1][j] != '#')
        {
            backtracking(n, m, i + 1, j, mapa, visitados, index + 1, menor);
        }
        if (j - 1 >= 0 && mapa[i][j-1] != '#')
        {
            backtracking(n, m, i, j - 1, mapa, visitados, index + 1, menor);
        }
        if (i - 1 >= 0 && mapa[i - 1][j] != '#')
        {
            backtracking(n, m, i - 1, j, mapa, visitados, index + 1, menor);
        }
    }
}

int main()
{
    int linha, coluna;
    scanf("%d%*c%d", &linha, &coluna);
    char mapa[linha][coluna];
    int visitados[linha][coluna];
    int x, y;
    getchar();
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            visitados[i][j] = 1000;
            if (j == coluna - 1 && i != linha - 1)
            {
                scanf("%c\n", &mapa[i][j]);
            }
            else
            {
                scanf("%c", &mapa[i][j]);
            }
            if (mapa[i][j] == 'o')
            {
                x = i;
                y = j;
            }
        }
    }
    int index = 0;
    int menor = 1000;
    for(int i = 0; i < linha; i++)
    {
        for(int j = 0; j < coluna; j++)
        {
            if(mapa[i][j] == 'o')
            {
                if(mapa[i+1][j] == '#' && mapa[i-1][j] == '#' && mapa[i][j+1] == '#' && mapa[i][j - 1] == '#')
                {
                    break;
                }
                backtracking(linha, coluna, x, y, mapa, visitados, index, &menor);
                break;
            }
        }
    }
    if (menor != 1000)
    {
        printf("Apos correr %d metros e quase desistir por causa da distância, Rebeka conseguiu escapar!\n", menor);
    }
    else
    {
        printf("Poxa... Parece que nao foi dessa vez que Rebeka conseguiu fugir\n");
    }
    return 0;
}