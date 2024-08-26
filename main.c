#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
int n=0;
while (~scanf("%d", &n))
{
    if(n%2==0)
    {
        printf("even\n");
    }
    else
    {
        printf("odd\n");
    }   
}
return 0;
}