#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new tree node.
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to find the index of a value in an array.
int findIndex(int arr[], int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == val) {
            return i;
        }
    }
    return -1; // Should not happen if inputs are valid
}

// Recursive function to construct the binary tree.
struct Node* buildTree(int pre[], int in[], int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd) {
        return NULL; // Base case: empty subtree
    }

    // The first element in preorder traversal is the root of the current subtree.
    struct Node* root = createNode(pre[*preIndex]);
    (*preIndex)++;

    // If the current subtree has only one node, return it.
    if (inStart == inEnd) {
        return root;
    }

    // Find the index of the current root in the inorder traversal.
    int inIndex = findIndex(in, inStart, inEnd, root->data);

    // Recursively build the left and right subtrees.
    // Elements before inIndex in inorder belong to the left subtree.
    root->left = buildTree(pre, in, inStart, inIndex - 1, preIndex);
    // Elements after inIndex in inorder belong to the right subtree.
    root->right = buildTree(pre, in, inIndex + 1, inEnd, preIndex);

    return root;
}

// Function to print the postorder traversal of the constructed tree.
void printPostOrder(struct Node* node) {
    if (node == NULL) {
        return;
    }

    // Traverse left subtree
    printPostOrder(node->left);

    // Traverse right subtree
    printPostOrder(node->right);

    // Visit node
    printf("%d ", node->data);
}

// Driver program to test the functions.
int main() {
    int N;

    // Read the number of nodes
    if (scanf("%d", &N) != 1) return 1;

    int pre[N], in[N];

    // Read preorder traversal
    for (int i = 0; i < N; i++) {
        scanf("%d", &pre[i]);
    }

    // Read inorder traversal
    for (int i = 0; i < N; i++) {
        scanf("%d", &in[i]);
    }

    int preIndex = 0;
    // Build the tree
    struct Node* root = buildTree(pre, in, 0, N - 1, &preIndex);

    // Print the postorder traversal of the constructed tree
    printPostOrder(root);
    printf("\n");

    // Free the allocated memory (optional, for complete program)
    // A proper memory management system would be needed for a robust program.

    return 0;
}
