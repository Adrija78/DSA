#include <stdio.h>
#define MAX_SIZE 5
int queue[MAX_SIZE];
int front = -1, rear = -1;
int isEmpty() 
{
return front == -1 && rear == -1;
}
int isFull() 
{
return (rear + 1) % MAX_SIZE == front;
}
void enqueue(int value) {
if (isFull()) {
printf("Queue is full, cannot enqueue.\n");
return;
}
if (isEmpty()) {
front = rear = 0;
} else {
rear = (rear + 1) % MAX_SIZE;
}
queue[rear] = value;
printf("%d enqueued to the queue.\n", value);
}
void dequeue() {
if (isEmpty()) {
printf("Queue is empty, cannot dequeue.\n");
return;
} else if (front == rear) {
printf("%d dequeued from the queue.\n", queue[front]);
front = rear = -1;
} else {
printf("%d dequeued from the queue.\n", queue[front]);
front = (front + 1) % MAX_SIZE;
}
}
int main() 
{
int choice, value;
while (1) {
printf("Main Menu\n------------\n1.Enqueue\n2.Dequeue\n3.Exit\nEnter your choice:");
scanf("%d", &choice);
switch(choice) {
case 1:
printf("Enter value to enqueue: ");
scanf("%d", &value);
enqueue(value);
break;
case 2:
dequeue();
break;
case 3:
printf("Exiting...\n");
return 0;
default:
printf("Invalid choice, please try again.\n");
}
};
return 0;
}
