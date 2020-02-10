#include <stdio.h>
#include <stdlib.h>

int main()
{
    int fama[6]={1,2,3,5,10,20};    //砝码种类数组
    int num[6]={5,3,2,2,1,1};   //砝码数量数组
    int flag[100]={0};  //标记数组，一开始全为0
    int i,j;
    int tempweight; //用来存每种砝码能称出的最大重量，每次累加，
    //都是从0开始到当前最大重量
    int newweight;  //加起来后得到的新重量
    int maxweight=0;    //计算出所有砝码能称得到的最大重量
    int currentweight;  //目前能称重的重量，是一个行动指针
    for(i=0;i<6;i++)
        maxweight=maxweight+fama[i]*num[i];
    for(i=0;i<=num[0];i++)  //考虑先计算第0种砝码能称出的重量
        flag[fama[0]*i]=1;  //将能称出重量的标志数组的对应位置为1
    tempweight=fama[0]*num[0];  //这是第0种砝码能称出的最大重量，在后
    //面的计算中，均以0-tempweight之间已经可以称重的来累加上后面的重量，从
    //而得到新的能够称取的重量（动态规划的核心，由前一个推算出后一个）。
    i=1;    //准备计算第1-5种砝码能称的重量（在第0种砝码能称取的基础上进行计算）
    while(i<6)  //总共有5种砝码，所以循环5次（除了已经计算好的第0种砝码）
    {
        for(j=1;j<=num[i];j++)  //第1种砝码，用前面已经计算可以称重的重量来
        //加后面新增的重量
            for(currentweight=0;currentweight<=tempweight;currentweight++)
            //从0开始，将前面的已经能称重的重量加上新增的重量
            {
                newweight=currentweight+j*fama[i];
                if(flag[currentweight]==1&&flag[newweight]==0)
                    flag[newweight]=1;  //如果currentweight能称重，并且
                //newweight还没有能称的话，则表明这种新重量可以称了
            }
        tempweight=tempweight+fama[i]*num[i];   //修改当前能称重的最大
        //值，以便后面能够从0-tempweight累加
        i++;    //计算下一个砝码
    }
    int count=0;
    for(i=0;i<=maxweight;i++)
    {
        if(flag[i]==1)  //如果能称重（对应标志位为1）
        {
            count++;
            printf("%d\t",i);
            if(count%10==0) //每10个换行
                putchar('\n');
        }
    }
    printf("\n以上，总共能称出%d",count);
    system("pause");
    return 0;
}
