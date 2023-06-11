#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int age;
    struct Node *next;
} node;

void deleteNode(node**,int);
void printList(node*);

int main(){

    node *head = malloc(sizeof(node));
    head->age = 18;
    node *iter = head;
    int i;
    for(i=0 ; i<5 ; i++){
        iter->next = malloc(sizeof(node));
        iter = iter->next;
        iter->age = i+10;
        iter->next = NULL;
    }
    
    int s_age;

    printList(head);
    printf("Enter the student age to be deleted: ");
    scanf("%d", &s_age);

    deleteNode(&head, s_age);
    printList(head);


    return 0;
}
void deleteNode(node **head_ptr, int age){
    node *temp, *iter = *head_ptr;

    if( (*head_ptr)->age == age ){
        temp = *head_ptr;
        *head_ptr = (*head_ptr)->next;
    }
    else{
        while( iter->next != NULL && iter->next->age != age )
            iter = iter->next;
        temp = iter->next;
        iter->next = iter->next->next;
    }
    free(temp);
}
void printList(node *p){
    while( p != NULL ){
        printf("%d ", p->age);
        p = p->next;
    }
    printf("\n");
}
