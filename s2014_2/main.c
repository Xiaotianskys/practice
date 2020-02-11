#include <stdio.h>
#include <stdlib.h>
#define MAX 50

char abc[MAX][MAX];

int main()
{
    int i,j,n;
    printf("Please input x: ");
    scanf("%d",&n);
    for(i=0;i<MAX;i++)
    {
        for(j=0;j<MAX;j++)
            abc[i][j]=' ';
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<2*n-1;j++)
        {
            if(i+j==n-1||j-i==n-1)
                abc[i][j]='1';
            if(i-1>=0&&j-1>=0&&j+1<2*n-1&&abc[i-1][j-1]!=' '&&abc[i-1][j+1]!=' ')
                abc[i][j]=abc[i-1][j-1]+abc[i-1][j+1]-'0';
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<2*n-1;j++)
        {
            if(abc[i][j]!=' ')
                printf("%2d",abc[i][j]-'0');
            else
                printf("%c ",abc[i][j]);
        }
        printf("\n");
    }
    return 0;
}
