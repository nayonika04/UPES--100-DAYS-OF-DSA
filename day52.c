#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition for a binary tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to build the binary tree from level-order traversal input
struct Node* buildTree(int arr[], int n) {
    if (n <= 0 || arr[0] == -1) return NULL;

    struct Node** nodes = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++) {
        if (arr[i] == -1) {
            nodes[i] = NULL;
        } else {
            nodes[i] = newNode(arr[i]);
        }
    }

    int parentIdx = 0;
    for (int i = 1; i < n; i += 2) {
        // Find the next non-null parent
        while (parentIdx < n && nodes[parentIdx] == NULL) {
            parentIdx++;
        }
        if (parentIdx >= n) break;

        nodes[parentIdx]->left = nodes[i];
        if (i + 1 < n) {
            nodes[parentIdx]->right = nodes[i + 1];
        }
        parentIdx++;
    }

    struct Node* root = nodes[0];
    free(nodes); // Free the temporary array of pointers
    return root;
}

// Recursive function to find the LCA of two nodes
struct Node* findLCA(struct Node* root, int n1, int n2) {
    if (root == NULL || root->data == n1 || root->data == n2) {
        return root;
    }

    // Recursively search for nodes in left and right subtrees
    struct Node* left_lca = findLCA(root->left, n1, n2);
    struct Node* right_lca = findLCA(root->right, n1, n2);

    // If both nodes are found in different subtrees, the current root is the LCA
    if (left_lca != NULL && right_lca != NULL) {
        return root;
    }

    // Otherwise, return the non-null result from the subtrees
    return (left_lca != NULL) ? left_lca : right_lca;
}

// Main function to handle input and output
int main() {
    int N, node1_val, node2_val;

    // Read N (number of elements in level-order input)
    if (scanf("%d", &N) != 1) return 1;

    int* arr = (int*)malloc(N * sizeof(int));
    // Read level-order traversal values
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    // Build the tree from the input array
    struct Node* root = buildTree(arr, N);
    free(arr); // Free the input array

    // Read the two node values
    if (scanf("%d %d", &node1_val, &node2_val) != 2) return 1;

    // Find the LCA
    struct Node* lca_node = findLCA(root, node1_val, node2_val);

    // Print the result
    if (lca_node != NULL) {
        printf("%d\n", lca_node->data);
    } else {
        printf("LCA not found or nodes not present.\n");
    }

    // Note: Proper memory management for the tree nodes should be added
    // for a complete program (e.g., a function to free the tree).

    return 0;
}
