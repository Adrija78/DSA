// #include <stdio.h> 
// #define SIZE 50 
// struct stack 
// { 
//     int arr[SIZE]; 
//     int tos; 
// }st; 
// void init() 
// { 
//     st.tos=-1; 
// } 
// int isfull() 
// { 
//     if (st.tos==SIZE-1) 
//     { 
//         return 1; 
//     } 
//     else 
//     { 
//         return 0; 
//     } 
// } 
// int isempty() 
// { 
//     if (st.tos==-1) 
//     { 
//         return 1; 
//     } 
//     else 
//     { 
//         return 0; 
//     } 
// } 
// void push(int n) 
// { 
//     if (isfull()) 
//     { 
//         return; 
//     } 
//     else 
//     { 
//         st.tos++; 
//         st.arr[st.tos]=n; 
         
//     } 
// } 
// int pop() 
// { 
//     int temp; 
//     if (isempty()) 
//     { 
//         return -9999; 
//     } 
//     else 
//     {    
//         temp=st.arr[st.tos]; 
//         st.tos--; 
//         return temp; 
//     } 
// } 
// int peek() 
// { 
     
//     if (isempty()==1) 
//     { 
//         return -9999; 
//     } 
//     else 
//     { 
//         return st.arr[st.tos];  
//     } 
// } 
// int prcd(char ch) 
// { 
//     if (ch=='^') 
//         return 4; 
//     else if (ch=='*'|| ch=='/'|| ch=='%') 
//         return 3; 
//     else if (ch=='+' || ch=='-') 
//         return 2; 
//     else 
//         return 1; 
// } 
// int evaluate(int x,int y,char a) 
// { 
//     if (a=='+') 
//        return x+y; 
//     else if (a=='-') 
//        return y-x; 
//     else if(a=='*') 
//        return y*x; 
//     else if (a=='/') 
//        return y/x; 
// } 
// int main() 
// { 
//     init(); 
//     char a[SIZE],b[SIZE]; 
//     printf("The postfix expression:"); 
//     scanf("%s",a); 
//     int i,t,j,x,y,r; 
//     for (i=0,j=0;a[i]!='\0';i++) 
//     { 
//         if ((a[i]>='0' && a[i]<='9') || (a[i]>='A' && a[i]<='Z')) 
//         { 
//             b[j++]=a[i]; 
//         } 
//         else 
//         { 
//             if (a[i]=='(') 
//             { 
//                 push(a[i]); 
//             } 
//             else if (a[i]==')') 
//             { 
//                 do 
//                 { 
//                     t=pop(); 
//                     if (t!='(') 
//                     { 
//                         b[j++]=t; 
//                     } 
//                 }while(t!='(');     
//             } 
//             else 
//             { 
//                 while(isempty()==0 && (prcd(peek())>=prcd(a[i]))) 
//                 { 
//                     b[j++]=pop(); 
//                 } 
//                 push(a[i]); 
//             } 
//         } 
//     } 
//     while (isempty()==0) 
//     { 
//         b[j++]=pop(); 
//     } 
//     b[j]='\0'; 
//     printf("%s\n",b); 
//     for(i=0;b[i]!='\0';i++) 
//     { 
//         if (b[i]>='0' && b[j]<='9') 
//         { 
//             push(b[i]-48); 
//         } 
//         else 
//         { 
//             char t=b[i]; 
//             x=pop(); 
//             y=pop(); 
//             r=evaluate(x,y,t); 
//             push(r); 
//         } 
//     } 
//     int result=pop(); 
//     printf("The evaluation result:%d",result); 
//     return 0; 
// }








#include <stdio.h>  
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 100  
struct stack 
{ 
     int arr[MAX_SIZE]; 
     int tos; 
};
 struct stack st; 
 void init() 
{ 
     st.tos=-1; 
}  
void push(int item) {  
    if (tos >= MAX_SIZE - 1) {  
printf("Stack Overflow\n");  
        return;  
    }  
    tos++;  
    stack[tos] = item;  
}  
int pop() {  
    if (tos < 0) {  
printf("Stack Underflow\n");  
        return -1;  
    }  
    int item = stack[tos];  
    tos--;  
    return item;  
}  
int is_operator(char symbol) {  
    if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/') {  
        return 1;  
    }  
    return 0;  
}  
int evaluate(char* expression) {  
    int i = 0;  
    char symbol = expression[i];  
    int operand1, operand2, result;  
  
    while (symbol != '\0') {  
        if (symbol >= '0' && symbol <= '9') {  
            int num = symbol - '0';  
            push(num);  
        }  
        else if (is_operator(symbol)) {  
            operand2 = pop();  
            operand1 = pop();  
            switch(symbol) {  
                case '+': result = operand1 + operand2; break;  
                case '-': result = operand1 - operand2; break;  
                case '*': result = operand1 * operand2; break;  
                case '/': result = operand1 / operand2; break;  
            }  
            push(result);  
        }  
i++;  
        symbol = expression[i];  
    }  
    result = pop();  
    return result;  
}  
  
int main() {
    char expression[MAX_SIZE];  
    printf("Enter the expression (in postfix notation): ");
    fgets(expression, sizeof(expression), stdin);  
    if (expression[strlen(expression) - 1] == '\n') {
        expression[strlen(expression) - 1] = '\0';
    }

    int result = evaluate(expression);  
    printf("Result= %d\n", result);     
    return 0;
}