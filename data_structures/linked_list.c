#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int number;
    struct _node *next;
} node;
    
void print_node(node *n);
void print_list(node *n);

int main(void){

    printf("sizeof(int): %lu sizeof(node): %zu\n", sizeof(int), sizeof(node));

    // Allocates size bytes of uninitialized storage and return a pointer
    node *head = malloc(sizeof(node));

    printf("beginning of list: %p\n", head);

    if(head == NULL)
        return EXIT_FAILURE;

    // allocate memory for the first node
    node *n = (node *) malloc(sizeof(node)); 
    (*n).number = 10; // n->number
    (*n).next = NULL; // n->next

    print_node(n);

    // head is now pointing the new node.
    head = n;

    // create a second node
    n = (node *) malloc(sizeof(node)); 

    n -> number = 20;
    n -> next = NULL;

    print_node(n);

    head->next = n;

    // create a third node
    n = (node *) malloc(sizeof(node)); 

    n -> number = 30;
    n -> next = NULL;

    print_node(n);

    head->next->next = n;

    puts("List contents:");
    print_list(head);

    return 0;
}

void print_node(node *n){
    printf("{address: %p, number: %d, next: %p}\n", n, n->number, n->next);
}

void print_list(node *n){
    printf("{number: %d, next: %p}\n", n->number, n->next);
    if(n->next != NULL)
    {
        print_list(n->next);
    }
    
}