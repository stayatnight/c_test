#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define EMPTYHEAD 1
//单项链表，头结点非空
typedef struct Node{
    int data;
    struct Node *next;
}*List;
//单链表插入函数
void insert(List *head,int data){
    List p = (List)malloc(sizeof(struct Node));
    p->data = data;
    p->next = *head;
    *head = p;
}
//单链表删除函数
void delete(List *head,int data){
    List p = *head;
    if(p->data == data){
        *head = p->next;
        free(p);
        return;
    }
    while(p->next->data != data){
        p = p->next;
    }
    List q = p->next;//q为要删除的结点
    p->next = q->next;
    free(q);    
}
//单链表查找函数
List search(List head,int data){
    List p = head;
    while(p->data != data){
        p = p->next;
    }
    return p;
}
//单链表打印函数
void print(List head){
    List p = head;
    while(p->next != NULL){
        printf("%d ",p->next->data);
        p = p->next;
    }
    printf("\n");
}
//单链表反转函数
List reverse(List head){
    List p = head->next;
    List q = p->next;
    p->next = NULL;
    while(q != NULL){
        List r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    head->next = p;
    return head;
}
//单链表合并函数
List merge(List head1,List head2){
    List p = head1;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = head2->next;
    free(head2);
    return head1;
}
//单链表删除重复元素函数    
void deleteRepeat(List head){
    List p = head;
    while(p->next != NULL){
        List q = p->next;
        while(q->next != NULL){
            if(p->data == q->next->data){
                List r = q->next;
                q->next = r->next;
                free(r);
}
            else{
                q = q->next;
            }   
        }
        p = p->next;    
    }
}
//单链表删除倒数第n个结点函数
void deleteLastN(List head,int n){
    List p = head;
    List q = head;
    for(int i = 0;i < n;i++){
        q = q->next;
    }
    while(q->next != NULL){
        p = p->next;
        q = q->next;
    }
    List r = p->next;
    p->next = r->next;
    free(r);
}
//单链表判断是否为回文函数

int isPalindrome(List head){
    List p = head;
    List q = head;
    while(q->next != NULL && q->next->next != NULL){
        p = p->next;
        q = q->next->next;
    }
    List r = p->next;
    p->next = NULL;
    r = reverse(r);
    p = head;   
    while(r != NULL){
        if(p->data != r->data){
            return 0;
        }
        p = p->next;
        r = r->next;
    }
    return 1;
}

int main() {
    
}