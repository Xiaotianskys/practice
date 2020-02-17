#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int mi2(int n)  //用来判断是否为2的幂的数
{
    int count=0;    //用count来记录是多少次幂，本题可以不用记录count
    if(n<1)
        return 0;   //小于1一定不是2的幂
    else if(n==1)
        return 1;   //等于1是2的0次幂
    else
    {
        while(n!=1) //当n不是1时，可以考虑循环除以2
        {
            if(n%2!=0)  //首先判断能否除尽2，不能整除2则一定不是2的幂
            {
                return 0;
                break;
            }
            else if(n==2)   //在能整除2时，如果本来就是2，则表明是2的幂
            {
                return 1;
                break;
            }
            else    //能整除2但不是2时，则考虑继续n/2除下去，判断除以2之后的情形，最后如果
            //不是2的幂，会在第一个if跳出循环，是2的幂则在第二个if跳出循环
                n=n/2;
        }
    }
}

int main()
{
    int i;
    int j=0;    //j用来控制每行的输出数
    double k=pow(2,sizeof(int)*8-2);    //得到int型最大的数，其实只能到2^30（共
    //32位，-2^31-1~2^31-1），所以要减2
    for(i=1;i<=k;i=i*2) //在int范围内寻找2的幂的数
        if(mi2(i))
        {
            printf("%10d\t",i);
            j++;    //j即为2的幂的数的个数
            if(j%5==0) //每十个输出一行
                printf("\n");
        }
    system("pause");
    return 0;
}
