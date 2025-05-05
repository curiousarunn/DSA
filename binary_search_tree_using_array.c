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
void insert(int value,int root){
    if(tree[root]==-1)
    tree[root] = value;
    else if(value< tree[root])
    insert(value, 2*root+1);
    else if(value>tree[root])
    insert(value,2*root+2);
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
// int search(int i,int target){
     
// }
int search(int target,int root){
    if(root>=MAX || tree[root]==-1)
    return -1;
    else if(tree[root]==target)
    return root;
    else if(target<tree[root])
    return search(2*root+1, target);
    else
    return search(2*root+2,target);

}
void delete(int i, int value){
    i = search(i, value);
    if(i==-1)
    printf("Element Not Found !!!!!\n")
    else
    int left = 2*i+1;
    int right = 2*i+2;
    if((left==MAX || tree[left]==-1) && (right>=MAX || tree[right]==-1))
    tree[i] = -1;
    else if(tree[left]==-1){
        int min = findMin(right);
        tree[i] = tree[min];
        delete(min, tree[min]);
    }
    else if(tree[right]==-1){
        int max = findMax(left);
        tree[i] = tree[max];
        delete(max, tree[max]);
    }
    else{
        int min = findMin(right);
        tree[i] = tree[min]
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
            printf("Enter the value:");
            scanf("%d",&n);
            insert(n,0);
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
            pos = search(target , 0);
            if(pos == -1)
            printf("Element not found\n");
            else
            printf("Element found at index %d\n", pos);
            break;
        // case 6:
        //     printf("Enter element to delete:");
        //     scanf("%d",&target);
        //     delete(target);
        //     break;*/
        case 7:
        exit(0);
        default:
            printf("Invalid Choice!!!\n");
        }
    }
    return 0;
}     