#include <stdio.h>
#include <stdlib.h>

int Reverse(int x)
{
    int rev=0;
    while(x)
    {
        rev=rev*10+x%10;
        x/=10;
    }
    return rev;
}

int main()
{
    int i;
    int count=0;
    for(i=0;i<65535;i++)
    {
        if(i==Reverse(i))
        {
            printf("%6d",i);
            count++;
            if(count%15==0)
                putchar('\n');
        }
    }
    return 0;
}
