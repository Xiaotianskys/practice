#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char password[7];   //存放6位密码，最后一位是字符串结束符'\0'

//随机生成一个六位数的密码，返回字符指针
void rand_six_password()
{
    //由于必须同时包含小写字母、大写字母和数字，因此需要随机确定小写字母、大写字母、数字的个数
    int lowerCaseNo=0;
    int upperCaseNo=0;
    int digitsNo=0;
    int count=0;
    int select=0;   //用于选择输入小写字母、大写字母、数字
    char selectLower,selectUpper,selectDigit;
    srand((unsigned)time(NULL));    //设置随机种子
    lowerCaseNo=rand()%4+1; //生成一个1-4的随机数（最多只能4个，因为小写字母、大写字母、数字
    //必须至少各有一个）
    upperCaseNo=rand()%(5-lowerCaseNo)+1;   //随机生成大写字母的个数（5-lowerCaseNo是为了
    //保证至少留一位数字）
    digitsNo=6-lowerCaseNo-upperCaseNo; //数字的个数

    while(count<6)  //循环生成6位密码
    {
        select=rand()%3+1;  //随机选择输入的是大写字母、小写字母，还是数字
        switch(select)
        {
        case 1: //小写字母
            if(lowerCaseNo==0)
                continue;
            selectLower=(char)((rand()%26)+'a');    //随机生成小写子没有
            printf("%c",selectLower);
            password[count]=selectLower;
            lowerCaseNo--;
            count++;
            break;
        case 2: //大写字母
            if(upperCaseNo==0)
                continue;
            selectUpper=(char)((rand()%26)+'A');    //随机生成大写字母
            printf("%c",selectUpper);
            password[count]=selectUpper;
            upperCaseNo--;
            count++;
            break;
        case 3: //数字
            if(digitsNo==0)
                continue;
            selectDigit=(char)((rand()%9)+'0'); //随机生成大写字母
            printf("%c",selectDigit);
            password[count]=selectDigit;
            digitsNo--;
            count++;
            break;
        }
    }
    password[6]='\0';
    printf("\n");
}

int main()
{
    rand_six_password();
    int i;
    for(i=0;i<6;i++)
    {
        printf("%c",password[i]);
    }
    printf("\n");
    return 0;
}
