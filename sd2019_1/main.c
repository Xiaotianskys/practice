#include <stdio.h>


int main()
{
    int i,j;
    int count=0;
    for(i=0;i<100;i++)
    {
        for(j=100;j>i;j--)
        {
            if(i+j==99)
            {
                count++;
                printf("i=%d,j=%d\n",i,j);
                break;
            }
        }
        if(j<=i)
            break;
    }
    printf("count=%d",count);
    return 0;
}
