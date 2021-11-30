#include <stdio.h>
#define n 10
#define inf 999999999
int min(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
void getMatrix(int mat[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
}
void isRoute(int mat[n][n])
{
    int i, j;
    scanf("%d%d", &i, &j);
    if (mat[i][j] == 0 && i != j)
    {
        mat[i][j] = inf;
    }
    for (int i = 0; i < n; i++)
    {
        Floyd_Warshall(mat, i);
    }
    if (mat[i][j] >= inf || mat[i][j] == 0)
        printf("False\n");
    else
        printf("True\n");
}
void Floyd_Warshall(int mat[n][n], int k)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                mat[i][j] = 0;
            else if (i == k || j == k)
                continue;
            else
            {
                mat[i][j] = min(mat[i][k] + mat[k][j], mat[i][j]);
            }
        }
    }
}
void printShortPath(int mat[n][n])
{
    int i, j;
    scanf("%d%d", &i, &j);
    for (int i = 0; i < n; i++)
    {
        Floyd_Warshall(mat, i);
    }
    if (mat[i][j] != inf && mat[i][j] != 0)
        printf("%d\n", mat[i][j]);
    else
        printf("-1\n");
}