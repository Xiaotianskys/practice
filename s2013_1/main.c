#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100000

int Reverse(int x)
{
    int rev=0;
    while(x)
    {
        rev*=10;
        rev=rev+x%10;
        x/=10;
    }
    return rev;
}

int main()
{
    int abc[MAX];
    int i,j;
    int count=0;
    for(i=0;i<MAX;i++)
    {
        abc[i]=1;
    }
    abc[0]=abc[1]=0;
    for(i=2;i<MAX;i++)
    {
        if(abc[i]==1)
        {
            for(j=2;j<sqrt(i);j++)
            {
                if(i%j==0)
                {
                    abc[i]=0;
                    break;
                }
            }
            if(i<320)   //320*320>100000
                if(abc[i]==0)
                {
                    for(j=i*i;j<MAX;j=j+i)
                    {
                        abc[j]=0;
                    }
                }
        }
        if(abc[i]==1&&Reverse(i)==i)
        {
            printf("%6d",i);
            count++;
            if(count%10==0)
                printf("\n");
        }
    }
    /*
    i=0;
    while(i<MAX)
    {
        if(abc[i]==1&&Reverse(i)==i)
            printf("%d\n",i);
        i++;
    }*/
    return 0;
}
