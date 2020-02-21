#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x1;
    int x2;
    printf("请输入待计算乘积的函数x1和x2: ");
    scanf("%d",&x1);
    scanf("%d",&x2);
    printf("%d*%d=%d\n",x1,x2,x1*x2);
    system("pause");
    return 0;
}
