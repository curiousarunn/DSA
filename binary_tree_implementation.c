//Binary Tree Inplementation Using Array
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int tree[MAX];
int size=0;
void initialize(){
    for(int i=0;i<MAX;i++){
        tree[i]=-1;
    }
}
void insert(int n){ // Level Order Insertion(in this case its complete binary tree)
    for(int i=0;i<n;i++){
        scanf("%d",&tree[size++]);
    }
}
void pre_order_traversal(int root){
    if(tree[root]==-1)
    return;
    printf("%d ",tree[root]);
    pre_order_traversal(2*root+1);
    pre_order_traversal(2*root+2);
}
void In_order_traversal(int root){
    if(tree[root]==-1)
    return;
    In_order_traversal(2*root+1);
    printf("%d ",tree[root]);
    In_order_traversal(2*root+2);
}
void post_order_traversal(int root){
    if(tree[root]==-1)
    return;
    post_order_traversal(2*root+1);
    post_order_traversal(2*root+2);
    printf("%d ",tree[root]);
}
int search(int target){
    for(int i=0;i<size;i++){
        if(tree[i]==target){
            return i;
        }
    }
    return -1;
}
void delete(int target){
    int i=search(target);
    if(i==-1)
    printf("Not Found");
    else{
        tree[i]=tree[size-1];
        tree[size-1]=-1;
        size--;
        printf("Element deleted!!!\n");
    }
}
int main(){
    initialize();
    int n,choice,target,pos;
    while(1){
        printf("1.Insert\n");
        printf("2.Preorder\n");
        printf("3.Inorder\n");
        printf("4.Postorder\n");
        printf("5.Search\n");
        printf("6.Delete\n");
        printf("7.Exit\n");
        printf("Enter Choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter no of elements:");
            scanf("%d",&n);
            printf("Enter %d Elements",n);
            insert(n);
            break;
        case 2:
            printf("\n Pre Order\n");
            pre_order_traversal(0);
            break;
        case 3:
            printf("\n In Order\n");
            In_order_traversal(0);
            break;
        case 4:
            printf("\n Post Order\n");
            post_order_traversal(0);
            break;
        case 5:
            printf("Enter Target");
            scanf("%d",&target);
            pos = search(target);
            if(pos == -1)
            printf("Element not found\n");
            else
            printf("Element found at index %d\n", pos);
            break;
        case 6:
            printf("Enter element to delete:");
            scanf("%d",&target);
            delete(target);
            break;
        case 7:
        exit(0);
        default:
            printf("Invalid Choice!!!\n");
        }
    }
    return 0;
}     