#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Queue structure for standard level order traversal
struct QueueNode {
    struct TreeNode *treeNode;
    struct QueueNode *next;
};

struct Queue {
    struct QueueNode *front, *rear;
};

// Function to create a new queue node
struct QueueNode* newQueueNode(struct TreeNode *treeNode) {
    struct QueueNode *temp = (struct QueueNode *)malloc(sizeof(struct QueueNode));
    temp->treeNode = treeNode;
    temp->next = NULL;
    return temp;
}

// Function to create a queue
struct Queue* createQueue() {
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to enqueue a tree node
void enqueue(struct Queue *q, struct TreeNode *treeNode) {
    if (treeNode == NULL) return;
    struct QueueNode *temp = newQueueNode(treeNode);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

// Function to dequeue a tree node
struct TreeNode* dequeue(struct Queue *q) {
    if (q->front == NULL) return NULL;
    struct QueueNode *temp = q->front;
    struct TreeNode *treeNode = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return treeNode;
}

// Function to check if a queue is empty
int isQueueEmpty(struct Queue *q) {
    return q->front == NULL;
}

// Function to build the tree from level order input
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0) return NULL;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = arr[0];
    root->left = root->right = NULL;
    struct Queue* q = createQueue();
    enqueue(q, root);
    int i = 1;
    while (i < n && !isQueueEmpty(q)) {
        struct TreeNode* current = dequeue(q);
        if (i < n && arr[i] != -1) {
            current->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            current->left->val = arr[i];
            current->left->left = current->left->right = NULL;
            enqueue(q, current->left);
        }
        i++;
        if (i < n && arr[i] != -1) {
            current->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            current->right->val = arr[i];
            current->right->left = current->right->right = NULL;
            enqueue(q, current->right);
        }
        i++;
    }
    return root;
}

// Function to perform zigzag level order traversal
void zigzagLevelOrder(struct TreeNode* root) {
    if (root == NULL) return;
    struct Queue* q = createQueue();
    enqueue(q, root);
    int leftToRight = 1; // Flag to track traversal direction

    while (!isQueueEmpty(q)) {
        int levelSize = 0;
        // Calculate current level size
        for (struct QueueNode* temp = q->front; temp != NULL; temp = temp->next) {
            levelSize++;
        }

        int *currentLevel = (int*)malloc(levelSize * sizeof(int));
        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* current = dequeue(q);
            currentLevel[i] = current->val;

            if (current->left) enqueue(q, current->left);
            if (current->right) enqueue(q, current->right);
        }

        // Print nodes based on direction
        if (leftToRight) {
            for (int i = 0; i < levelSize; i++) {
                printf("%d ", currentLevel[i]);
            }
        } else {
            for (int i = levelSize - 1; i >= 0; i--) {
                printf("%d ", currentLevel[i]);
            }
        }
        
        free(currentLevel);
        leftToRight = !leftToRight; // Toggle direction for next level
    }
}

int main() {
    int N;
    // Read the number of nodes
    if (scanf("%d", &N) != 1) return 1;

    int *arr = (int*)malloc(N * sizeof(int));
    // Read the level order elements
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    // Build the tree
    struct TreeNode* root = buildTree(arr, N);

    // Perform and print zigzag traversal
    zigzagLevelOrder(root);
    printf("\n");

    free(arr);
    return 0;
}
