#include<iostream>
using namespace std;

                    // program for defining stack

class Stack{
    int *arr;
    int size;
    int top;

    public:

    //constructor
    Stack(int size){
        this->size=size;
        arr=new int[size];
        top=-1;
    }

    // push function
    void push(int ele){
        if(top==size-1){
            cout<<"Stack Overflow";
        }
        else{
            top++;
            arr[top]=ele;
        }
    }

    //pop function
    int pop(){
        int x=-1;
        if(top==-1){
            cout<<"stack underflow";
        }
        else{
           x=arr[top];
           top--; 
        }
        return x;
    }

    //peek function
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
    Stack* s1=new Stack(5);
    s1->push(20);
    s1->push(30);
    s1->push(40);
    int ele=s1->peek(1);
    cout<<ele<<endl;
    s1->pop();
    int ele1=s1->peek(1);
    cout<<ele1;
}