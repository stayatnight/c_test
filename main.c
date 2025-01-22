#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<stdint.h>
#include<signal.h>
#include<unistd.h>
#include<sys/time.h>


int main()
{
const char src2[]="Are you ok!!!";
//int *a =3;
//a=5;
int8_t ab=9;
int8_t *test_8=&ab;

printf("%d\r\n",*test_8);
//strncpy();
return 0;
}
