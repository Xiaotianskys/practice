#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
argc是命令行总的参数个数，argv[]为保存命令行参数的字符串指针（所有的命令行参数都是以字符串的
形式输入的），其中第0个参数是程序的全名，以后的参数为命令行后面的用户输入的参数，argv参数是
字符串指针数组，其各元素值为命令行中各字符串（参数均按字符串处理）的首地址。指针数组的长度
即为参数的个数argc。数组元素的初值由系统自动赋予（即：argc的大小是系统自动统计的，指的是命令
行参数的个数，包括第0个参数（执行程序的地址））。
*/
int main(int argc,char *argv[]) //char *argv[]或者char **argv,这是命令行参数的一般形式
{
    char *temp;
    int i,j,flag;
    for(i=1;i<argc;i++) //最多进行argc-1轮冒泡排序
    {
        flag=0; //冒泡排序的标志，如果在某一论冒泡时没有进行交换，那么证明已经排序完成，
        //此时就可以跳出循环，结束程序
        for(j=argc-1;j>i-1;j--)
        {
            if(strcmp(argv[j],argv[j-1])<0) //这里使用的是冒泡排序，从后往前冒，将小的往前冒，
            //使得每次最小的都在最前面。且字符串的比较采用的是strcmp函数
            {
                temp=argv[j];
                argv[j]=argv[j-1];
                argv[j-1]=temp;
                flag=1; //如果发生了交换，就置标志flag为1
            }//以上对字符串的排序也体现了一种方法：当需要对字符串进行排序时，使用字符串指针
            //数组来进行排序时更为高效，因为相对于直接交换两个字符串，移动指针的指向更加方便、
            //更加快捷，也更加高效。
        }
        if(flag==0) //如果一轮内层for循环下来，没有发生指针的指向交换，则证明已经有序了，此时
        //不用再继续进行外层for循环了，直接跳出循环即可
        {
            break;
        }
    }
    for(i=0;i<argc;i++) //最后循环输出已经排好序的字符串
    {
        printf("%s\n",argv[i]);
    }
    return 0;
}
