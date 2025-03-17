#include <stdio.h>
#include <limits.h>
#define SIZE 100
#include <stdlib.h>
typedef struct PriorityQuue{
    int element;
    int priority;
} PQueue;
PQueue pq[SIZE];
int front=-1,rear=-1;
int isEmpty()
{
    return (front == -1) ? 1 : 0; // ternary condition
}
int isFull()
{
    return (rear == SIZE - 1) ? 1 : 0;
}
void enqueue(int data,int priority)
{                         // it will not remove any value that's why void
   rear=rear+1;
   pq[rear].element=data;// yahan +isliye nhi hua coz phir 2 times ho jaata
   pq[rear].priority=priority;
   if(front==-1)
   front=rear;
   printf("Element Inserted !!!!\n");
}
int getHigherPriorityElement(){
    int max = 0,index=-1;
    for(int i=front;i<=rear;i++){
        if(pq[i].priority>max){
            max=pq[i].priority;// index return
       index=i;
     }
    } 
    return index;
}
int dequeue()
{ 
    int index = getHigherPriorityElement();
    int data = pq[index].element;
    if(index == front && index == rear)
    front=rear=-1;
    else if(index == front)
    front++;
    else{
        for(int i=index;i<rear;i++){
            pq[i]=pq[i+1];
        }
        rear--;
    }
    return data;
}
int peek()//front
{ 
    int i=getHigherPriorityElement();
    return pq[i].element;
}
int display()
{
    printf("Elements of priority queue are :\n");
    for(int i=front;i<=rear;i++){
        printf("Element : %d => Priority: %d\n", pq[i].element,pq[i].priority);
    }
}
int main()
{
    system("cls");
    while (1)
    {
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Peek\n");
        printf("4.Show\n");
        printf("5.Exit\n");
        int choice, data,p;
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (isFull())
                printf("Queue Overflow !!!!\n");
            else
            {
                printf("Enter element: ");
                scanf("%d", &data);
                printf("Enter Priority: ");
                scanf("%d", &p);
                enqueue(data,p);
            }
            break;
        case 2:
            if (isEmpty())
                printf("Queue Underflow!!!!\n");
            else
            {
                printf("%d dequeue from the queue\n", dequeue());
            }
        case 3:
            if (isEmpty())
                printf("Queue is empty!!!!\n");
            else
            {
                printf("Element available at front is %d\n", peek());
            }

            break;
        case 4:
            if (isEmpty())
                printf("Queue is empty!!!!\n");
            else
            {
                display();
            }

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