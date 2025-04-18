#include<ctype.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
int top1=-1,top2=-1;
int operand[100];
char operator[100];
void doProcess(){
    int x=operand[top1--];
    int y=operand[top1--];
    char opr = operator[top2--];
    int z;
    switch(opr){         // switch is better than else if laddar
        case '+':
        z=y+x;
        break;
        case '-':
        z=y-x;
        break;
        case '*':
        z=y*x;
        break;
        case '/':
        z=y/x;
        break;
        case '^': // carat
        z=pow(y,x); // <math.h>
        break;
    }
    operand[++top1]=z;
}
int precedence(char opr){
    switch(opr){   // if break is not used such a condition is known as fall through

        case '+':
        case '-':
         return 1;
         case '*':
        case '/':
         return 2;
         case '^':
         return 3;
         default:
         return -1; // to check brackets , so the logic donot give garbage value
    }
}
    int evalInfixExpression(char*exp){ //exp=expression array name
  int size = strlen(exp);
  for(int i=0;i<size;i++){
    char ch=exp[i];
    if(isdigit(ch)){
        int num=0;
        while(isdigit(exp[i])){ // string mein se number nikalne ka logic
            num=num*10+exp[i]-48;
       i++;
     }
        i--;
operand[++top1]=num;
    }
    else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'){
 if(top2==-1)
 operator[++top2]=ch;
     else{
       while(top2!=-1 && precedence(ch)<=precedence(operator[top2])){
        doProcess();
    }
    operator[++top2]=ch;
  }
  }
     else if(ch=='('){
        operator[++top2]=ch;
    }
    else if(ch==')'){
        while(operator[top2]!='('){ //jab tak operator stack ke top pe ) na aaye tab tak process repeat karo& jab miljaaye tab process terminate karo &element pop karo
            doProcess();
        }
        top2--;
  }
  }
  while(top2!=-1){
doProcess();
  }
  return  operand[top1--];
  }

  int evalPostFixExpression(char *exp){  
  int size=strlen(exp);
  for(int i=0;i<size;i++){ // iteration from left to right
 char ch= exp[i];
 if(isdigit(ch)){
    int num=0;
    while(isdigit(exp[i])){ // string mein se number nikalne ka logic
        num=num*10+exp[i]-'0';
   i++;
 }
    i--;
operand[++top1]=num;
}
else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'){
    int x=operand[top1--];
    int y=operand[top1--];
    int z;
    switch(ch){         // switch is better than else if laddar
        case '+':
        z=y+x;
        break;
        case '-':
        z=y-x;
        break;
        case '*':
        z=y*x;
        break;
        case '/':
        z=y/x;
        break;
        case '^': // carat
        z=pow(y,x); // <math.h>
        break;
    }
    operand[++top1]=z;
}
  }
  return operand[top1--];
}
int evalPreFixExpression(char *exp){  
    int size=strlen(exp);
    for(int i=size-1;i>=0;i--){ // iteration from left to right
   char ch= exp[i];
   if(isdigit(ch)){
      int num=0, place=1;
      while(isdigit(exp[i])){ // string mein se number nikalne ka logic
          num=num + (exp[i]-'0')*place;
          place*=10;
i--;
   }
      i++;
  operand[++top1]=num;
  }
  else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'){
      int x=operand[top1--];
      int y=operand[top1--];
      int z;
      switch(ch){         // switch is better than else if laddar
          case '+':
          z=y+x;
          break;
          case '-':
          z=y-x;
          break;
          case '*':
          z=y*x;
          break;
          case '/':
          z=y/x;
          break;
          case '^': // carat
          z=pow(y,x); // <math.h>
          break;
      }
      operand[++top1]=z;
  }
    }
    return operand[top1--];
  }
int main(){
    system("cls");
    char str[100];
    printf("Enter Infix Expression: ");
   
    gets(str);
    int result=evalInfixExpression(str);
    printf("Result : %d\n",result);
     printf("Enter Postfix Expression: ");
     gets(str);
     int result1=evalPostFixExpression(str);
   
     
     printf("Result : %d\n",result1);
     printf("Enter prefix Expression: ");
   
    gets(str);
    int result2=evalPreFixExpression(str);
    printf("Result2 : %d\n",result2);
    return 0;
}
  