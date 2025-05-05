#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    struct TreeNode *left;
    int data;
    struct TreeNode *right;
};
struct TreeNode *createNode(int value) {
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->data = value;
    node->left = node->right = NULL;
    return node;
}
struct TreeNode *insert(struct TreeNode *root, int value) {
    if (root == NULL)
        return createNode(value);
    else if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}
void preorder(struct TreeNode *root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct TreeNode *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(struct TreeNode *root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

struct TreeNode *findMin(struct TreeNode *root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct TreeNode *delete(struct TreeNode *root, int value) {
    if (root == NULL)
        return NULL;
    else if (value < root->data)
        root->left = delete(root->left, value);
    else if (value > root->data)
        root->right = delete(root->right, value);
    else {
        // Node found
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else if (root->left == NULL) {
            struct TreeNode *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode *temp = root->left;
            free(root);
            return temp;
        } else {
            struct TreeNode *temp = findMin(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}

struct TreeNode *search(struct TreeNode *root, int value) {
    if (root == NULL)
        return NULL;
    else if (root->data == value)
        return root;
    else if (value < root->data)
        return search(root->left, value);
    else
        return search(root->right, value);
}

int main() {
    int choice, val;
    struct TreeNode *root = NULL;
    while (1) {
        printf("\n1. Insert\n");
        printf("2. Pre-Order\n");
        printf("3. In-Order\n");
        printf("4. Post-Order\n");
        printf("5. Search\n");
        printf("6. Delete\n");
        printf("7. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter Element: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            case 2:
                preorder(root);
                printf("\n");
                break;
            case 3:
                inorder(root);
                printf("\n");
                break;
            case 4:
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Enter Value: ");
                scanf("%d", &val);
                if (search(root, val) == NULL)
                    printf("Element Not Found!\n");
                else
                    printf("Element Found\n");
                break;
            case 6:
                printf("Enter Value to Delete: ");
                scanf("%d", &val);
                root = delete(root, val);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}