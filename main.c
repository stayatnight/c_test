#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define EMPTYHEAD 1

typedef struct Node
{
int number;
int score;
struct Node *next;
} Node;
#if EMPTYHEAD==1
Node*head_insert(Node*head,int num,int sc)
{
    Node*newNode=malloc(sizeof(Node));
    newNode->number=num;
    newNode->score=sc;
    newNode->next=head->next;
    head->next=newNode;
return head;
}
void print_list(Node*head)
{    Node* current = head->next; 
    while(current!=NULL)
    {
        printf("%d %d\n",current->number,current->score);
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
int main(void)
{
#if(EMPTYHEAD==1)
Node*head=malloc(sizeof(Node));
head->next=NULL;
head_insert(head,10,2);
head_insert(head,20,3);
head_insert(head,30,4);
print_list(head);
free_list(head);
#endif


return 0;
}