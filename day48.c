#include <stdio.h>
#include <stdlib.h>

// Input Specifications: A pointer to the root node of the binary tree.
// Output Specifications: The total count of leaf nodes in the tree.

// Definition for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Recursive function to count leaf nodes
int countLeafNodes(struct Node* root) {
    // If the node is NULL, it's an empty tree or an empty subtree, so return 0
    if (root == NULL) {
        return 0;
    }

    // If the node has no left or right child, it is a leaf node, so return 1
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }

    // If it's not a leaf node, recursively call the function on its left and right
    // children and return the sum of the counts
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Main function to demonstrate the solution
int main() {
    // Create a sample binary tree:
    //         1
    //        / \
    //       2   3
    //      / \   \
    //     4   5   8
    //              / \
    //             6   7
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(8);
    root->right->right->left = createNode(6);
    root->right->right->right = createNode(7);

    // Count and print the number of leaf nodes
    int leafCount = countLeafNodes(root);
    printf("The number of leaf nodes in the tree is: %d\n", leafCount);

    // Free the allocated memory (essential for good practice,
    // though simplified here for clarity)
    // A proper deallocation function would be needed for complex trees.
    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

// Input Specifications: A pointer to the root node of the binary tree.
// Output Specifications: The total count of leaf nodes in the tree.

// Definition for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Recursive function to count leaf nodes
int countLeafNodes(struct Node* root) {
    // If the node is NULL, it's an empty tree or an empty subtree, so return 0
    if (root == NULL) {
        return 0;
    }

    // If the node has no left or right child, it is a leaf node, so return 1
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }

    // If it's not a leaf node, recursively call the function on its left and right
    // children and return the sum of the counts
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Main function to demonstrate the solution
int main() {
    // Create a sample binary tree:
    //         1
    //        / \
    //       2   3
    //      / \   \
    //     4   5   8
    //              / \
    //             6   7
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(8);
    root->right->right->left = createNode(6);
    root->right->right->right = createNode(7);

    // Count and print the number of leaf nodes
    int leafCount = countLeafNodes(root);
    printf("The number of leaf nodes in the tree is: %d\n", leafCount);

    // Free the allocated memory (essential for good practice,
    // though simplified here for clarity)
    // A proper deallocation function would be needed for complex trees.
    
    return 0;
}
