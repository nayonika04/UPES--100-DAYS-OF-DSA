#include <stdio.h>
#include <stdlib.h>

// Definition of the BST Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to search a given key in BST
struct Node* search(struct Node* root, int key) {
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->data == key)
        return root;
    
    // Key is greater than root's data
    if (root->data < key)
        return search(root->right, key);
  
    // Key is smaller than root's data
    return search(root->left, key);
}

// Simple helper to insert nodes for testing
struct Node* insert(struct Node* node, int data) {
    if (node == NULL) return newNode(data);
    if (data < node->data)
        node->left = insert(node->left, data);
    else
        node->right = insert(node->right, data);
    return node;
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);

    int key = 40;
    struct Node* result = search(root, key);

    if (result != NULL)
        printf("Element %d found in the BST.\n", key);
    else
        printf("Element %d not found.\n", key);

    return 0;
}
