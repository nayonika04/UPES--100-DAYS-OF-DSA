#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* newNode(int data) {
    // Dynamically allocate memory for the new node
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to calculate the height of a binary tree recursively
int height(struct Node* node) {
    // Base case: an empty tree has a height of 0
    if (node == NULL) {
        return 0;
    } else {
        // Recursively calculate the height of left and right subtrees
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        // Return the greater of the two heights plus 1 for the current node
        if (leftHeight > rightHeight) {
            return (leftHeight + 1);
        } else {
            return (rightHeight + 1);
        }
    }
}

// Driver program to test the height function
int main() {
    // Constructing a sample binary tree:
    //         10
    //        /  \
    //       20  30
    //      / \
    //     40 50
    struct Node* root = newNode(10);
    root->left = newNode(20);
    root->right = newNode(30);
    root->left->left = newNode(40);
    root->left->right = newNode(50);

    // Calculate and print the height of the tree
    printf("Height of the tree is %d\n", height(root)); // Output: Height of the tree is 3

    // Clean up memory (optional for this small example)
    // A proper tree deallocation function would be used in a larger application.

    return 0;
}
