#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int precedence(char op){
    switch(op){   // if break is not used such a condition is known as fall through

        case '+':
        case '-':
         return 1;
         case '*':
        case '/':
         return 2;
         case '^':
         return 3;
         default:
         return -1; // to check brackets , so the logic donot give garbage value , 1 se less nu8mber lena hai toh hum -2,-3 etc.bhi le sakte hain
    }
}
   char* convertInfixToPostfix(char* exp){
    int size=strlen(exp),top=-1,index=0;
    char* str=(char*)malloc(size+1);
    char stack[size];
    for(int i=0;i<size;i++){
        char ch=exp[i];
        if(isalnum(ch)){
str[index++]=ch;
        }
        else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'){
           if(top==-1)
           stack[++top]=ch;
           else{
            while(top!=-1 && precedence (ch)<=precedence(stack[top])){
                str[index++]=stack[top--];
            }
            stack[++top]=ch;
           }
        }
            else if(ch=='('){
                stack[++top]=ch;
            }
            else if(ch==')'){
                while(stack[top]!='('){ //jab tak operator stack ke top pe ) na aaye tab tak process repeat karo& jab miljaaye tab process terminate karo &element pop karo
                   str[index++]=stack[top--]; // index increase , stack decrease
                   
                }
                top--;
          }
          }
          while(top!=-1){
            str[index++]=stack[top--];
          }
          str[index]='\0'; // to terminate the string
          return str;
    }

char* convertInfixToPrefix(char* exp){
    int size=strlen(exp),top=-1,index=0;
    char* str=(char*)malloc(size+1);
    char stack[size];
    for(int i=size-1;i>=0;i--){
        char ch=exp[i];
        if(isalnum(ch)){
str[index++]=ch;
        }
        else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'){
           if(top==-1)
           stack[++top]=ch;
           else{
            while(top!=-1 && precedence (ch)<=precedence(stack[top])){
                str[index++]=stack[top--];
            }
            stack[++top]=ch;
           }
        }
            else if(ch==')'){
                stack[++top]=ch;
            }
            else if(ch=='('){
                while(stack[top]!=')'){ //jab tak operator stack ke top pe ) na aaye tab tak process repeat karo& jab miljaaye tab process terminate karo &element pop karo
                   str[index++]=stack[top--]; // index increase , stack decrease
                   
                }
                top--;
          }
          }
          while(top!=-1){
            str[index++]=stack[top--];
          }
          str[index]='\0'; // to terminate the string
          return strrev(str);
         
    }
    char* convertPostfixToInfix(char* exp){
        int size=strlen(exp),top=-1;
 char stack[size][100];
 for(int i=0;i<size;i++){
    char ch=exp[i];
    if(isalnum(ch)){
char temp[]={ch,'\0'};
strcpy(stack[++top],temp);
    }
    else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'){
       char *s1=stack[top--];
       char *s2=stack[top--];
       char s3[100];
       snprintf(s3,100,"(%s%c%s)",s2,ch,s1);
       strcpy(stack[++top],s3);
    }
 }
 char *s=(char*)malloc(strlen(stack[top])+1);
 strcpy(s,stack[top]);
 return s;
    }
    char* convertPrefixToInfix(char* exp){
        int size=strlen(exp),top=-1;
 char stack[size][100];
 for(int i=size-1;i>=0;i--){
    char ch=exp[i];
    if(isalnum(ch)){
char temp[]={ch,'\0'};
strcpy(stack[++top],temp);
    }
    else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'){
       char *s1=stack[top--];
       char *s2=stack[top--];
       char s3[100];
       snprintf(s3,100,"(%s%c%s)",s1,ch,s2);
       strcpy(stack[++top],s3);
    }
 }
 char *s=(char*)malloc(strlen(stack[top])+1);
 strcpy(s,stack[top]);
 return s;
    }
        int main(){
      //  system("cls");
        char exp[100];
        printf("Enter Infix Expression: ");
       
        gets(exp);
        printf("Postfix form of Infix expression %s is %s\n",exp,convertInfixToPostfix(exp));
         printf("Enter Infix Expression: ");
       
        gets(exp);
        printf("Prefix form of Infix expression %s is %s\n",exp,convertInfixToPrefix(exp));
        printf("Enter Postfix Expression: ");
       
        gets(exp);
        printf("Infix form of Postfix expression %s is %s\n",exp,convertPostfixToInfix(exp));
         printf("Enter Prefix Expression: ");
       
        gets(exp);
        printf("Infix form of Prefix expression %s is %s\n",exp,convertPrefixToInfix(exp));
       
    return 0;
}