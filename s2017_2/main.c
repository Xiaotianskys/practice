#include <stdio.h>
#include <stdlib.h>

int main()
{
    int abc[100]={0};
    abc[0]=1;
    int i,n,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            printf(" ");
        }
        for(j=0;j<=i;j++)
        {
            printf("%d ",abc[j]);
        }
        if(i==0)
        {
            abc[i+1]=1;
        }
        else
        {
            abc[i+1]=1;
            for(j=i;j>0;j--)
            {
                abc[j]=abc[j-1]+abc[j];
            }
        }
        printf("\n");
    }
    return 0;
}
