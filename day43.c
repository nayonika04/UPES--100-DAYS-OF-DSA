#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Definition for a queue node (used for queue implementation)
struct QNode {
    struct TreeNode *treeNode;
    struct QNode *next;
};

// Definition for a Queue
struct Queue {
    struct QNode *front, *rear;
};

// Function to create a new tree node
struct TreeNode* createTreeNode(int data) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to create a new queue node
struct QNode* createQNode(struct TreeNode *treeNode) {
    struct QNode* qNode = (struct QNode*)malloc(sizeof(struct QNode));
    qNode->treeNode = treeNode;
    qNode->next = NULL;
    return qNode;
}

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to enqueue a tree node
void enqueue(struct Queue* q, struct TreeNode *treeNode) {
    struct QNode* temp = createQNode(treeNode);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

// Function to dequeue a tree node
struct TreeNode* dequeue(struct Queue* q) {
    if (q->front == NULL) return NULL;
    struct QNode* temp = q->front;
    struct TreeNode* treeNode = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return treeNode;
}

// Function to construct the binary tree from level order traversal array
struct TreeNode* constructTree(int arr[], int n) {
    if (n <= 0 || arr[0] == -1) return NULL;

    struct TreeNode* root = createTreeNode(arr[0]);
    struct Queue* q = createQueue();
    enqueue(q, root);
    int i = 1;

    while (i < n && q->front != NULL) {
        struct TreeNode* currentNode = dequeue(q);

        // Process left child
        if (i < n) {
            if (arr[i] != -1) {
                currentNode->left = createTreeNode(arr[i]);
                enqueue(q, currentNode->left);
            }
            i++;
        }

        // Process right child
        if (i < n) {
            if (arr[i] != -1) {
                currentNode->right = createTreeNode(arr[i]);
                enqueue(q, currentNode->right);
            }
            i++;
        }
    }
    // Note: Queue memory should be freed in a production environment
    return root;
}

// Function to print inorder traversal of the binary tree (Left, Root, Right)
void inorderTraversal(struct TreeNode* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Main function to run the program with the example
int main() {
    // Example Input: 7 \n 1 2 3 4 5 "-1" 6
    // The program reads N and the array elements
    
    int n;
    printf("Enter the number of nodes (N): ");
    if (scanf("%d", &n) != 1) return 1;

    int arr[n];
    printf("Enter the %d space-separated integers (-1 for NULL): ", n);
    for (int i = 0; i < n; i++) {
        // Use a temporary variable to read and handle potential type mismatches
        if (scanf("%d", &arr[i]) != 1) return 1;
    }

    struct TreeNode* root = constructTree(arr, n);

    printf("Inorder traversal of the constructed tree: ");
    inorderTraversal(root);
    printf("\n");

    // Free allocated memory (omitted for brevity in this example)

    return 0;
}
