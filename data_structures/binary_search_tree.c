#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int data;
    struct _node* left;
    struct _node* right;
} node;

/* Function prototypes */
node* new_node(int data);
void process_node(node* tree);
void traverse_inorder(node* tree);
node * create_manual_bst();
node* insert(node* nodePtr, int data);

int main(void){

    //node * tree = create_sample_bst();

    // create a pointer to tree structure
    node* tree = NULL;

    tree = insert(tree, 7);
    tree = insert(tree, 20);
    tree = insert(tree, 15);
    tree = insert(tree, 8);
    tree = insert(tree, 40);
    tree = insert(tree, 65);
    tree = insert(tree, 2);
    tree = insert(tree, 19);
    tree = insert(tree, 90);
    tree = insert(tree, 3);
    tree = insert(tree, 5);
    tree = insert(tree, 1);


    traverse_inorder(tree);

    return 0;
}

// node constructor
// allocate memory in the heap, set the data and return the address.
node* new_node(int data){

    node* n = (node*) malloc(sizeof(node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n; 
}

void process_node(node* tree){
    printf("%d ",tree->data);
}

void traverse_inorder(node* tree){

    if(tree == NULL){
        //printf("traverse(node: NULL)\n");
        return;
    }

    //printf("traverse(node: %d)\n", tree->data);

    traverse_inorder(tree->left);
    process_node(tree);
    traverse_inorder(tree->right);
}

node * create_manual_bst(){

    // create a pointer to tree structure
    node* root = NULL;

    //create first node
    node* a = new_node(7);

    root = a; //tree is now pointing to the first node.

    node* b = new_node(20);
    a->right = b;

    node* c = new_node(15);
    b->left = c;

    node* d = new_node(8);
    c->left = d;

    node* e = new_node(40);
    b->right = e;

    node* f = new_node(65);
    e->right = f;

    node* g = new_node(2);
    a->left = g;

    node* h = new_node(19);
    c->right = h;

    node* i = new_node(90);
    f->right = i;

    node* j = new_node(3);
    g->right = j;

    node* k = new_node(5);
    j->right = k;

    node* l = new_node(1);
    g->left = l;


    return root;

}
// update a NULL node pointer to point at a new struct node.
node* insert(node* nodePtr, int data){

    if(nodePtr == NULL){
        nodePtr = new_node(data);
    }

    // the pointer has an address value of a node
    // calculate direction, call recursive on the subtree of that direction.
    else if(data <= nodePtr->data){
        nodePtr->left = insert(nodePtr->left, data);
    }else if(data > nodePtr->data){
        nodePtr->right = insert(nodePtr->right, data);
    }

    return nodePtr;

}
