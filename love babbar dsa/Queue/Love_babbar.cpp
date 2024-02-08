#include<iostream>
using namespace std;
#include<stack>
class Queue{
    int size;
    int *arr;
    int rear;
    int front;

    public:
    Queue(){
        size=10000;
        arr=new int[size];
        front=0;
        rear=0;
    }

    void enqueue(int x){
        if(rear==size){
            cout<<"queue is full";
        }
        else{
            arr[rear]=x;
            rear++;
        }
    }

    int dequeue(){
        int ans=-1;
        if(front==rear){
            return -1;
        }
        else{
            ans=arr[front];
            front++;
            return ans;
        }
    }

    int frontele(){
        int x=-1;
        if(front==rear){
            return x;
        }
        else{
            x=arr[front];
        }
        return x;
    }
     bool Isempty(){
        if(front==rear || front>rear){
            return true;
        }
        else{
            return false;
        }
    }

    
    

};
int main(){
    Queue q1;
    q1.enqueue(12);
    q1.enqueue(15);
    q1.enqueue(20);
    int elee=q1.frontele();
    cout<<elee<<endl;
    // q1.reverse();
    int ele=q1.frontele();
    cout<<ele;



}