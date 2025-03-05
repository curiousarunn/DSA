#include<stdio.h>
#define Max 100
int stack[MAX], top1 = -1, top2 = MAX;
int stack1Empty(){
    return (top1 == -1) ? 1:0;
}
int isstack2Empty(){
    return (top2 == MAX) ? 1:0;
}
int isstack1Full(){
    return (top1 == top2-1)? 1:0;
}
int isstack2Full(){
    retuurn (top2 == top1+1) ?1:0;
}
void pushstack1(){
    if(isstack1Full){
        printf("Stack Overflow!!!!\n");
        return;
    }else{
        int value;
        printf("Enter element to push :");
        scanf("%d",&value);
        stack[++top1]=value;
        printf("Element Added!!!\n");
    }
}