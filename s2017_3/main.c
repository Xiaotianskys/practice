#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXN 10

int getdigit()
{
    int magic;
    //srand(time(NULL));  //这句代码千万不要写在函数用，不然代码运行速度特别慢
    //因为只要是秒针相同，每次随机出来的第一个数必然相同，但是如果把这句话写在外面
    //的话，就可以使用上一次随机种子所随机的下一个数
    magic=rand()%100+1;
    return magic;
}

int main()
{
    int number[MAXN]={0};
    int i=0;
    srand(time(NULL));  //为函数rand()设置随机种子
    while(i<MAXN)
    {
        int num=getdigit();
        int temp=1;
        for(int j=0;j<i;j++)
        {
            if(num==number[j])
            {
                temp=0;
                break;
            }
        }
        if(temp==1)
        {
            number[i]=num;
            i++;
        }
    }
    for(i=0;i<MAXN;i++)
    {
        printf("%d ",number[i]);
    }
    return 0;
}
