// #include <stdio.h>

// #include <stdlib.h>
// struct node 
// {
//  int data;
//  struct node *next,*prev;
// };
// struct node *head=NULL;
// void addbeg(int val)
// {
//  struct node *temp;
//  temp=(struct node *)malloc(sizeof(struct node));
//  temp->data=val;
//  temp->prev=NULL;
//  temp->next=head;
//  if (head!=NULL)
//  head->prev=temp;
//  head=temp;
// }
// void append(int val)
// {
//  struct node *tmp,*cur;
//  tmp=(struct node *)malloc(sizeof(struct node));
//  tmp->data=val;
//  tmp->next=NULL;
// if (head==NULL)
//  {
//  tmp->prev=NULL;
//  head=tmp;
//  }
//  else
//  {
//  cur=head;
//  while(cur->next!=NULL)
//  {
//  cur=cur->next;
//  }
//  tmp->prev=cur;
//  cur->next=tmp;
//  }
// }
// void delbeg()
// {
//  if (head==NULL)
//  {
//  return;
//  }
//  else
//  {
//  struct node *temp;
//  temp=head;
//  head=head->next;
// if(head!=NULL)
//  {
//  head->prev=NULL;
//  }
//  free(temp);
//  }
// }
// struct node *linearsearch(int key)
// {
//  struct node *temp;
//  temp=head;
//  while(temp!=NULL)
//  {
//  if (temp->data==key)
//  {
//  return temp;
//  }
//  else
//  {
//  temp=temp->next;
//  }
//  }
//  return NULL;
// }
// void insertafter(struct node *ptr,int val)
// {
//  struct node *temp;
// temp=(struct node *)malloc(sizeof(struct node));
//  temp->data=val;
//  temp->next=ptr->next;
//  temp->prev=ptr;
//  if (ptr->next!=NULL)
//  {
//  ptr->next->prev=temp;
 
//  }
//  ptr->next=temp;
// }
// void insertbefore(struct node *ptr,int val)
// {
//  if (ptr==NULL)
//  {
//  return;
//  }
//  else
//  {
//  struct node *temp;
//  temp=(struct node *)malloc(sizeof(struct node));
//  temp->data=val;
//  temp->next=ptr;
//  temp->prev=ptr->prev;
//  if (ptr->prev!=NULL)
//  {
//  ptr->prev->next=temp;

//  ptr->prev=temp;
//  }
// }
// }
// void delany(struct node *ptr)
// {
//  if (ptr==NULL || ptr==head)
//  return;
//  else
//  {
//  if (ptr->prev!=NULL)
//  {
//  ptr->prev->next=ptr->next;
//  }
//  if (ptr->next!=NULL)
//  {
//  ptr->next->prev=ptr->prev;
//  }
//  free(ptr);
//  }
// }
// void traverse()
// {
//  struct node *cur;
//  cur=head;
//  if(head == NULL){
//  printf("list is empty.");return;
//  }
//  while(cur!=NULL)
//  {
//  printf("%d |",cur->data);
//  cur=cur->next;
//  }
//  printf("\n");
 
// }
// int main()
// {
//  int option,r,val,element,data,n,m,da,key;
//  struct node *ptr,*temp,*ppr,*hold;
//  printf("\n*MAIN MENU*");
//  printf("\n1.Add an element at the begining");
//  printf("\n2.Append an element");
//  printf("\n3.Delete from beginning" );
//  printf("\n4.Search a node" );
//  printf("\n5.Insert an element after a given value");
//  printf("\n6.Insert before a given value");
//  printf("\n7.Delete any node");
//  printf("\n8.Traverse the entire list");
//  printf("\n9.Exit!");
//  do
//  {printf("Enter your choice:");
//  scanf("%d",&option);
//  switch(option)
//  {
//  case 1:
//  printf("Enter the element to be stored:");
//  scanf("%d",&val);
//  addbeg(val);
//  break;
//  case 2:
//  printf("Enter the element to be stored:");
//  scanf("%d",&element);
//  append(element);
//  break;
//  case 3:
//  delbeg();
//  printf("The first node is deleted.\n");
//  break;
//  case 4:
//  printf("Enter the node to be searched:");
//  scanf("%d",&key);
//  hold=linearsearch(key);
//  if(hold==NULL)
//  {
//  printf("The element is not found\n");
//  }else
// printf("The element %d is found",hold->data );
//  break;
//  case 5:
//  printf("Enter the value after which insertion is to be done:");
//  scanf("%d",&r);
//  printf("Enter the element to be stored:");
//  scanf("%d",&data);
//  ptr=linearsearch(r);
//  if (ptr==NULL)
//  {
//  printf("INVALID POSITION\n");
//  }
//  else
//  {
//  insertafter(ptr,data);
//  }
//  break;
//  case 6:
//  printf("Enter the value before which insertion is to be done:");
//  scanf("%d",&n);
//  printf("Enter the element to be stored:");
//  scanf("%d",&da);
//  ppr=linearsearch(n);
//  if (ppr==NULL)
//  {
//  printf("INVALID POSITION\n");
//  }
// else
//  {
//  insertbefore(ppr,da);
//  }
//  break;
 
//  case 7:
//  printf("Enter the element:");
//  scanf("%d",&m);
//  temp=linearsearch(m);
//  if (temp==NULL)
//  {
//  printf("LIST IS EMPTY!\n");
//  }
//  else
//  {
//  delany(temp);
//  printf("The node is deleted.");
//  }
//  break;
//  case 8:
//  printf("The linked list:\n");
//  traverse();
//  break;
//  default:
//  printf("INVALID CHOICE!\n");
//  break;}
//  } while (option!=8);
//  return 0;
// }




#include