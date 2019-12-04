#include <stdio.h>
#include <stdlib.h>
int n,m,i,j,a[100][100],at[100][100];
int main()
{
    scanf("%d %d", &n, &m);
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            scanf("%d", &a[i][j]);
    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
            at[i][j]=a[j][i];
    for(i=1; i<=m; i++)
    {
        for(j=1; j<=n; j++)
            printf("%d ", at[i][j]);
        printf("\n");
    }
    return 0;
}
