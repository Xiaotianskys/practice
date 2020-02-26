#include <stdio.h>

//n为需要移动的盘子的个数，a,b,c代表3根柱子的名称，用char来表示
void hanio(int n,char a,char b,char c)
{
    if(n==1)
    {
        printf("%c->%c\n",a,c); //如果只有一个盘子，则直接从柱a移动到柱c
    }
    else
    {
        hanio(n-1,a,c,b);   //否则递归调用，以c盘为中介，先将n-1个盘子递归从柱a移动到柱b
        printf("%c->%c\n",a,c); //然后将柱a中剩下的一个盘子直接移动到柱c
        hanio(n-1,b,a,c);   //最后以a盘为中介，将n-1个盘子递归的从柱b移动到c
    }
}

int main()
{
    int n;
    printf("请输入要移动的块数：");
    scanf("%d",&n);
    hanio(n,'A','B','C');
    return 0;
}
