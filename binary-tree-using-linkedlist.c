// Binary tree using linked list
#include <stdio.h>
#include<stdlib.h>
struct TreeNode{
    struct TreeNode* left;
    int data;
    struct TreeNode* right;
};
struct TreeNode* createNode(int value){
struct TreeNode* node=(struct TreeNode*)malloc(sizeof(struct TreeNode));
node->data=value;
node->left=node->right=NULL;
return node;
}
struct TreeNode* insert(struct TreeNode* root, int value){
    if(root==NULL)
    return createNode(value);
    else{
        struct TreeNode* queue[100];
        int front = 0, rear = 0;
        queue[rear++] = root;
        while(front != rear){
            struct TreeNode* temp = queue[front++];
            if(temp->left == NULL){
                temp->left = createNode(value);
                break;
            }
            else if(temp->right == NULL){
                temp->right = createNode(value);
                break;
            }
            else{
                queue[rear++] = temp->left;
                queue[rear++] = temp->right;
            }
            }

    }
}
void preorder(struct TreeNode* root){
    if(root!=NULL){
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct TreeNode*root){
    if(root!=NULL){
    inorder(root->left);
    printf("%d",root->data);
   inorder(root->right);
    }
}
void postorder(struct TreeNode* root){
    if(root!=NULL){
        postorder(root->left);
       postorder(root->right);
       printf("%d",root->data);
} }

void levelorder(struct TreeNode*root){
    struct TreeNode* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while(front != rear)(
        struct TreeNode* temp = queue[front++];
        printf("%d ", temp->data);
        if(temp->left != NULL)
        queue[rear++] = temp->left;
        if(temp->right != NULL)
        queue[rear++] = temp->right;
    )
}
struct TreeNode search(struct treeNode* root, int value){
    struct TreeNode* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while(front != rear)(
        struct TreeNode* temp = queue[front++];
        if(value == temp->data)
        return temp;
        if(temp->left != NULL)
        queue[rear++] = temp->left;
        if(temp->right != NULL)
        queue[rear++] = temp->right;
    )
    return NULL;

}
struct TreeNode* findDeepest(struct TreeNode* root){
    struct TreeNode* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    struct TreeNode* temp;
    while(front != rear)(
        temp = queue[front++];
        if(temp->left != NULL)
        queue[rear++] = temp->left;
        if(temp->right != NULL)
        queue[rear++] = temp->right;
    )
    int i = (rear-2)/2;
    if(queue[i]->left == temp)
    queue[i]->left = NULL;
    else
    queue[i]->right = Null;
    return temp;
}


void delete(struct TreeNode* root, int value){
    struct TreeNode* temp = search(root, value);
    if(temp==NULL)
    printf("Element Not Available !!!!!\n");
    else{
        struct TreeNode* last = findDeepest(root);
        temp->data = last->data;

        
    }
    
    
}
int main(){
    
    int n,choice,index,target,pos;
   while(1){
    printf("1. Insert\n");
    printf("2. Pre-Order\n");
    printf("3. In-Order\n");
    printf("4. Post-order\n");
    printf("5. Level Order\n");
    printf("6.Search\n");
    printf("7.Delete\n");
    printf("8.Exit\n");
    printf("Enter Choice");
    scanf("%d",&choice);
  switch(choice){
    case 1:
    printf("Enter the value of N : ");
    scanf("%d",&n);
    insert(n);
    break;
    case 2:
    printf("\n Pre-Order: ");
    preorder(0);
    break;
    case 3:
    printf("\n In-Order: ");
    inorder(0);
    break;
    case 4:
    printf("\n Post-Order: ");
    postorder(0);
    break;
    case 5:
    printf("\n Post-Order: ");
    postorder(0);
    break;
    case 6:
  printf("Enter Target");
 scanf("%d",&target);
 pos = search(target);
     if(pos == -1)
     printf("Element not found\n");
     else
     printf("Element found at index %d\n", pos);
         break;
        case 7:
            printf("Enter element to delete:");
            scanf("%d",&target);
            delete(target);
            break;

  case 8:
        exit(0);
         break;
         default:
      printf("Invalid Choice !!!!\n");
        }
        printf("\n");
        system("pause"); // without pressing system will not work
 }
return 0;
}