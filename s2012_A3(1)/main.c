#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char str[30];
    int count;
}Node,*Linklist;

//判断是否是字母的函数，如果是字母则返回1，统计单词个数的时候不会区分大小写
int zimu(char *c)
{
    if(*c>='a'&&*c<='z')
        return 1;
    if(*c>='A'&&*c<='Z')//凡是大写字母最终都会转化为小写字母
    {
        *c=*c+32;
        return 1;
    }
    return 0;
}

/*
通过折半查找，要插入的位置（如果原数组中有相同的元素，则直接count++；
如果原数组中没有相同的元素，则需要按序插入合适的位置，此时count=1；）
*/
void zheban(Linklist p[],Node *newnode,int *index)
{
    int low,high;
    int mid;    //折半查找的三个参数，不必多说
    int i;
    if(*index==-1)//当数组中什么都没有的时候，需要特别考虑
    {
        p[0]=newnode;
        *index=*index+1;
    }
    else
    {
        low=0;
        high=*index;
        while(high>=low)    //注意这里一定是>=,不然当mid=high=low的时候就有错误
        {
            mid=(low+high)/2;
            if(strcmp(newnode->str,p[mid]->str)>0)
            {
                low=mid+1;
            }
            else if(strcmp(newnode->str,p[mid]->str)<0)
            {
                high=mid-1;
            }
            else if(strcmp(newnode->str,p[mid]->str)==0)
            {
                break;
            }
        }
        if(low>high)
        {
            for(i=*index;i>=low;i--)    //集体后移
            {
                p[i+1]=p[i];
            }
            p[low]=newnode;     //插入适当的位置
            /*
            （*p）++相当于a++,即将指针变量P所表示的变量的值加1。而*P++等价于*(P++)，
            这时先将p值加1，p不再指向a，而是指向a所占存储区域的后续位置，再取其内存值
            */
            *index=*index+1;    //千万不要写成*index++,表示是指针的位置加一
        }
        else
        {
            p[mid]->count++;
            free(newnode);      //不用的newnode要及时free掉，否则会造成内存泄漏
        }
    }
}

int main()
{
    int i=0;
    int j=0;
    int k=-1;
    int word;
    Linklist Q[100]={0};    //单词类别及其次数指针数组
    char p[1000];           //输入的一段话存放位置
    char s[30];             //话中提取出来的单词提取出来的位置
    gets(p);
    int L = strlen(p);      //输入话的话长
    printf("strlen==============%d\n",L);
    while(i<(L+1))
    {
        word=0;
        if((i==0&&zimu(&p[i]))||(!zimu(&p[i-1])&&zimu(&p[i])))  //单词首字母判定标志
        {
            word=1;     //拷贝进入s的标志位
            j=0;        //开始拷贝的标志位
        }
        else if(zimu(&p[i]))
        {
            word=1;     //拷贝进入s的标志位
            j++;
        }
        if(word==1)
        {
            s[j]=p[i];  //通过对j变量进行处理j++，按字符逐个拷贝
        }
        if(word==0)
        {
            s[j+1]='\0';    //拷贝完毕后千万别忘记在最后加入'\0'，以构成字符串
            Node *q=(Node*)malloc(sizeof(Node));    //初始化
            strcpy(q->str,s);
            q->count=1;
            zheban(Q,q,&k);//这句话执行完之后就不用k++了，因为这里k为模拟引用调用，函数中就可以改变其值
        }

        i++;
    }
    //打印出最后的结果
    for(i=0;i<=k;i++)
    {
        printf("%s:\t%d\n",Q[i]->str,Q[i]->count);
    }
    system("pause");
    return 0;
}
