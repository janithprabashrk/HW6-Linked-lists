#include <stdio.h>
#include <stdlib.h>
// node structure
struct Node{
 int data;
 struct Node* prev;
 struct Node* next;
};
struct Node* insertAtBegin(struct Node* last, int data); // inserts a node at the beginning
struct Node* insertAtEnd(struct Node* last, int data); // inserts a node at the end
struct Node* deleteAtBegin(struct Node* last); // deletes a node from the beginning
struct Node* deleteAtEnd(struct Node* last); // deletes a node from the end
int main(){
    struct Node* last = NULL;
    // insert nodes and print the circular doubly linked list
    last = insertAtEnd(last,10);
    last = insertAtEnd(last,20);
    last = insertAtEnd(last,30);
    if (last == NULL){
        printf("List is empty.\n");
        return 0;
    }
    struct Node* temp=last->next;
    printf("After insertion: ");
    while(temp!=last){
        printf("%d <-> ",temp->data);
        temp=temp->next;
    }
    printf("%d <-> %d",temp->data,temp->next->data);
    printf("(circular)\n");
    last = deleteAtBegin(last);
    last = deleteAtEnd(last);
    temp=last->next;
    // print the circular doubly linked list after deletion
    if (last==NULL){
        printf("List is empty.\n");
        return 0;
    }
    printf("After deletion: ");
    while(temp!=last){
        printf("%d <-> ",temp->data);
        temp=temp->next;
    }
    printf("%d <-> %d",temp->data,temp->next->data);
    printf("(circular, only one node remains)\n");
return 0;
}

struct Node* insertAtBegin(struct Node* last,int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    if(last==NULL){
        newNode->prev=newNode;
        newNode->next=newNode;  
        last=newNode;           
    }else{
        struct Node* start=last->next;
        start->prev=newNode;
        newNode->next=start;
        newNode->prev=last;
        last->next=newNode;       
    }
    return last;
}


struct Node* insertAtEnd(struct Node* last,int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    if(last==NULL){
        newNode->prev=newNode;
        newNode->next=newNode;
        last=newNode;
    }else{
        struct Node* first=last->next;
        last->next=newNode;
        newNode->prev=last;
        newNode->next=first;
        first->prev=newNode;
        last=newNode;
    }
    return last;
}

struct Node* deleteAtBegin(struct Node* last){
    if(last==NULL){
        printf("List is empty.\n");
    }else if(last->next==last){
        free(last);
        last=NULL;
    }else{
        struct Node* first=last->next;
        struct Node* second=first->next;
        last->next=second;
        second->prev=last;
        free(first);
    }
    return last;
}

struct Node* deleteAtEnd(struct Node* last){
    if(last==NULL){
        printf("List is empty...\n");
    }else if (last->next==last){
        free(last);
        last=NULL;
    }else{
        struct Node* befLast=last->prev;
        struct Node* first=last->next;
        befLast->next=first;
        first->prev=befLast;
        free(last);
        last=befLast;
    }
return last;
}