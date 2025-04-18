#include<stdio.h>
#include<limits.h>
#define MAX 100
#include<stdlib.h>
int stack[MAX],top=-1;// program mein har jagah use karna hai issliye GLOBALLY DECLARED, top= holds topmost element's index, -1 when stack is empty
int isEmpty(){
    return (top==-1)?1:0;   //ternary condition 
}
int isFull(){
    return (top==MAX-1)?1:0;
}
void push(){      // it will not remove any value that's why void
    if(isFull()){
        printf("Stack Overflow");

    }
    else{
        int value;
        printf("Enter Value : ");
        scanf("%d",&value);
        top++;
        stack[top]=value; // [top] = index of the value
        printf("Element added!!!!\n");
    }
}
int  pop(){     // it will return value that's why int
    if(isEmpty()){
        printf("Stack Underflow!!!!\n");
 return INT_MIN ;
    }
    else{
        int val = stack[top];
       
        top--;
       return val;
    }
}
int  peek(){     // it will return value that's why int
    if(isEmpty()){
        printf("Stack is empty!!!!\n");
 return INT_MIN ; // null is a microfunction, we didnot use zero because element can be zero
    }
    else{
       return stack[top];
    }
}
void show(){
    if(isEmpty())
    printf("Stack is empty !!!!\n");
    else{
        int i;
        for(i=top;i>=0;i--){
  printf("%d\n",stack[i]);
        }
    }
}
int main(){
   system("cls");
    while(1){
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Show\n");
        printf("5.Exit\n");
        int choice,res,ele;
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
         case 1:
        push();
         break;
          case 2:
         res = pop();
         if(res!=INT_MIN)
         printf("%d is pop from the stack\n",res);
         break;
          case 3:
          ele= peek();
        if(ele!=INT_MIN)
         printf("Top element is %d\n",ele);
         break;
          case 4:
       show();
         break;
          case 5:
        exit(0);
         break;
         default:
         printf("Invalid Choice !!!!!\n");
        }
        printf("\n");
        system("pause"); // without pressing system will not work
 }
return 0;
}

    