#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int year;
    int month;
    int day;
}Data;

typedef struct
{
    int xh;
    char name[100];
    Data birthday;
    int score;
}STU;

int main()
{
    int i,n;
    printf("请输入学生个数\n");
    scanf("%d",&n);
    STU *p=(STU*)malloc(sizeof(STU)*n); //为p动态申请空间，申请n个学生所需要的空
    //间，p是结构体数组的首地址
    STU *q=p;   //这里的q指针其实就是保留整个动态数组的首地址
    for(i=0;i<n;i++)
    {
        printf("请输入第%d个学生的学号\n",i+1);
        scanf("%d",&p->xh);
        printf("请输入第%d个学生的姓名\n",i+1);
        scanf("%s",p->name);    //这里name本来就是一个地址，所以不需要加取地址符
        printf("请输入第%d个学生的生日，如1991.11.26\n",i+1);
        scanf("%d.%d.%d",&p->birthday.year,&p->birthday.month,&p->birthday.day);
        printf("请输入第%d个学生的分数\n",i+1);
        scanf("%d",&p->score);  ///原题这里没有&号
        p++;    ///原题这个语句没有
    }
    p=q;
    for(i=0;i<n;i++)
    {
        printf("%d\t%s\t%d.%d.%d\t%d\n",p->xh,p->name,p->birthday.year
               ,p->birthday.month,p->birthday.day,p->score);
        p++;
    }
    free(q);    ///原题这里是free(p)，因为p已经自增了，
                ///不再是动态申请的结构体数组的首地址了
    return 0;
}
