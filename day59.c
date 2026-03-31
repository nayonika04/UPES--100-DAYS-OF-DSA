#include <stdio.h>
#include <stdlib.h>

/* Structure for a binary tree node */
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

/* Function to create a new tree node */
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* Function to find the index of a value in an array */
int findIndex(int arr[], int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == val) {
            return i;
        }
    }
    return -1; // Value not found, should not happen with valid input
}

/* Recursive function to build the binary tree */
struct Node* buildTree(int in[], int post[], int inStart, int inEnd, int postStart, int postEnd) {
    if (inStart > inEnd || postStart > postEnd) {
        return NULL;
    }

    // The last element in postorder is the root
    int rootVal = post[postEnd];
    struct Node* root = createNode(rootVal);

    // Find the index of the root in inorder
    int rootIndexIn = findIndex(in, inStart, inEnd, rootVal);

    // Calculate the size of the left and right subtrees
    int leftSubtreeSize = rootIndexIn - inStart;
    // int rightSubtreeSize = inEnd - rootIndexIn; // Not explicitly needed here

    // Recursively build the left and right subtrees
    // For the left subtree:
    // Inorder: in[inStart...rootIndexIn-1]
    // Postorder: post[postStart...postStart + leftSubtreeSize - 1]
    root->left = buildTree(in, post, inStart, rootIndexIn - 1, postStart, postStart + leftSubtreeSize - 1);

    // For the right subtree:
    // Inorder: in[rootIndexIn+1...inEnd]
    // Postorder: post[postStart + leftSubtreeSize...postEnd - 1]
    root->right = buildTree(in, post, rootIndexIn + 1, inEnd, postStart + leftSubtreeSize, postEnd - 1);

    return root;
}

/* Function to print the preorder traversal of the constructed tree */
void printPreorder(struct Node* node) {
    if (node == NULL) {
        return;
    }
    printf("%d ", node->data);
    printPreorder(node->left);
    printPreorder(node->right);
}

/* Main function to handle input and output */
int main() {
    int N;
    // Read the number of nodes
    if (scanf("%d", &N) != 1) return 1;

    int* inorder = (int*)malloc(N * sizeof(int));
    int* postorder = (int*)malloc(N * sizeof(int));

    // Read inorder traversal
    for (int i = 0; i < N; i++) {
        scanf("%d", &inorder[i]);
    }

    // Read postorder traversal
    for (int i = 0; i < N; i++) {
        scanf("%d", &postorder[i]);
    }

    // Construct the tree
    struct Node* root = buildTree(inorder, postorder, 0, N - 1, 0, N - 1);

    // Print the preorder traversal
    printPreorder(root);
    printf("\n");

    // Free dynamically allocated memory (optional for simple examples)
    free(inorder);
    free(postorder);

    return 0;
}
