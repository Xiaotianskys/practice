#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i;
    printf("请输入一个待因式分解的整数n：");
    scanf("%d",&n);
    printf("%d=",n);
    for(i=2;i<=n;i++)
    {
        while(i<=n) //当没有除尽的时候循环，证明整数仍有待分解
        {
            if(n%i==0)  //如果能除尽的话
            {
                printf("%d",i);     //输出因式分解的一个数
                if(n!=i)
                {
                    printf("*");    //当最后一个除了之后，不在需要*号了，限制最后一个不输出*号
                }
                n=n/i;              //能除尽，便把n分解，变成n/i;
            }
            else
                break;      //否则，当无法除尽时，便让i+1（在外层for循环中自增）
        }
    }
    putchar('\n');    //输出一个换行符
    system("pause");
    return 0;
}
