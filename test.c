#include<stdio.h>
void function()
{
    int num_of_letter=0,num_of_dig=0,num_of_dig_other=0,num_of_spec=0;
    char str[100];
   // scanf("%s",str);
fgets(str, sizeof(str), stdin);
for(int i=0;str[i]!='\0';i++)
{
    if(((int)str[i]>=65&&(int)str[i]<=90)||((int)str[i]>=97&&(int)str[i]<=122))
        num_of_letter++;
    else if((int)str[i]>=48&&(int)str[i]<=57)   
        num_of_dig++;
    else if((int)str[i]==32)
    num_of_spec++;
    else if((int)str[i]!='\n')
    {
        num_of_dig_other++;
    }
}
  printf("%d %d %d %d\n",num_of_letter,num_of_dig,num_of_spec,num_of_dig_other);

}