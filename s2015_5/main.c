#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int i=1;
    double n=1;
    double m=pow(2,31)-1;
    while(n<m)
    {
        printf("%d\n",(int)n);
        n=pow(2,i);
        i++;
    }
    return 0;
}
