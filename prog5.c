#include <stdio.h>
#include <stdlib.h>

// node structure
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};
struct Node* insert(struct Node* head, int coeff,int exp); // inserts a term
struct Node* addPolynomials(struct Node* poly1,struct Node* poly2); // adds two polynomials
struct Node* subtractPolynomials(struct Node* poly1, struct Node* poly2); // subtracts two polynomials

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    // insert terms into poly1 and poly2
    poly1 = insert(poly1,3,2);
    poly1 = insert(poly1,2,1);
    poly1 = insert(poly1,1,0);
    poly2 = insert(poly2,1,2);
    poly2 = insert(poly2,2,1);
    poly2 = insert(poly2,3,0);
    struct Node* sum = addPolynomials(poly1, poly2);
    // print the resulting polynomial
    struct Node* sumResult=sum;
    printf("After addition: ");
    while(sumResult!=NULL){
        if(sumResult->coeff!=0){
            if(sumResult!=sum)
                printf(" + ");
            if(sumResult->coeff!=1)
                printf("%dx^%d",sumResult->coeff, sumResult->exp);
            else
                printf("x^%d",sumResult->exp);
        }
        sumResult=sumResult->next;
    }
    printf(" ; ");

    struct Node* difference = subtractPolynomials(poly1, poly2);
    // print the resulting polynomial
    printf("After subtraction: ");
    struct Node* poly=difference;
    int isFirst= 1;
    while(poly!=NULL){
        if(poly->coeff!=0){
            if (!isFirst) {
                if(poly->coeff>0){
                    printf(" + ");
                }else{
                    printf(" - ");
                }
                if(poly->coeff<0){
                    poly->coeff=-(poly->coeff);
                }
            }
            if(poly->coeff!=1||poly->exp==0){
                printf("%d",poly->coeff);
            }
            if(poly->exp>0){
                printf("x");
                if (poly->exp>1){
                    printf("^%d",poly->exp);
                }
            }
            isFirst= 0;
        }
        poly=poly->next;
    }
 return 0;
}

struct Node* insert(struct Node* head,int coeff,int exp){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->coeff=coeff;
    newNode->exp=exp;
    newNode->next=NULL;
    if(head==NULL||exp>head->exp){
        head=newNode;
        return head;
    }
    struct Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    return head;
}

struct Node* addPolynomials(struct Node* poly1,struct Node* poly2){
    struct Node* sum=NULL;
    struct Node* current=NULL;

    while(poly1 && poly2){
        struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
        if(poly1->exp > poly2->exp){
            newNode->coeff=poly1->coeff;
            newNode->exp=poly1->exp;
            poly1=poly1->next;
        }else if(poly1->exp < poly2->exp){
            newNode->coeff=poly2->coeff;
            newNode->exp=poly2->exp;
            poly2=poly2->next;
        }else{
            newNode->coeff=poly1->coeff+poly2->coeff;
            newNode->exp=poly1->exp;
            poly1=poly1->next;
            poly2=poly2->next;
        }
        newNode->next=NULL;
        if(sum==NULL){
            sum=newNode;
            current=newNode;
        }else{
            current->next=newNode;
            current=current->next;
        }
    }
    return sum; 
}

struct Node* subtractPolynomials(struct Node* poly1, struct Node* poly2){
    struct Node* diff=NULL;
    struct Node* current=NULL;

    while(poly1 && poly2){
        struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
        if(poly1->exp > poly2->exp){
            newNode->coeff=poly1->coeff;
            newNode->exp=poly1->exp;
            poly1=poly1->next;
        }else if(poly1->exp < poly2->exp){
            newNode->coeff=-(poly2->coeff);
            newNode->exp=poly2->exp;
            poly2=poly2->next;
        } else{
            newNode->coeff=poly1->coeff-poly2->coeff;
            newNode->exp=poly1->exp;
            poly1=poly1->next;
            poly2=poly2->next;
        }

        newNode->next=NULL;
        if (diff==NULL){
            diff=newNode;
            current=newNode;
        } else{
            current->next=newNode;
            current=current->next;
        }
    }
    return diff;
}



