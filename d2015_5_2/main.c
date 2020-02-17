#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int mi2(int n)  //判断是否为2的幂
{
    if(n<1) //小于1必然不是2的幂
        return 0;
    else
    {
        if((n&(n-1))==0)  //n与n-1的二进制进行按位与为0时，则是2的幂
            return 1;
        else
            return 0;
    }
}

int main()
{
    int i;
    int j=0;    //计数换行
    int k=pow(2,sizeof(int)*8-2);
    for(i=1;i<=k;i=i*2)
        if(mi2(i))
        {
            printf("%10d\t",i);
            j++;
            if(j%5==0)
                putchar('\n');  //每10个输出一行
        }
    return 0;
}
