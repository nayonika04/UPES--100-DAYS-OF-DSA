#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Swap left and right children recursively
void mirror(struct Node* node) {
    if (node == NULL) return;
    
    struct Node* temp = node->left;
    node->left = node->right;
    node->right = temp;

    mirror(node->left);
    mirror(node->right);
}

// Standard Inorder Traversal
void printInorder(struct Node* node) {
    if (node == NULL) return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

// Build tree from level-order input using a queue
struct Node* buildTree(int n) {
    if (n <= 0) return NULL;
    int val;
    scanf("%d", &val);
    if (val == -1) return NULL;

    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->data = val;
    root->left = root->right = NULL;

    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * n);
    int head = 0, tail = 0;
    queue[tail++] = root;

    for (int i = 1; i < n && head < tail; ) {
        struct Node* curr = queue[head++];
        
        // Process Left Child
        if (scanf("%d", &val) && val != -1) {
            curr->left = (struct Node*)malloc(sizeof(struct Node));
            curr->left->data = val;
            curr->left->left = curr->left->right = NULL;
            queue[tail++] = curr->left;
        }
        i++;

        // Process Right Child
        if (i < n && scanf("%d", &val) && val != -1) {
            curr->right = (struct Node*)malloc(sizeof(struct Node));
            curr->right->data = val;
            curr->right->left = curr->right->right = NULL;
            queue[tail++] = curr->right;
        }
        i++;
    }
    free(queue);
    return root;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    struct Node* root = buildTree(n);
    mirror(root);
    printInorder(root);
    
    return 0;
}
