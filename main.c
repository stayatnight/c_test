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
{    
    while(head!=NULL)
    {
        printf("%d",head->number);
        printf("\n");
        head=head->next;
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
Node* makeList() {
    int x;
    Node* pNewCell;
    if (scanf("%d", &x) == EOF) {
//使用ctrl+d结束输入,在linux下
        printf("\n");
        return NULL;
    } else {
        pNewCell = (Node*) malloc(sizeof(Node));
        pNewCell->number = x;
        pNewCell->next = makeList();
        return pNewCell;
    }
}
int main(void)
{
Node*List=makeList();
print_list(List);
free_list(List);
return 0;
}