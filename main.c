#include <stdio.h>
#include "my_mat.h"
#define n 10
int main()
{
    char a;
    scanf(" %c", &a);
    int matrix[n][n];
    while ('D' != a)
    {
        switch (a)
        {
        case 'A':
            getMatrix(matrix);
            scanf(" %c", &a);
            break;
        case 'B':
            isRoute(matrix);
            scanf(" %c", &a);
            break;
        case 'C':
            printShortPath(matrix);
            scanf(" %c", &a);
            break;
        default:
            return 0;
        }
    }
    return 0;
}