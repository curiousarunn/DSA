#include<stdio.h>
#include<stdlib.h>
struct Node{
struct Node* prev;
   int data;
  struct Node *next;
};
 struct Node* head=NULL;
 struct Node* createNode(int ele){
   struct  Node* temp=(struct Node*)malloc(sizeof(struct Node));//pointer ko memeory de rahe hain issliye pointer mein typecasting ki hai
 temp->data=ele;//newnode ke data field mein element de diya
 temp->prev=temp->next=NULL;
 return temp;
    temp->data=ele;//newnode ke data field mein element de diya
    temp->prev=temp->next=NULL;
    return temp;
 }
 void insertNodeInBeg(int ele){
 struct Node* newNode = createNode(ele);
 if(head == NULL)
 head=newNode;
 else{
 newNode->next=head;
 head->prev=newNode;
 head=newNode;
 printf("Node Inserted !!!\n");
 }
    struct Node* newNode = createNode(ele);
    if(head == NULL)
       head=newNode;
    else{
       newNode->next=head;
       head->prev=newNode;
       head=newNode;
    }
    printf("Node Inserted !!!\n");
 }
 void insertNodeAtEnd(int ele){
   struct Node* newNode = createNode(ele);
   }
 else{
   struct Node* newNode = createNode(ele);
    newNode->data=ele;
    newNode->next=NULL;
    struct Node* temp=head;
 
    
    int i=1;
    while(i<pos && temp->next !=NULL){
       temp=temp->next;
       i++;
    }
    if(temp->next !=NULL && pos>0){
       newNode->next=temp;
      
        newNode->prev=temp->prev;
        temp->prev->next=newNode;
        temp->prev=newNode;
        newNode->next=temp;
         temp->prev=newNode;
       printf("Node Inserted !!!!\n");
    }
    else{
 
    printf("List is Empty!!!\n");
    }
    else{
       Node*t=head;
       struct Node*temp=head;
       head=head->next;
       free(t);
       if(head!=NULL);
       head->prev=NULL;
       free(temp);
       printf("Node Deleted !!!\n");
    }
 }
 void deleteNodefromEnd(){
    if(head==NULL)
    printf("List is empty !!!\n");
    else{
   Node* t;
    if(head->next==NULL){//list contains single node
   t=head;
   head=NULL;
    }
   else{//list contain more than one node
    Node* temp=head;
    while(temp->next->next!=NULL){
   else{
   struct Node* temp=head;
    while(temp->next!=NULL){
       temp=temp->next;
    }
    t=temp->next;
    temp->next=NULL;
   }
   free(t);
    if(temp->prev!=NULL)
    temp->prev->next=NULL;
    else
    head=NULL;
    
   free(temp);
 
 printf("Node Deleted !!!\n");
 }
    if(head==NULL)
  printf("List is empty !!!\n");
    else if(pos==1){
       deleteNodefromBeg();
      deleteNodefromBeg();
    }
    else{
       int i=1;
       Node* temp=head;
       while(i<pos-1 && temp->next!=NULL){
      int i=1;
      struct Node* temp=head;
       while(i!=pos && temp!=NULL){
          i++;
          temp=temp->next;
         
       }
       if(temp->next!=NULL && pos>0){
         Node* t=temp->next;
          temp->next=temp->next->next;
          free(t);
          printf("Node Deleted !!!\n");
       temp->prev->next=temp->next;
       if(temp->next!=NULL){
         
           temp->next->prev=temp->prev;
       free(temp);
       }
       else
       else 
       printf("Invalid Position");
    }
 }
 void search(int target){
    if(head==NULL)
    printf("List is empty !!!\n");
    else{
       Node* temp=head;
      struct Node* temp=head;
       while(temp!=NULL){
          if(temp->data==target){
             printf("Found !!!\n");
 
    }
 }
 void sort(){
    Node* last=NULL;
    for(Node* i = head; i->next!=NULL;i=i->next){
       Node* j;// j ki value loop ke bahar leni hai
   struct Node* last=NULL;
    for(struct Node* i = head; i->next!=NULL;i=i->next){
       struct Node* j;// j ki value loop ke bahar leni hai
       for( j = head; j->next!=last ; j=j->next){
          if(j->data > j->next->data){
             int temp=j->data;
    printf("List is empty !!!\n");
    else{
       printf("Elements are : \n");
       Node* temp=head;
      struct Node* temp=head;
       while(temp!=NULL){
          printf("%d ",temp->data);
          temp=temp->next;
 int main(){
    system("cls");
     while(1){
        printf("---- Singly Linked List ----\n");
        printf("---- Singly Linked List ----\n");     
         printf("1. Insert Node In Beginning\n");
         printf("2.Insert Node At End\n");
         printf("3.Insert Node At Any Position \n");
         scanf("%d",&choice);
         switch(choice)
         {
          case 1:
         case 1:
         printf("Enter value: ");
         scanf("%d",&value);
         insertNodeInBeg(value);
        break;
          case 2:
          printf("Enter value: ");
         scanf("%d",&value);
        insertNodeAtEnd(value);
         break;
          case 3:
           printf("Enter value: ");
        scanf("%d",&value);
        printf("Enter Position: ");
          scanf("%d",&pos);
        insertNodeAtAnyPos(value,pos);
         break;
          case 4:
          
         deleteNodefromBeg();
         break;
          case 5:
          
        deleteNodefromEnd();
         break;
         case 6:
       printf("Enter position");
       scanf("%d",&pos);
        deleteNodeFromAnyPos(pos);
         break;
         case 7:
         printf("Enter the searching element");
            scanf("%d",&target);
            search(target);
         break;
        
         case 8:
        display();
         break;
         case 9:
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