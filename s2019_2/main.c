#include <stdio.h>
#include <stdlib.h>

void move(char a,char b)
{
    printf("%c->%c\n",a,b);
}

void hanno(char a,char b,char c,int n)
{
    if(n>1)
    {
        hanno(a,c,b,n-1);
        move(a,c);
        hanno(b,a,c,n-1);
    }
    else
    {
        move(a,c);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    hanno('a','b','c',n);
    return 0;
}
