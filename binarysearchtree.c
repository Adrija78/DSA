#include <stdio.h>
#include <stdlib.h>
struct Node
{
int data;
struct Node* left;
struct Node* right;
};
struct Node* createNode(int data) 
{
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
if (newNode == NULL) {
printf("Memory allocation failed!\n");
exit(1);
}
newNode->data = data;
newNode->left = NULL;
newNode->right = NULL;
return newNode;
}
struct Node* insertNode(struct Node* root, int data) 
{
if (root == NULL) {
return createNode(data);
}
if (data < root->data) {
root->left = insertNode(root->left, data);
} else if (data > root->data) {
root->right = insertNode(root->right, data);
}
return root;
}
struct Node* minValueNode(struct Node* node) 
{
struct Node* current = node;
while (current && current->left != NULL) {
current = current->left;
}
return current;
}
struct Node* deleteNode(struct Node* root, int data) {
if (root == NULL) {
return root;
}
if (data < root->data) {
root->left = deleteNode(root->left, data);
} else if (data > root->data) {
root->right = deleteNode(root->right, data);
} else {
if (root->left == NULL) {
struct Node* temp = root->right;
free(root);
return temp;
} else if (root->right == NULL) {
struct Node* temp = root->left;
free(root);
return temp;
}
struct Node* temp = minValueNode(root->right);
root->data = temp->data;
root->right = deleteNode(root->right, temp->data);
}
return root;
}
struct Node* searchNode(struct Node* root, int data) {
if (root == NULL || root->data == data) {
return root;
}
if (root->data < data) {
return searchNode(root->right, data);
}
return searchNode(root->left, data);
}
void inorderTraversal(struct Node* root) 
{
if (root != NULL) {
inorderTraversal(root->left);
printf("%d ", root->data);
inorderTraversal(root->right);
}
}
int main() 
{
struct Node* root = NULL;
int choice, data;
do {
printf("\nBinary Search Tree Operations\n");
printf("1. Insert a node\n");
printf("2. Delete a node\n");
printf("3. Search for a node\n");
printf("4. Print inorder traversal\n");
printf("5. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter data to insert: ");
scanf("%d", &data);
root = insertNode(root, data);
break;
case 2:
printf("Enter data to delete: ");
scanf("%d", &data);
root = deleteNode(root, data);
break;
case 3:
printf("Enter data to search: ");
scanf("%d", &data);
if (searchNode(root, data) != NULL) {
printf("Node with data %d found in the tree.\n", data);
} else {
printf("Node with data %d not found in the tree.\n", data);
}
break;
case 4:
printf("Inorder traversal of the tree: ");
inorderTraversal(root);
printf("\n");
break;
case 5:
printf("Exiting...\n");
break;
default:
printf("Invalid choice. Please enter a valid option.\n");
}
} while (choice != 5);
return 0;
}