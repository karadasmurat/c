#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int data;
    struct _node *next;
} node;

/* Function prototypes */
node* new_node(int data);
int push__byval(int data);
void push__byref(int data, node** stack);
void print_stack(node* stack);



int main(void){

    // beginning address of stack
    node* stack = NULL;

    for(int i=100; i<105; i++)
        push__byref(i, &stack);

    print_stack(stack);

    return 0;
}

/* Function */
int push__byval(int data){

    node* n = new_node(data);
    return 0;
}

/* Function */
void push__byref(int data, node** stack){

    node* n = new_node(data);

    //dereference the argument (pointer) to modify the value it is pointing.
    n->next = *stack;
    *stack = n;

}

// allocate memory for the node, set data value and return the beginning address
node* new_node(int data){

    node* n = (node*) malloc(sizeof(node));
    n->data = data;
    n->next = NULL;

    return n;
}

void print_stack(node* stack){

    printf("{");

    // use a second pointer to traverse. do not modify the pointer holding the beginning address of stack.
    node* current = stack;
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }

    printf("}");

}