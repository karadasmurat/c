#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int data;
    struct _node *next;
} node;

/* Function prototypes */
void push(int val, node **list);
//void push(int val);
void print_list(node *head);
//void print_list();
void print_node(node *n);


/* Global variables */
// node *head;

int main(void){

    printf("sizeof(int): %zu \n", sizeof(int));
    printf("sizeof(node *): %zu \n", sizeof(node *));
    printf("sizeof(node): %zu\n", sizeof(node));

    // a pointer to struct node, to hold the address of the first node.
    // head will be our access point to the linked list.
    // carefull not to modify or loose it unwillingly.
    node *head = NULL;  // local
    // head = NULL; // global

/*
    // malloc allocates size bytes of uninitialized storage and return a pointer
    // from now on, this memory will be accessible through this pointer
    node *n = (node *) malloc(sizeof(node)); 

    if(n == NULL)
        return EXIT_FAILURE;

    (*n).number = 10; // n->number
    (*n).next = NULL; // n->next

    print_node(n);

    // head is now pointing the new node.
    // when we assign a pointer to another, they will have the same value, which is the address of another variable.
    // in other words, they will both point to the same variable at that address.
    head = n;

    // create a second node
    n = (node *) malloc(sizeof(node)); 

    n -> number = 20;
    n -> next = NULL;

    head->next = n; // do not modify head, it is keeping the beginning address of our list!

    // create a third node
    n = (node *) malloc(sizeof(node)); 

    n -> number = 30;
    n -> next = NULL;

    print_node(n);

    head->next->next = n;
*/
    for(int i=1; i<=5; i++){
        push(i, &head);
        // push(i); //global
    }

    puts("List contents:");
    // print_list();
    print_list(head);

    return 0;
}

// insert at the beginning - LIFO
void push(int val, node **list){
// void push(int val){

    // new node (allocate memory and get a pointer to the beginning address)
    node *n = (node *) malloc(sizeof(node));
    if(n == NULL)
        return ; // return void if memory is not allocated.
    
    n->data = val;

    // tie new node to the rest of the list through its own next pointer
    n->next = *list; // alternative syntax for dereference (*n).next

    // update head to point to the new node as the first member of the list
    *list = n;

}

void print_node(node *n){

    printf("{n: %p, n->number: %d, n->next: %p}\n", n, n->data, n->next);
}

void print_list(node *head){
// void print_list(){

    // temp pointer to traverse. 
    // do not traverse using head just to print, you will loose beginning address
    //node *current = head;

    while(head!= NULL){
        print_node(head);
        head = head->next;
    }
}