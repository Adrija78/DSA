#include <stdio.h> 
#define size 50
struct stack 
{ 
    int arr[size]; 
    int tos; 
}; 
struct stack st; 
void init()  
{ 
    st.tos=-1; 
} 
int isfull() 
{
    return (st.tos== (size-1)); 
} 
int isempty() 
{ 
    return (st.tos==-1); 
} 
void push(int data) 
{ 
    if (isfull()==1) 
       return; 
    else  
       { 
        st.tos++; 
        st.arr[st.tos]=data; 
       } 
} 
int pop() 
{ 
    if (isempty()==1) 
      return -9999; 
    else  
     { 
        int temp = st.arr[st.tos]; 
        st.tos --; 
        return temp; 
     } 
} 
int peek() 
{ 
    if (isempty()==-1) 
      return -9999; 
    else  
      return st.arr[st.tos]; 
}  
int prcd(char ch) 
{ 
    if (ch=='*' || ch=='/' || ch=='%') 
      return 3; 
    else if (ch=='+' || ch=='-') 
      return 2; 
    else  
     return 1; 
}  
int main() 
{ 
 char a[size], b[size]; 
 int i,j,t; 
 printf("Enter the infix compression:"); 
 scanf("%s",&a); 
 for (i=0,j=0;a[i]!='\0';++i) 
    {  
        if ((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z')||(a[i]>='0'&&a[i]<='9')) 
          b[j++]= a[i]; 
        else  
        { 
          if (a[i]=='(') 
                push(a[i]); 
           else if (a[i]==')') 
            { 
                do 
                { 
                t=pop(); 
                 if (t!='(') 
                     b[j++]=t; 
                }while(t!='('); 
            } 
          else  
            { 
                while(isempty()==0 && (prcd(peek())>=prcd(a[i]))) 
                {b[j++]=pop();} 
                push (a[i]); 
            } 
        } 
    } 
 while(isempty()==0) 
 { 
 b[j++]=pop(); 
 } 
 b[j]='\0'; 
 printf("%s",b); 
 return 0; 
}