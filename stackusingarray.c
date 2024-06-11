#include <stdio.h>
#define SIZE 5
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
printf("ERROR:STACK OVERFLOW!\n");
}
else
{
st.tos++;
st.arr[st.tos]=n;
printf("%d is inserted in the stack.\n",st.arr[st.tos]);
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
int main()
{
init();
printf("MAIN MENU\n----------------------------\n1.Push an element.\n2.Pop an element.\n3.Peek at the top of the stack\n4.Enter 0 to exit!\n--------------------------\n");
int ch,r,top;
do
{
printf("Enter your choice:");
scanf("%d",&ch);
switch(ch)
{
case 1: ;
int n;
printf("Enter the data to be stored:");
scanf("%d",&n);
push(n);
printf("----------------------------\n");
break;
case 2:
r=pop();
if (r!=-9999)
{
printf("%d is popped out from the stack\n",r);
}
else
{
printf("ERROR:STACK UNDERFLOW!\n");
}
printf("----------------------------\n");
break;
case 3:
top=peek();
printf("Top of the stack is :%d\n",top);
printf("----------------------------\n");
break;
case 4:
printf("Exit\n");
printf("----------------------------\n");
break;
default:
printf("INVALID CHOICE!");
printf("----------------------------\n");
}
} while (ch!=0);
}