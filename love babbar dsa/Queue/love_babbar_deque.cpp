#include<iostream>
using namespace std;

class Deque{
    int *arr;
    int size=1000;
    int front=-1;
    int rear=-1;

    public:
    Deque(){
        arr=new int[size]; 
    }

    //pushfront function
    bool pushfront(int value){
        if(front==0 && rear==size-1){
            return false;
        }
        else if(front==-1 && rear==-1){
            front=rear=0;
        }
        else if(front==0 && rear!=size-1){
            front=size-1;
        }
        else{
            front--;
        }
        arr[front]=value;
        return true;
    }

    int popfront(){
        if(front==-1 && rear==-1){
            return -1;
        }
        int ans=arr[front];
        arr[front]=-1;
        if(front==rear){
            front=rear-1;
        }
        else if(front=size-1){
            front=0;
        }
        else{
            front++;
        }
        return ans;
    }
};
int main(){
    Deque q1;
    q1.pushfront(12);
    q1.pushfront(14);
    q1.pushfront(16);
    int ele=q1.popfront();
    cout<<ele;

}