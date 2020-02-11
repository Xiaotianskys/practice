#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    scanf("%d",&x);
    int i=2;
    while(x/i>0)
    {
        if(x%i==0)
        {
            printf("%d",i);
            x=x/i;
            if(x!=1)
            {
                printf("*");
            }
        }
        else
        {
            i++;
        }
    }
    return 0;
}
