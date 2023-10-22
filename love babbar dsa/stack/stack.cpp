// #include<iostream>
// #include <stdlib.h>
// #include<string.h>
// using namespace std;
// #define n 100
/*
class stack{
    int* arr;
    int top;

    public:
    stack(){
        arr=new int[n];
        top=-1;
    }
    void push(int x){
        if(top==n-1){
            cout<<"stack overflow";
        }
        else{
            top++;
            arr[top]=x;
        }
    }
    int pop(){
        if(top==-1){
            cout<<"stack underflow";
        }
        else{
            return arr[top--];
        }
        return -1;

    }

};

int main(){
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.pop()<<endl;
    cout<<st.pop()<<endl;
    cout<<st.pop()<<endl;
    cout<<st.pop();

}

class stack{
    private:
    int* arr;
    int top;

    public:
    stack(){
        arr=new int[n];
        top=-1;
    }

    void push(int x){
        if(top==n-1){
            cout<<"stack overflow";
        }
        else{
            top++;
            arr[top]=x;
        }
    }
    int pop(){
        int x=-1;
        if(top==-1){
            cout<<"stack underflow";
        }
        else{
            x= arr[top--];
        }
        return x;
    }
    int peek(int i){
        int x=-1;
        if(top-i+1<0){
            cout<<"invalid pos";
        }
        else{
            x=arr[top-i+1];
        }
        return x;
    }
};

int main(){
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.peek(1)<<endl;
    cout<<st.pop()<<endl;
    cout<<st.peek(1)<<endl;
}

*/







// #include <iostream>
// #include <cstring>

// using namespace std;

// struct Stack {
//     char data[100];
//     int top;
// };

// // Function to check if the stack is empty
// bool isEmpty(Stack &st) {
//     return st.top == -1;
// }

// // Function to push an element onto the stack
// void push(Stack &st, char x) {
//     st.data[++st.top] = x;
// }

// // Function to pop an element from the stack
// char pop(Stack &st) {
//     if (!isEmpty(st)) {
//         return st.data[st.top--];
//     }
//     return '\0'; // Return null character if the stack is empty
// }

// // Function to get the precedence of an operator
// int pre(char x) {
//     if (x == '+' || x == '-') {
//         return 1;
//     } else if (x == '*' || x == '/') {
//         return 2;
//     } else {
//         return 0;
//     }
// }

// // Function to check if a character is an operand
// bool isOperand(char x) {
//     return (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z');
// }

// char* infixToPostfix(const char* infix) {
//     Stack st;
//     st.top = -1; // Initialize the stack top

//     int length = strlen(infix);
//     char* postfix = new char[length];
//     int i = 0, j = 0;

//     while (infix[i] != '\0') {
//         if (isOperand(infix[i])) {
//             postfix[j++] = infix[i++];
//         } else {
//             if (pre(infix[i]) > pre(st.data[st.top]) || isEmpty(st)) {
//                 push(st, infix[i++]);
//             } else {
//                 postfix[j++] = pop(st);
//             }
//         }
//     }

//     while (!isEmpty(st)) {
//         postfix[j++] = pop(st);
//     }

//     postfix[j] = '\0';
//     return postfix;
// }

// int main() {
//     Stack st;
//     const char* infix = "a+b*c";
//     push(st, '#');
//     char* postfix = infixToPostfix(infix);
//     cout << postfix << endl;
    
//     delete[] postfix; // Don't forget to free the memory allocated for postfix
//     return 0;

// }



// #include<iostream>
// #include<stdio.h>
// #include<stdlib.h>
// using namespace std;
// int main(){
//     int s[10],choice,top=-1,m,c;
//     int n,x;
//     printf("enter the size of stack:");
//     scanf("%d",&n);
//     while(m!=0){
//         printf("**stack menu**");
//         printf("\n1.push\n2.pop\n3.peep\n4.Display\n5.change\n6.exit\n");
//         printf("enter your choice:");
//         scanf("%d",&c);
//         if(c==1){
//             if(top>=n-1){
//                 printf("stack is overflow\n");
//             }
//             else{
//                 printf("enter element to push:");
//                 scanf("%d",&x);
//                 top=top+1;
//                 s[top]=x;
//             }
//         }
//         else if(c==2){
//             if(top<=-1){
//                 printf("stack is underflow");
//             }
//             else{
//                 printf("the poped element is: %d",s[top]);
//                 top=top-1;
//             }
//         }
//         else if(c==6){
//             exit(0);
//         }
//         else{
//             printf("enter valid number.");
//         }

//     }
// }



#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int main(){
    int arr[10],top=-1,m,ele,pos,k,value;
    int choice;
    int size;
    printf("enter the size:");
    scanf("%d",&size);
    while(m!=0){
        printf("\n**stack menu**\n");
        printf("\n1.push\n2.pop\n3.peek\n4.display\n5.change\n6.exit\n");
        scanf("%d",&choice);
        if(choice==1){
            if(top>=size-1){
                printf("\nstack overflow");
            }
            else{
                printf("\nenter the element to be entered:");
                scanf("%d",&ele);
                top++;
                arr[top]=ele;
            }
        }
        else if(choice==2){
            if(top==-1){
                printf("\nstack is underflow");
            }
            else{
                printf("\nthe poped ele is:%d",arr[top]);
                top--;
            }
        }
        else if(choice==3){
            printf("\nenter the position to be viewed:");
            scanf("%d",&pos);

            if(top-pos-1<0){
                printf("\nenter the valid position.");
            }
            else{
                printf("\nthe ele is:%d",arr[top-pos+1]);
            }
        }
        else if(choice==4){
            if(top==-1){
                printf("\nstack is empty");
            }
            else{
                for(int i=top;i>=0;i--){
                    printf("%d ",arr[i]);
                }
            }
        }
        else if(choice==5){
            printf("\nenter the position of element to be changed:");
            scanf("%d",&k);
            if(k<0){
                printf("\nenter the valid number.");
            }
            else{
                printf("\nenter the value:");
                scanf("%d",&value);
                for(int i=0;i<top;i++){
                    if(i==top){
                        arr[i]=value;
                    }
                }
            }
        }
        else if(choice==6){
            exit(0);
        }
        else{
            printf("\nenter the valid number.");
        }
    }
}