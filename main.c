#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct pr_test
{
int (*sum)(int a,int b);
int (*mul)(int a,int b);
}pr;

int __sum(int a ,int b)
{
    return a+b;
}
int __mul(int a,int b)
{
    return a*b;
}
int main()
{
pr test ;
test.sum=__sum;
test.mul=__mul;
while(1)
{
    //回调测试
    #if 0
    printf("%d\n",test.sum(10,11));
    printf("%d\n",test.mul(10,11));
    printf("%d\n",test.sum(10,12));
    printf("%d\n",test.mul(10,12));
    printf("%d\n",test.sum(10,13));
    #endif

}
}
