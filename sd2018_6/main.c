#include <stdio.h>
#include <stdlib.h>

int Reverse(int x)
{
    int rev=0;
    while(x!=0)
    {
        rev=rev*10+x%10;
        x=x/10;
    }
    return rev;
}

int main()
{
    int x;
    scanf("%d",&x);
    if(x==Reverse(x))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
