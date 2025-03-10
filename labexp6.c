#include <stdio.h>
#include<stdlib.h>
#define  SIZE 100
int queue[SIZE], rear=-1,front=-1;
int isEmpty(){
    return(front==-1) ? 1:0;
}
int isFull(){
    return(rear==SIZE-1) ? 1:0;
}
void enqueue(int data){
    queue[++rear] = data;
    if(front==-1)
    front=rear;
    printf("Element inserted\n");

}
int dequeue(){
    int data = queue[front];
    if(front==rear)
    front=rear-1;
    else
    front++;
    return data;

}
int peek(){
    return queue[front];

}
void display(){
    printf("Queue elements are");
    for(int i=front;i<=rear;i++){
        printf("%d ",queue[i]);
    }

}

int main(){
    while(1){
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        int choice,data;
        printf("Enter choice");
        scanf("%d,&choice");
        switch(choice){
            case 1:
            if(isFull())
            printf("Queue overflow !!!!\n");
            else{
                printf("Enter element");
                scanf("%d",&data);
                enqueue(data);
            }
            break;
            case 2:
            if(isEmpty())
            printf("Queue underflow!!!!\n");
            else
            printf("%d dequeue from the queue",dequeue());
            break;
            case 3:
            if(isEmpty())
            printf("Queue is empty\n");
            else
            printf("elements available at front is %d\n",peek);
            break;
            case 4:
            if(isEmpty())
            printf("queue is empty !!!!\n");
            else 
            display();
            break;
            case 5:
            break;
            exit(0);
            default:
            printf("INVALID CHOICE!!!\n");
        }
        printf("\n");

    }
    
    return 0;
}