#include<iostream>
#include<stack>
using namespace std;

                                //reverse a string using stack;
// int main(){
//     //   Stack s1(5);
//     string str="babbar";
//     stack<int> s;
    
//     for(int i=0;i<str.length();i++){
//         char ch=str[i];
//         s.push(ch);
//     }

//     string ans="";

//     while(!s.empty()){
//         char ch=s.top();
//         ans.push_back(ch);
//         s.pop();
//     }

//     cout<<"the reverse string is :"<< ans<<endl;
// }


void insertAtBottom(stack<int> a,int ele,int count){                //function to insert at the bottom of the stack
   //base case
   if(count==0){
    a.push(ele);
    return;
   }

   int x=a.top();
   a.pop();

   insertAtBottom(a,ele,count-1);
   a.push(x);
}

void reverseSt(stack<int> &s, int count) {
    // base case
    if (count < 0) {
        return;
    }

    int x = s.top();
    s.pop();

    reverseSt(s, count - 1);
    insertAtBottom(s,x,count);
}

void reverseStack(stack<int> &stack) {
    // Calculate the size of the stack
    int count = stack.size() - 1;

    // Reverse the stack
    reverseSt(stack, count);
}

int main() {
    stack<int> myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    cout<<"original:"<<endl;
    reverseStack(myStack);
    while (!myStack.empty()) {
        cout << myStack.top() << " ";
        myStack.pop();
    }
    cout<<endl;
    // Reverse the stack

    // // Print the elements in the reversed stack
    // while (!myStack.empty()) {
    //     cout << myStack.top() << " ";
    //     myStack.pop();
    // }

    return 0;
}
