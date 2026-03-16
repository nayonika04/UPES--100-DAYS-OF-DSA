#include <stdio.h>
#include <stdlib.h>

// Define the structure of a binary tree node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to build the binary tree from level order input
struct Node* buildTree(int arr[], int n) {
    if (n <= 0 || arr[0] == -1) {
        return NULL;
    }

    struct Node* root = createNode(arr[0]);
    struct Node* queue[100]; // Simple queue implementation (adjust size as needed)
    int head = 0, tail = 0;
    queue[tail++] = root;
    int i = 1;

    while (i < n && head < tail) {
        struct Node* currentNode = queue[head++];

        // Process left child
        if (i < n && arr[i] != -1) {
            currentNode->left = createNode(arr[i]);
            queue[tail++] = currentNode->left;
        }
        i++;

        // Process right child
        if (i < n && arr[i] != -1) {
            currentNode->right = createNode(arr[i]);
            queue[tail++] = currentNode->right;
        }
        i++;
    }
    return root;
}

// Inorder Traversal: Left -> Root -> Right
void inorderTraversal(struct Node* node) {
    if (node == NULL)
        return;
    inorderTraversal(node->left);
    printf("%d ", node->data);
    inorderTraversal(node->right);
}

// Preorder Traversal: Root -> Left -> Right
void preorderTraversal(struct Node* node) {
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

// Postorder Traversal: Left -> Right -> Root
void postorderTraversal(struct Node* node) {
    if (node == NULL)
        return;
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    printf("%d ", node->data);
}

// Main function
int main() {
    int n;
    // Read the number of nodes
    if (scanf("%d", &n) != 1) return 1;

    int arr[n];
    // Read the level order traversal values
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Build the tree
    struct Node* root = buildTree(arr, n);

    // Perform and print traversals
    printf("Inorder: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder: ");
    postorderTraversal(root);
    printf("\n");

    // Free allocated memory (optional for this specific problem, but good practice)
    // A recursive function for memory deallocation can be used here.

    return 0;
}
