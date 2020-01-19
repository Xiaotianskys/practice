#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int n=0;
    int i,j;
    char str[10];
    gets(str);
    int len=strlen(str);
    for(i=0;i<len;i++)
    {
        double c = pow(10,len-1-i);
        n=n+(str[i]-'0')*c;
    }
    printf("%d\n",n);
    int flag1=1,flag2=1;
    for(i=2;i<=n/2;i++)
    {
        if(n%i==0)
        {
            flag1=0;
        }
    }
    for(i=0;i<len/2;i++)
    {
        if(str[i]!=str[len-1-i])
            flag2=0;
    }
    if(flag1&&flag2)
    {
        printf("%s\n","T");
    }
    else
    {
        printf("%s\n","F");
    }
    return 0;
}
