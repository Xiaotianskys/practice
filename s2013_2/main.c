#include <stdio.h>
#include <stdlib.h>

#define MAX 60

int zhongliang[MAX]={0};

int main()
{
    int a,b,c,d,f,e;
    int i;
    for(a=0;a<=5;a++)
    {
        for(b=0;b<=3;b++)
        {
            for(c=0;c<=2;c++)
            {
                for(d=0;d<=2;d++)
                {
                    for(e=0;e<=1;e++)
                    {
                        for(f=0;f<=1;f++)
                        {
                            zhongliang[a+b*2+c*3+d*5+e*10+f*20]=1;
                        }
                    }
                }
            }
        }
    }
    int count=0;
    printf("所有的重量是：\n");
    for(i=0;i<MAX;i++)
    {
        if(zhongliang[i]==1)
        {
            printf("%3d",i);
            count++;
        }
        if(count%10==0)
            printf("\n");
    }
    return 0;
}
