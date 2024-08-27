#include"stdio.h"
#include"stdlib.h"
#include"string.h"
typedef struct Node{
int data;
struct Node *next;
struct Node*prev;
}*zjlist;
zjlist create_node(int data)
{
zjlist temp=(zjlist)malloc(sizeof(struct Node));
if(temp==NULL)
{
    printf("malloc error\n");
    exit(0);
}
temp->data=data;
//temp->next=temp;
//temp->prev=temp;
temp->next=NULL;
temp->prev=NULL;
return temp;
}
void print_list(zjlist head)
{
    zjlist temp=(zjlist)malloc(sizeof(struct Node));
    while(head->next!=NULL)
    {
        printf("%d\n",head->data);
        head=head->next;
    }
}
zjlist insert_node(zjlist head,int data)
{
    zjlist temp=create_node(data);
    temp->next=head;
    temp->prev=head->prev;
    head->prev=temp;
    head->prev->next=temp;
    return head;
}

int main(void)
{
    zjlist head=create_node(0);
   head= insert_node(head,1);
    head=insert_node(head,2);
        print_list(head);
  //  printf("head is %d\n",head->data);
return 0;
}