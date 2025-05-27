
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coef;
    int exp;
    struct Node* next;
};

typedef struct Node Node;
 Node *head1 = NULL,*head2 = NULL;


void insert(Node** poly, int coef, int exp) {
    Node* temp1 = (Node*) malloc(sizeof(Node));
    temp1->coef = coef;
    temp1->exp = exp;
    temp1->next = NULL;

    if (*poly == NULL) {
        *poly = temp1;
        return;
    }

    Node* temp = *poly;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = temp1;
}

void print(Node* poly) {
    if (poly == NULL) {
        printf("Empty\n");
        return;
    }

    Node* temp = poly;

    while (temp != NULL) {
        printf("%dx^%d", temp->coef, temp->exp);
        if (temp->next != NULL) {
            printf(" + ");
        }
        temp = temp->next;
    }

    printf("\n\n");
}

Node* add(Node* head1, Node* head2) {
    Node* result = NULL;

    while (head1 != NULL && head2 != NULL) {
        if (head1->exp == head2->exp) {
            insert(&result, head1->coef + head2->coef, head1->exp);
            head1 = head1->next;
            head2 = head2->next;
        } else if (head1->exp > head2->exp) {
            insert(&result, head1->coef, head1->exp);
            head1 = head1->next;
        } else {
            insert(&result, head2->coef, head2->exp);
            head2 = head2->next;
        }
    }

    while (head1 != NULL) {
        insert(&result, head1->coef, head1->exp);
        head1 = head1->next;
    }

    while (head2 != NULL) {
        insert(&result, head2->coef, head2->exp);
        head2 = head2->next;
    }

    return result;
}

int main()
{
    int terms,c,e;
    printf("\n Enter number of terms for poly 1");
    scanf("%d",&terms);

    for(int i=1;i<=terms;i++)
    {
        printf("\n Enter coeff   ");
        scanf("%d",&c);
        printf("\n Enter expo   ");
        scanf("%d",&e);
        insert(&head1,c,e);
    }

    printf("\n Enter number of terms for poly 2");
    scanf("%d",&terms);

    for(int i=1;i<=terms;i++)
    {
        printf("\n Enter coeff   ");
        scanf("%d",&c);
        printf("\n Enter expo   ");
        scanf("%d",&e);
        insert(&head2,c,e);
    }

    printf("First polynomial: ");
    print(head1);

    printf("Second polynomial: ");
    print(head2);

    Node* result = add(head1, head2);
    printf("Result: ");
    print(result);

    return 0;
}






/*
#include<stdio.h>

struct Node {
    int coeff;
    int pow;
    struct Node* next;
};

void create_node(int coef, int expo, struct Node** temp)
{
    struct Node *r, *z;
    z = *temp;
    if (z == NULL) {
        r = (struct Node*)malloc(sizeof(struct Node));
        r->coeff = x;
        r->pow = y;
        *temp = r;
        r->next = (struct Node*)malloc(sizeof(struct Node));
        r = r->next;
        r->next = NULL;
    }
    else {
        r->coeff = x;
        r->pow = y;
        r->next = (struct Node*)malloc(sizeof(struct Node));
        r = r->next;
        r->next = NULL;
    }
}

void polyadd(struct Node* poly1, struct Node* poly2,
             struct Node* poly)
{
    while (poly1->next && poly2->next) {
        // If power of 1st polynomial is greater then 2nd,
        // then store 1st as it is and move its pointer
        if (poly1->pow > poly2->pow) {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff;
            poly1 = poly1->next;
        }

        // If power of 2nd polynomial is greater then 1st,
        // then store 2nd as it is and move its pointer
        else if (poly1->pow < poly2->pow) {
            poly->pow = poly2->pow;
            poly->coeff = poly2->coeff;
            poly2 = poly2->next;
        }

        // If power of both polynomial numbers is same then
        // add their coefficients
        else {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff + poly2->coeff;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        // Dynamically create new node
        poly->next
            = (struct Node*)malloc(sizeof(struct Node));
        poly = poly->next;
        poly->next = NULL;
    }
    while (poly1->next || poly2->next) {
        if (poly1->next) {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        if (poly2->next) {
            poly->pow = poly2->pow;
            poly->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        poly->next
            = (struct Node*)malloc(sizeof(struct Node));
        poly = poly->next;
        poly->next = NULL;
    }
}

// Display Linked list
void show(struct Node* node)
{
    while (node->next != NULL) {
        printf("%dx^%d ", node->coeff, node->pow);
        node = node->next;
        if (node->coeff >= 0) {
            if (node->next != NULL)
                printf("+");
        }
    }
}

// Driver code
int main()
{
    struct Node *poly1 = NULL, *poly2 = NULL, *poly = NULL;

    int terms,coef,expo;
    printf("\n Enter number of terms for poly 1");
    scanf("%d",&terms);

    for(int i=1;i<=terms;i++)
    {
        printf("\n Enter coeff   ");
        scanf("%d",&coef);
        printf("\n Enter expo   ");
        scanf("%d",&expo);
        create_node(coef, expo, &poly1);
    }

    printf("\n Enter number of terms for poly 2");
    scanf("%d",&terms);

    for(int i=1;i<=terms;i++)
    {
        printf("\n Enter coeff   ");
        scanf("%d",&coef);
        printf("\n Enter expo   ");
        scanf("%d",&expo);
        create_node(coef, expo, &poly2);
    }

    /* Create first list of 5x^2 + 4x^1 + 2x^0
    create_node(5, 2, &poly1);
    create_node(4, 1, &poly1);
    create_node(2, 0, &poly1);

    // Create second list of -5x^1 - 5x^0
    create_node(-5, 1, &poly2);
    create_node(-5, 0, &poly2);

    printf("\n1st Poly: ");
    show(poly1);

    printf("\n2nd Poly: ");
    show(poly2);

    poly = (struct Node*)malloc(sizeof(struct Node));

    // Function add two polynomial numbers
    polyadd(poly1, poly2, poly);

    // Display resultant List
    printf("\nAdded polynomial: ");
    show(poly);

    return 0;
}*/
