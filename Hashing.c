#include<stdio.h>
#include<stdlib.h>

// create a hash table with an array of linked lists of size 10

struct node {
    int data;
    struct node *next;
} *hashtable[10];


void initialize(){
    int i;
    for(i=0; i<10; i++){
        hashtable[i] = NULL;
    }
}

void insert(int value){
    int key = value % 10;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("inserting");
    newnode->data = value;
    newnode->next = NULL;
    if(hashtable[key] == NULL){
        hashtable[key] = newnode;
    }
    else if(hashtable[key]->data > value){
        newnode->next = hashtable[key];
        hashtable[key] = newnode;
    }
    else{
        struct node *temp = hashtable[key];
        while(temp->next != NULL && temp->next->data < value){
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    
}

void print(){
    struct node *temp;
    printf("\n\nHashtable: \n");
    for(int i=0; i<10; i++){
        printf("\n[%d] --- ", i);
        temp = hashtable[i];
        while(temp != NULL){
            printf(" %d -->", temp->data);
            temp = temp->next;
        }
        printf("NULL");
    }
}

void main(){
    initialize();
    int choice = 0, value;
    do{
        printf("\n\n\t\tMENU\n 1. Insert into the hashtable\n 2. Print the hashtable\n 3. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\nEnter the value to be inserted: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                print();
                break;
            
            case 3:
                printf("\nExiting");
                break;
            default:
                printf("\nInvalid choice");
        }
    } while(choice !=3);
}