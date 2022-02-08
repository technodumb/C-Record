#include<stdio.h>
#include<stdlib.h>

struct poly_node {
    int coeff;
    int exp;
    struct poly_node *next;
} *head1, *head2, *headprod;


void insert_poly(struct poly_node **head, int co, int ex) {
    struct poly_node *x = (struct poly_node *)malloc(sizeof(struct poly_node));
    x->coeff = co;
    x->exp = ex;
    x->next = NULL;
    if (*head == NULL) {
        *head = x;
    }
    else if((*head)->exp < ex) {
        x->next = *head;
        *head = x;
    }
    else {
        struct poly_node *temp = *head;
        while (temp->next != NULL && temp->next->exp >= ex) {
            temp = temp->next;
        }
        if(temp->exp == ex)
            temp->coeff+=co;
        else 
        {
            x->next = temp->next;
            temp->next = x;
        }
    }
}

void create_poly(struct poly_node **head) {
    int n, co, ex;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the coefficient and exponent of term %d: ", i+1);
        scanf("%d %d", &co, &ex);
        insert_poly(head, co, ex);
    }
}

void print_poly(struct poly_node **head){
    struct poly_node *temp = *head;
    while (temp != NULL) {
        printf("%d", temp->coeff);
        if(temp->exp != 0)
            printf("x^%d ", temp->exp);
        temp = temp->next;
        if(temp != NULL)
            printf("+ ");
    }
    printf("\n");
}

void prod_poly() {
    headprod = NULL;
    int ncoeff, nexp;
    struct poly_node *temp1 = head1;
    struct poly_node *temp2 = head2;
    while(temp1 != NULL) {
        temp2 = head2;
        while(temp2 != NULL) {
            ncoeff = temp1->coeff * temp2->coeff;
            nexp = temp1->exp + temp2 ->exp;
            insert_poly(&headprod, ncoeff, nexp);
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
}

void main(){
    printf("\n\nPolynomial 1: \n");
    create_poly(&head1);
    printf("\n\nPolynomial 2: \n");
    create_poly(&head2);
    printf("\n\nPolynomial 1 is: \n");
    print_poly(&head1);
    printf("\n\nPolynomial 2 is: \n");
    print_poly(&head2);
    printf("\nProduct of the polynomials is: \n");
    prod_poly();
    print_poly(&headprod);
}