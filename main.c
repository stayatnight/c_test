#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define EMPTYHEAD 1
typedef struct Node
{
int number;
struct Node *next;
} Node;
#if EMPTYHEAD==1
Node*head_insert(Node*head,int num)
{
    Node*newNode=malloc(sizeof(Node));
    newNode->number=num;
    newNode->next=head->next;
    head->next=newNode;
return head;
}
void print_list(Node*head)
{    Node* current = head->next; 
    while(current!=NULL)
    {
        printf("%d \n",current->number);
        current=current->next;
    }
}
void free_list(Node*head)
{
    Node*current=head->next;
    while(current!=NULL)
    {
        Node*temp=current;
        current=current->next;
        free(temp);
    }
    free(head);
}
#endif
#if EMPTYHEAD==0
Node*head_insert(Node*head,int num,int sc)
{
    Node*newNode=malloc(sizeof(Node));
    newNode->number=num;
    newNode->score=sc;
    newNode->next=head;
    head=newNode;
    return head;
}
#endif
Node*split(Node*list)
{
Node* fast =list, *slow = list,*temp;
    while(fast->next!=NULL && fast->next->next != NULL)
    {
    fast=fast->next->next;
    slow=slow->next;
    }
    temp=slow->next;
    slow->next=NULL;
    return temp;
}
int main(void)
{
#if(EMPTYHEAD==1)
Node*head=malloc(sizeof(Node));
head->next=NULL;
int num;
while(~scanf("%d",&num))
{
    if(num==-1)
    {
    printf("\n");
        break;
    }
    head=head_insert(head,num);
}
int j;
Node*temp_list=split(head);
print_list(head);
print_list(temp_list);
int test[]={1,2,2,3};
int *a =test;
#endif
free_list(head);
free_list(temp_list);
return 0;
}