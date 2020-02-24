#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,i;
    printf("请任意输入一个待因式分解的整数x：");
    scanf("%d",&x);
    printf("%d=",x);
    for(i=2;i<=x;i++)
    {
        while(x!=1)
        {
            if(x%i==0)
            {
                printf("%d",i);
                x=x/i;
                if(x!=1)
                    printf("*");
            }
            else
                break;
        }
    }
    putchar('\n');
    system("pause");
    return 0;
}
