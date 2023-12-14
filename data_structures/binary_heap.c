/*
A binary heap is defined as a binary tree with two additional constraints:[3]

Shape property: a binary heap is a complete binary tree; 
that is, all levels of the tree, except possibly the last one (deepest) are fully filled, and, 
if the last level of the tree is not complete, the nodes of that level are filled from left to right.

Heap property: the key stored in each node is either greater than or equal to (≥) {max-heaps}- or 
less than or equal to (≤) the keys in the node's children {min-heaps}

https://www.cs.usfca.edu/~galles/visualization/Heap.html

*/

#include <stdio.h>

int main(void){

    return 0;
}

/*
Insert
1. Add the element to the bottom level of the heap at the leftmost open space.
2. Compare the added element with its parent; if they are in the correct order, stop.
3. If not, swap the element with its parent and return to the previous step.
*/

/*
Extract (the maximum element in a max-heap or the minimum element in a min-heap)

1. Replace the root of the heap with the last element on the last level.
2. Compare the new root with its children; if they are in the correct order, stop.
3. If not, swap the element with one of its children and return to the previous step. (Swap with its smaller child in a min-heap and its larger child in a max-heap.)
*/