// Implement insertion, deletion and display operations on circular queue and priority queue using arrays

#include <stdio.h>

int cqueue[20];
int cfront, crear, cn;

int cq_display(){
    int i;
    if(cfront==crear)
        printf("Queue Empty!\n");
    
    else{
        printf("Queue : ");
        for(i=(cfront+1)%cn; i!=crear; i=(i+1)%cn)
            printf("%d ", cqueue[i]);
        printf("%d\n", cqueue[i]);
    }
}

void cq_insert()
{
    // insert item in circular queue
    if((crear+1)%cn == cfront)
        printf("Queue Full!\n");
    
    else {
        int item;
        printf("Enter the item to be inserted : ");
        scanf("%d", &item);
        crear = (crear+1)%cn;
        cqueue[crear] = item;
    }  
    cq_display();
}

int cq_delete(){
    if(cfront==crear)
        printf("Queue Empty!\n");

    else{
        cfront = (cfront+1)%cn;
        printf("Popped Element : %d\n", cqueue[cfront]);
    }
    cq_display();
}

void circular_queue() {
    int choice, i;
    cfront = crear = 0;
    do{
        printf("\n\n\t\tCircular Queue");
        printf("\n1. Insertion\n2. Deletion\n3. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                cq_insert();
                break;
            case 2:
                cq_delete();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }while(choice!=3);
}

struct priority_queue {
    int data;
    int priority;
} pqueue[100];

int pn, pfront, prear;


void pq_display(){
    if(pfront == prear)
        printf("Queue Empty!\n");
    else {
        printf("Contents of the Queue : ");
        for(int i=pfront+1; i<=prear; i++)
            printf("\n%d - %d", pqueue[i].data, pqueue[i].priority);
    }
}

void pq_insert(){
    if(prear == pn-1)
        printf("Queue Full!\n");
    
    else{
        int item, priority;
        struct priority_queue temp;
        printf("Enter the item to be inserted : ");
        scanf("%d", &item);
        printf("Enter the priority of the item : ");
        scanf("%d", &priority);
        prear++;
        pqueue[prear].data = item;
        pqueue[prear].priority = priority;
        for(int i = prear; i>pfront+1; i--)
            if(pqueue[i].priority > pqueue[i-1].priority){
                temp = pqueue[i];
                pqueue[i] = pqueue[i-1];
                pqueue[i-1] = temp;
            }
            else break;
    }
    pq_display();
}

void pq_delete(){
    if(pfront == prear)
        printf("Queue Empty!\n");
    
    else{
        pfront++;
        printf("Popped Element : \n");
        printf("\t Data - %d", pqueue[pfront].data);
        printf("\t Priority - %d\n", pqueue[pfront].priority);
    }
    pq_display();
}

void priority_queue() {
    int choice, i;
    do{
        printf("\n\n\t\tPriority Queue\n1. Insertion\n2. Deletion\n3. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                pq_insert();
                break;
            case 2:
                pq_delete();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }while(choice!=3);
}

void main() {
    cfront = crear = 0;
    printf("Enter size of the Queue: ");
    scanf("%d", &pn);
    cn = pn+1;
    pfront = prear = -1;
    int choice=0;
    // A menu with options Circular Queue, Priority Queue and Exit
    do {
        printf("\n\n\n\t\t\tMENU");
        printf("\n1. Circular Queue\n2. Priority Queue\n3. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                circular_queue();
                break;
            case 2:
                priority_queue();
                break;
            case 3:
                printf("Exiting.....\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!=3);
    
}