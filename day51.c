#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Function to create a new node
Node* newNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a node into the BST
Node* insert(Node* root, int val) {
    if (root == NULL) {
        return newNode(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    return root;
}

// Function to find the LCA of two nodes in a BST
Node* lca(Node* root, int n1, int n2) {
    while (root != NULL) {
        // If both n1 and n2 are smaller than root, LCA is in the left subtree
        if (root->data > n1 && root->data > n2) {
            root = root->left;
        }
        // If both n1 and n2 are greater than root, LCA is in the right subtree
        else if (root->data < n1 && root->data < n2) {
            root = root->right;
        }
        // Otherwise, one is smaller and one is greater (or one is the root itself),
        // so the current node is the LCA
        else {
            break;
        }
    }
    return root;
}

// Main function to handle input and output
int main() {
    int N, val, n1, n2;
    Node* root = NULL;

    // Read the number of nodes
    if (scanf("%d", &N) != 1) return 1;

    // Read the N space-separated integers to build the BST
    for (int i = 0; i < N; i++) {
        if (scanf("%d", &val) != 1) return 1;
        root = insert(root, val);
    }

    // Read the two node values
    if (scanf("%d %d", &n1, &n2) != 2) return 1;

    // Find the LCA node
    Node* lcaNode = lca(root, n1, n2);

    // Print the LCA value
    if (lcaNode != NULL) {
        printf("%d\n", lcaNode->data);
    } else {
        printf("LCA not found or invalid input\n");
    }

    // Free the allocated memory (optional for simple problem, good practice)
    // Add a function to free the tree if needed

    return 0;
}
