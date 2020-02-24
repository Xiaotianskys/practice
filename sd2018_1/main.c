#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int i,j,sum=0,flag;
    for(i=2;i<=100;i++) //循环判断100以内的素数
    {
        flag=0; //先置flag为0，即先假定其就是一个素数
        for(j=2;j<=sqrt(i);j++) //通过这里的2—sqrt(i)，我们可以知道这里是用来判断素数的
        //（因为只要i能够整除（除尽）2—sqrt(i)中任何一个数，那么i就不是素数）
        {
            if(i%j==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            sum+=i;
        }
    }
    printf("%d\n",sum);
    return 0;
}
