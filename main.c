#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Node
{
int number;
int score;
struct Node *next;
} Node;
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
    while(current->next!=NULL)
    {
        printf("%d %d\n",current->number,current->score);
        current=current->next;
    }
}
int main(void)
{
Node*head=malloc(sizeof(Node));
head->next=NULL;
head_insert(head,10,2);
//head_insert(head,20,3);
//head_insert(head,30,4);
print_list(head);
return 0;
}