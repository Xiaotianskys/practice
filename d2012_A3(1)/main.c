#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char s[20]; //用于存放单词
    int count;  //用于存取本单词的个数
    struct node *next;
}Node,*Linklist;

/*判断是否为字母的函数，考虑大小写的单词应该是一样的，这里之所以在形参
用指针的形式是由于要将大写字母转为小写字母，所以用指针才能保证形参的改变
影响到实参
*/
int zimu(char *c)
{
    if(*c>='a'&&*c<='z')    //小写字母直接确认即可
    {
        return 1;
    }
    if(*c>='A'&&*c<='Z')    //大写字母时，这里考虑判断，并把大写转小写
    {
        *c=*c+32;
        return 1;
    }
    else
        return 0;
}

void binary_search(Linklist p[],int *index,Linklist newnode)    //二分查找的函数
{
    int low,high;   //二分查找的高低指针
    int mid;
    int i;
    if(*index==-1)  //证明指针数组是空的
    {
        p[0]=newnode;   //此时，直接将指针数组第0个元素指向该结点
        (*index)++;
    }
    else    //开始二分查找，指针数组应该按照字符串的大小排序（从小到大排序）
    {
        low=0;
        high=*index;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(strcmp(p[mid]->s,newnode->s)>0)
            {
                high=mid-1;
            }
            else if(strcmp(p[mid]->s,newnode->s)<0)
            {
                low=mid+1;
            }
            else if(strcmp(p[mid]->s,newnode->s)==0)    //相等
            {
                break;
            }
        }
        if(low<=high)   //如果最后low<=high,证明这个单词是存在的，把相应的字符串++
        {
            (p[mid]->count)++;
            return;
        }
        else    //否则low>=high,证明该字单词是不存在的，应该插入，且插入位置是low所在的位置
        {
            for(i=*index;i>=low;i--)
            {
                p[i+1]=p[i];    //后移
            }
            p[low]=newnode;     //插入，p[low]指向newnode
            (*index)++;         //元素+1
            return;
        }
    }
}

int main()
{
    Linklist *p;    //指针数组
    int i,l,word=0; //word是单词标记
    int k;
    int index=-1;   //指针数组的下标
    Linklist newnode;   //用于申请新结点
    int count_danci=0;
    char s[1000];   //用于存放要判断的英文语句（假定语句的长度为1000）
    char str[20];   //用于存放单词
    printf("请输入待处理的英文语句：\n");   //这里也有可能是直接从文件中读出这个语句，
    //因为题目中说的是涉及文件操作。但是无论是自己写语句还是从文件读，基本都是差不多的，
    //所以这里省略了从文件中读的过程
    gets(s);    //输入待处理的英文语句
    l=strlen(s);
    p=(Linklist*)calloc(1000,sizeof(Linklist));     //指针数组的头指针p，是一个二级指针
    word=0;     //先另单词标记word=0
    for(i=0;i<=l;i++)
    {
        if(i==l&&!zimu(&s[i-1]))
            break;
        if((!zimu(&s[i])&&i-1>=0&&zimu(&s[i-1]))||(i==l&&zimu(&s[i-1])))
        //证明单词结束了，应该放入新结点newnode
        {
            str[k]='\0';
            newnode=(Linklist)calloc(1,sizeof(Node));   //申请新结点
            newnode->count=1;   //数量为1
            strcpy(newnode->s,str);     //将单词放入新结点
            binary_search(p,&index,newnode);    //进行折半查找
        }
        if(!zimu(&s[i]))
            word=0;     //不是字母，则令单词标记=0
        else if(word==0)    //证明找到单词的开始了，我们应该考虑将单词放到
        //某个地方，待单词结束后再放入链表中
        {
            k=0;
            word=1; //令单词标记=1
            count_danci++;
        }
        if(word==1)
        {
            str[k]=s[i];
            k++;
        }
    }
    printf("不同单词数index=%d\n",index+1);
    for(i=0;i<=index;i++)
    {
        printf("%s\t%d\n",p[i]->s,p[i]->count);
    }
    system("pause");
    return 0;
}
