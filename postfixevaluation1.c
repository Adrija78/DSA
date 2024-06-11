// #include <stdio.h> 
// #define size 50
// struct stack 
// { 
//     int arr[size]; 
//     int tos; 
// }; 
// struct stack st; 
// void init()  
// { 
//     st.tos=-1; 
// } 
// int isfull() 
// {
//     return (st.tos== (size-1)); 
// } 
// int isempty() 
// { 
//     return (st.tos==-1); 
// } 
// void push(int data) 
// { 
//     if (isfull()==1) 
//        return; 
//     else  
//        { 
//         st.tos++; 
//         st.arr[st.tos]=data; 
//        } 
// } 
// int pop() 
// { 
//     if (isempty()==1) 
//       return -9999; 
//     else  
//      { 
//         int temp = st.arr[st.tos]; 
//         st.tos --; 
//         return temp; 
//      } 
// } 
// int peek() 
// { 
//     if (isempty()==-1) 
//       return -9999; 
//     else  
//       return st.arr[st.tos]; 
// }  
// int prcd(char ch) 
// { 
//     if (ch=='*' || ch=='/' || ch=='%') 
//       return 3; 
//     else if (ch=='+' || ch=='-') 
//       return 2; 
//     else  
//      return 1; 
// }  
// int main() 
// { 
//  char a[size], b[size]; 
//  int i,j,t; 
//  printf("Enter the infix compression:"); 
//  scanf("%s",&a); 
//  for (i=0,j=0;a[i]!='\0';++i) 
//     {  
//         if ((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z')||(a[i]>='0'&&a[i]<='9')) 
//           b[j++]= a[i]; 
//         else  
//         { 
//           if (a[i]=='(') 
//                 push(a[i]); 
//            else if (a[i]==')') 
//             { 
//                 do 
//                 { 
//                 t=pop(); 
//                  if (t!='(') 
//                      b[j++]=t; 
//                 }while(t!='('); 
//             } 
//           else  
//             { 
//                 while(isempty()==0 && (prcd(peek())>=prcd(a[i]))) 
//                 {b[j++]=pop();} 
//                 push (a[i]); 
//             } 
//         } 
//     } 
//  while(isempty()==0) 
//  { 
//  b[j++]=pop(); 
//  } 
//  b[j]='\0'; 
//  printf("%s",b); 
//  init();
//  for(int k=0;b[k]!='\0';k++)
//  {
//     if (b[k]>='0'&&b[k]<='9')
//     push(b[k]-'0');
//     else{
//         int x=pop();
//         int y=pop();
//         if(b[k]='+')
//         {
//             push(x+y);
//         }
//         else if(b[k]='-')
//         {
//             push(y-x);
//         }
//         else if(b[k]='*')
//         {
//             push(x*y);
//         }
//         else if(b[k]='/')
//         {
//             push(y/x);
//         }
//     }
//  }
//  printf("%d",pop());
//  return 0; 
// }





#include <stdio.h>
#define SIZE 50
struct stack
{
int arr[SIZE];
int tos;
}st;
void init()
{
st.tos=-1;
}
int isfull()
{
if (st.tos==SIZE-1)
{
return 1;
}
else
{
return 0;
}
}
int isempty()
{
if (st.tos==-1)
{
return 1;
}
else
{
return 0;
}
}
void push(int n)
{
if (isfull())
{
return;
}
else
{
st.tos++;
st.arr[st.tos]=n;
}
}
int pop()
{
int temp;
if (isempty())
{
return -9999;
}
else
{ 
temp=st.arr[st.tos];
st.tos--;
return temp;
}
}
int peek()
{
if (isempty()==1)
{
return -9999;
}
else
{
return st.arr[st.tos]; 
}
}
int prcd(char ch)
{
if (ch=='^')
return 4;
else if (ch=='*'|| ch=='/'|| ch=='%')
return 3;
else if (ch=='+' || ch=='-')
return 2;
else
return 1;
}
int evaluate(int x,int y,char a)
{
if (a=='+')
return x+y;
else if (a=='-')
return y-x;
else if(a=='*')
return y*x;
else if (a=='/')
return y/x;
}
int main()
{
init();
char a[SIZE],b[SIZE];
printf("The postfix expression:");
scanf("%s",&a);
int i,t,j,x,y,r;
for (i=0,j=0;a[i]!='\0';i++)
{
if ((a[i]>='0' && a[i]<='9') || (a[i]>='A' && a[i]<='Z'))
{
b[j++]=a[i];
}
else
{
if (a[i]=='(')
{
push(a[i]);
}
else if (a[i]==')')
{
do
{
t=pop();
if (t!='(')
{
b[j++]=t;
}
}while(t!='('); 
}
else
{
while(isempty()==0 && (prcd(peek())>=prcd(a[i])))
{
b[j++]=pop();
}
push(a[i]);
}
}
}
while (isempty()==0)
{
b[j++]=pop();
}
b[j]='\0';
printf("%s\n",b);
for(i=0;b[i]!='\0';i++)
{
if (b[i]>='0' && b[j]<='9')
{
push(b[i]-0);
}
else
{
char t=b[i];
x=pop();
y=pop();
r=evaluate(x,y,t);
push(r);
}
}
int result=pop();
printf("The evaluation result:%d",result);
return 0;
}
