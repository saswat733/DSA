#include<iostream>
#include<stack>

using namespace std;

class Stack{
   int *arr;
   int size;
   int top;

    public:

    //constructor
    Stack(int size){
        this->size=size;
        arr= new int[size];
        top=-1;
    }


    //push function
    void push(int ele){
     if(top==size-1){
        cout<<"stack overflow";
     }
     else{
        top++;
        arr[top]=ele;
     }
    }

    //pop function 
    int pop(){
       int x=-1;
       if(top<0){
        cout<<"stack underflow";
       }
       else{
        x=arr[top];
        top--;
       }
       return x;
    }

    int peek(int pos){
        int x=-1;
        if(top-pos+1<0){
            cout<<"invalid position";
        }
        else{
            x=arr[top-pos+1];
        }
        return x;
    }

};

int main(){
  
    // s1.push(4);
    // s1.push(5);
    // s1.push(50);
    // s1.push(25);
    // cout<<s1.pop()<<endl;
    // cout<<s1.peek(2);
   
   

}