#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Please input a number: ");
    scanf("%d",&n);
    int i=2;
    while(n!=1) //注意：这里不是n!=0
    {
        if(n%i==0)
        {
            if(n!=i)
                printf("%d*",i);
            else
                printf("%d",i);
            n/=i;
            continue;
        }
        i++;
    }
    return 0;
}
