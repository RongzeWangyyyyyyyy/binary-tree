#include <stdlib.h>
#include <stdio.h>

/**
 * A node of the binary tree containing the node's integer value
 * and pointers to its right and left children (or null).
 */
struct Node {
  int  value;
  struct Node* parent;
  struct Node* left;
  struct Node* right;
};

/**
 * Create a new node with no children.
 */
struct Node* create (int value) {
  struct Node* node = malloc(sizeof(struct Node));
  node->value=value;
  node->left=0;
  node->parent=0;
  node->right=0;
  return node;
}

/**
 * Insert the node n into the binary tree rooted by toNode.
 */
void insert (struct Node* toNode, struct Node* n) {
  if (n->value <= toNode->value) {
    if (toNode->left == 0) {
      toNode->left = n;
      n->parent=toNode;
    } else {
      insert(toNode->left, n);
    }
  } else {
    if (toNode->right == 0) {
      toNode->right = n;
      n->parent=toNode;
    } else {
      insert(toNode->right, n);
    }
  }
}

/**
 * Print the contents entire binary tree in order of ascending integer value.
 */
void printInOrder (struct Node* node) {
  if (node->left != 0)
    printInOrder(node->left);
    printf ("%d\n", node->value);
  if (node->right != 0)
    printInOrder(node->right);
}

/**
 * Print path of values from root to specified node in orderer starting from root.
 * Each node in path indicates direction taken (i.e., left or right) from parent to arive at node.
 */
void printPath (struct Node* node) {
  if (node->parent != 0) {
    printPath(node->parent);
  }
  printf("%s: %d\n", node->parent == 0? "from root": node->parent->left == node? "left to": "right to", node->value);
}

/**
 * Create a new tree populated with values provided on the command line and
 * print it in depth-first order.
 */
int main (int argc, char* argv[]) {
  struct Node* root = 0;
  // read values from command line and add them to the tree
  struct Node* lastNodeInserted = NULL;
  for (int i=1; i<argc; i++) {
    int value = atoi (argv [i]);
    struct Node* node = create (value);
    if (i==1)
      root = node;
    else
      insert (root, node);
    lastNodeInserted = node;
  }
  // print results
  if (root) {
    printf("In Order:\n");
    printInOrder (root);
    printf("Path to %d:\n", lastNodeInserted->value);  // TODO: replace 0 with expression that gets value of lastNodeInserted
    printPath(lastNodeInserted);
  }
}