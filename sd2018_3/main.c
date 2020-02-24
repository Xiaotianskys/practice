#include <stdio.h>

double collect(double (*p)(double),double a,double b,int n)
/*
原题中：double (*p)(double)是double *p。
这里的p实际上指的是函数f，因此我们应该使用指向函数f的指针作为形参，而不是直接用
double*型指针作为形参，应修改为double(*p)(double)，其能够指向函数f
*/
{
    double h,area;  //注：这里是改错。area的作用是累加得到最终的面积，需要初始化为0
    area=0; //原题中没有这一行代码
    int i;
    h=(b-a)/n;  //很明显，这里的作用是将底边的a-b分成n份，每份的长为h，用长*宽并累加以求
    //取面积
    for(i=0;i<100;i++)
    {
        area+=((*p)(a+i*h)+(*p)(a+(i+1)*h))*h/2;
        //这里采用的面积公式是梯形的公式：（上底+下底）*高h/2.将各个小的梯形累加（即积分），
        //最后即可得到曲线的积分（曲线下a-b的面积）
    }
    return area;
}

double f(double x)  //f函数的作用实际就是我们要求取的积分函数，本处为f(x)=1+x^3
{
    return 1+x*x*x;
}

int main()
{
    double sum;
    sum=collect(f,-1,1,100);
    //原题中f是f()
    //这里以f作为实参，不应该包含括号，
    printf("%lf\n",sum);
    return 0;
}
