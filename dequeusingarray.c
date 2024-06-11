#include<stdio.h>
#define MAX 10
struct queue
{
int arr[MAX];
int rear,front;
};
struct queue q;
void init()
{
q.front=q.rear=-1;
}
int isempty()
{
if(q.front==-1)
return 1;
else
return 0;
}
 int isfull()
{
if(q.front==0&&q.rear==MAX-1||q.front==q.rear+1)
return 1;
else
return 0;
}
void enqueue(int data)
{
if(isfull()==1)
return;
else
{
if(isempty()==1)
q.rear=q.front=MAX-1;
else if(q.front==0)
q.rear=MAX-1;
else
q.front=q.front-1;
q.arr[q.front]=data;
}
}
int dequeue()
{
if(isempty()==1)
return -9999;
else
{
int temp;
temp=q.arr[q.rear];
if(q.front==q.rear)
q.front=q.rear=-1;
else if(q.rear==0)
q.front=MAX-1;
else
 q.rear=q.rear-1;
 return temp;
}
}
int main()
{ 
 init();
printf("\n**MAIN MENU");
printf("\n1.Insert an element:");
printf("\n2.Delete an element:");
printf("\n3.EXIT");
int option,val,num;
do
{
printf("\nENTER YOUR OPTION:");
scanf("%d",&option);
switch(option)
{
case 1:
printf("Enter the number to be inserted:" );
scanf("%d",&num);
printf("The number %d has been inserted in the Double Ended Queue.",num 
);
enqueue(num);
break;
case 2:
val=dequeue();
if(val!=-9999)
{
printf("%d is deleted from the Double Ended Queue.",val);
}
else
printf("ERROR!UNDERFLOW!");
break;
case 3:
printf("EXIT!");
break;
default:
printf("Enter a valid choice!");
 break;
}
}while(option!=3);
return 0;
}