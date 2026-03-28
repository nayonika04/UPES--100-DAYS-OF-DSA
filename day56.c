#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
bool isMirror(struct TreeNode* leftSubtree, struct TreeNode* rightSubtree) {
    if (leftSubtree == NULL && rightSubtree == NULL) {
        return true;
    }

    if (leftSubtree == NULL || rightSubtree == NULL || leftSubtree->val != rightSubtree->val) {
        return false;
    }

    return isMirror(leftSubtree->left, rightSubtree->right) && isMirror(leftSubtree->right, rightSubtree->left);
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    return isMirror(root->left, root->right);
}
struct TreeNode* buildTree(int* arr, int n) {
    if (n == 0 || arr[0] == -1) {
        return NULL;
    }

    struct TreeNode** queue = (struct TreeNode**)malloc(n * sizeof(struct TreeNode*));
    int head = 0, tail = 0;

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = arr[0];
    root->left = NULL;
    root->right = NULL;
    queue[tail++] = root;

    for (int i = 1; i < n; i++) {
        struct TreeNode* currentNode = queue[head++];
        
        if (i < n && arr[i] != -1) {
            struct TreeNode* leftNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            leftNode->val = arr[i];
            leftNode->left = NULL;
            leftNode->right = NULL;
            currentNode->left = leftNode;
            queue[tail++] = leftNode;
        }
        i++;

        if (i < n && arr[i] != -1) {
            struct TreeNode* rightNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            rightNode->val = arr[i];
            rightNode->left = NULL;
            rightNode->right = NULL;
            currentNode->right = rightNode;
            queue[tail++] = rightNode;
        }
    }
    free(queue); 
    return root;
}

int main() {
    int N;

    if (scanf("%d", &N) != 1) return 1;

    int arr[1000]; 
    for (int i = 0; i < N; i++) {
        if (scanf("%d", &arr[i]) != 1) return 1;
    }
    
    struct TreeNode* root = buildTree(arr, N);

    if (isSymmetric(root)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
