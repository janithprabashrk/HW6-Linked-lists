#include <stdio.h>
#include <stdlib.h>
// node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* insert(struct Node* head, int data); // inserts a node
struct Node* delete(struct Node* head, int key); // deletes a node with the given key

int main() {
    int key;
    struct Node* head = (struct Node*)malloc(sizeof(struct Node)); 
    // head node
    head->next=NULL;
    head->data=0;
    // insert nodes and print the header linked list
    head=insert(head,10);
    head=insert(head,20);
    head=insert(head,30);
    head=insert(head,40);
    head=insert(head,50);
    printf("After insertion: ");
    struct Node* current=head->next;
    printf("%d-> ",head->data);
    while(current!=NULL){
        printf("%d ",current->data);
        if(current->next!=NULL){
            printf("-> ");
        }
        current=current->next;
    }
    printf("\nEnter Key you want to delete :");
    scanf("%d",&key);
    head=delete(head,key);// delete a node
    // print the header linked list after deletion
    current=head->next;
    printf("After deletion: ");
    printf("%d-> ",head->data);
    while(current!=NULL){
        printf("%d ",current->data);
        if(current->next!=NULL){
            printf("-> ");
        }
        current=current->next;
    }
return 0;
}

struct Node* insert(struct Node* head,int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=head->next;
    head->next=newNode;
    head->data++;

    return head;
}

struct Node* delete(struct Node* head,int key){
    struct Node* current=head->next;
    struct Node* prev=head;
    while(current != NULL) {
        if(current->data==key){
            prev->next=current->next;
            free(current);
            head->data--;

            break;
        }
        prev=current;
        current=current->next;
    }
    return head;
}