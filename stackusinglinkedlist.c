// #include <stdio.h>
// #include <stdlib.h>
// struct Node {
//     int data;
//     struct Node* next;
// };
// struct Node* tos;
// void init()
// {
//     tos=NULL;
// }
// void push(int value) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     if (newNode == NULL) {
//         printf("Memory allocation failed. Stack overflow!\n");
//         return;
//     }
//     newNode->data = value;
//     newNode->next = tos;
//     tos = newNode;
// }
// int pop() {
//     if (tos == NULL) {
//         printf("Stack is empty. Nothing to pop!\n");
//         return -1;
//     }
//     int poppedValue = tos->data;
//     struct Node* temp = tos;
//     tos = tos->next;
//     free(temp);
//     return poppedValue;
// }
// int peek() {
//     if (tos == NULL) {
//         printf("Stack is empty!\n");
//         return -1;
//     }
//    return tos->data;
// }
// void display() {
//     if (tos == NULL) {
//         printf("Stack is empty!\n");
//         return;
//     }
//     struct Node* current = tos;
//     printf("Stack: ");
//     while (current != NULL) {
//         printf("%d ", current->data);
//         current = current->next;
//     }
//     printf("\n");
// }
// int main() {
//     push(1);
//     push(2);
//     push(3);
//     display();
//     printf("Top of the stack: %d\n", peek());
//     printf("Popped element: %d\n", pop());
//     display();
//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *tos = NULL; 

void push() {
    struct Node *tmp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data to push: ");
    scanf("%d", &tmp->data);
    tmp->next = tos;
    tos = tmp;
}

int pop() {
    if (tos == NULL) {
        return -9999;
    }

    struct Node *temp = tos;
    int poppedData = temp->data;
    tos = tos->next;
    free(temp); 
    printf("Popped element: %d\n", poppedData);
}

int peek() {
    if (tos == NULL) {
        return -9999;
    }

    printf("Top element: %d\n", tos->data);
}

int isEmpty() {
    return tos == NULL;
}

int display() {
    if (tos == NULL) {
        return -9999;
    }

    struct Node *temp = tos;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nStack Operations:\n1. Push\n2. Pop\n3. Peek\n4. Check if empty\n5. Display stack\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                if (isEmpty()) {
                    printf("Stack is empty\n");
                } else {
                    printf("Stack is not empty\n");
                }
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}    