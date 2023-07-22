#include <stdio.h>
#include <stdlib.h>
// node structure
struct Node {
 int data;
 struct Node* next;
};
struct Node* sortLinkedList(struct Node* head); // sorts the linked list
struct Node* deleteLinkedList(struct Node* head); // deletes the entire linked list

int main(){
    struct Node *head=NULL,*current=NULL;
    int temp, a;

    printf("Enter the number of elements you want to add: ");
    scanf("%d",&a);

    for(int i = 0; i<a;i++){
        printf("Enter element %d: ",i+1);
        scanf("%d",&temp);

        if(i==0){
            head=(struct Node*)malloc(sizeof(struct Node));
            current=head;
        } else {
            current->next=(struct Node*)malloc(sizeof(struct Node));
            current=current->next;
        }

        current->data=temp;
        current->next=NULL;
    }

    printf("\nInput:");
    current=head;
    while (current!=NULL) {
        printf("%d",current->data);
        if (current->next != NULL) {
        printf("->");
        }
        current=current->next;
    }
    printf("\b");

    head=sortLinkedList(head);

    printf("\nsorted list :");
    current=head;
    while(current != NULL) {
        printf("%d",current->data);
        if (current->next != NULL) {
        printf("->");
        }
        current = current->next;
    }
    printf("\b");
    deleteLinkedList(head);
    printf("\nLinked list is deleted.\n");

    return 0;
}

struct Node* sortLinkedList(struct Node* head){
    if(head==NULL||head->next==NULL)
        return head;

    int x;
    struct Node* current;
    struct Node* last = NULL;

    do{
        x=0;
        current=head;

        while(current->next!=last){
            if (current->data<current->next->data){ // Change the comparison operator to sort in descending order
                int temp=current->data;
                current->data=current->next->data;
                current->next->data=temp;
                x=1;
            }
            current=current->next;
        }
        last=current;
    }while(x);

    return head;
}

struct Node* deleteLinkedList(struct Node* head) {
    struct Node* current=head;
    struct Node* nextNode;

    while(current!=NULL) {
        nextNode=current->next;
        free(current);
        current=nextNode;
    }

    return 0;
}