#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i,j;    //i数组下标
    int a[10];  //用于存放10个不重复的随机数
    srand((unsigned)time(0));   //设置seed种子随时间变化，永远都不会相同
    for(i=0;i<9;i++)    //生成9个不重复的随机数，对于随机数如果要确定小于n，可以用rand()%n的
    //方法，此时得到的是0-n（不包含n）
    {
        a[i]=rand()%100;    //先生成一个随机数，之后再同前面的随机数检查，看是否相同
        //（使生成的随机数处于0-99）
        for(j=0;j<i;j++)    //同0-i-1检查，看是否相同
        {
            if(a[j]==a[i])  //如果有存在相等的话，则重复了，应重新生成
            {
                a[i]=rand()%100;    //随机数已经存在，考虑重新生成并判断
                i=-1;
                break;  //i=-1之后，跳出循环，不用再检查了，因为已经重复了，此时外层循环又
                //从i=0开始重新检查
            }
        }
    }
    for(i=0;i<10;i++)    //输出随机生成的10个不重复的随机数
        printf("%d ",a[i]);
    putchar('\n');
    system("pause");
    return 0;
}
