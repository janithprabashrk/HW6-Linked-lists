#include <stdio.h>
#include <stdlib.h>
// node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* insertAtBegin(struct Node* last, int data); // inserts a node at the beginning
struct Node* insertAtEnd(struct Node* last, int data); // inserts a node at the end
struct Node* deleteAtBegin(struct Node* last); // deletes a node from the beginning
struct Node* deleteAtEnd(struct Node* last); // deletes a node from the end

int main(){
    struct Node* last = NULL;
    last=insertAtEnd(last,10);
    last=insertAtEnd(last,20);
    last=insertAtEnd(last,30);
    if(last!=NULL){
        struct Node* temp=last->next;
        printf("After insertion: ");
        do{
            printf("%d->",temp->data);
            temp=temp->next;
        }while(temp!=last->next);
        printf("%d(circular)",last->next->data);
    }
    else{
        printf("Circular linked list is empty.\n");
    }
    last=deleteAtBegin(last);
    last=deleteAtEnd(last);
    printf("\nAfter Deletion: ");
    if(last==NULL){
        printf("----Circular linked list is empty.----\n");
    }
    else{
        struct Node* temp=last->next;
        do{
            printf("%d->",temp->data);
            temp=temp->next;
        }while(temp !=last->next);
        printf("%d",last->next->data);
        printf("(circular,only one node remains)\n");
    }
    return 0;
}
 

struct Node* insertAtBegin(struct Node* last,int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    if(last==NULL){
        last=newNode;
        last->next=last;
    }
    else{
        newNode->next=last->next;
        last->next=newNode;
    }
    return last;
}

struct Node* insertAtEnd(struct Node* last,int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    if (last==NULL) {
        last=newNode;
        last->next=last;
    }
    else{
        newNode->next=last->next;
        last->next=newNode;
        last=newNode;
    }
    return last;
}



struct Node* deleteAtBegin(struct Node* last){
    if (last==NULL){
        printf("----Circular linked list is EMPTY-----\n");
    }
    else{
        struct Node* first=last->next;
        if (first==last){
            free(first);
            last=NULL;
        } 
        else{
            last->next=first->next;
            free(first);
        }
    }
    return last;
}

struct Node* deleteAtEnd(struct Node* last){
    if(last==NULL){
        printf("-----Circular linked list is EMPTY----\n");
    } 
    else{
        struct Node* temp=last->next;
        if(temp==last){
            free(temp);
            last=NULL;
        }
        else{
            while(temp->next!=last){
                temp=temp->next;
            }
            temp->next=last->next;
            free(last);
            last = temp;
        }
    }
    return last;
}