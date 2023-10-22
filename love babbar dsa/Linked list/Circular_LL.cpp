#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    //constructor
    node(int d){
        this->data=d;
        this->next=NULL;
    }

    //destructor
    ~node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            next=NULL;
        }
    cout<<"meemory is free for node with data:"<<value<<endl;
    }
};

void insert(node* &tail,int element,int d){

    //if empty
    if(tail==NULL){
        node* newnode=new node(d);
        tail=newnode;
        newnode->next=newnode;
    }

    //non-empty
    else{
        node* curr=tail;

        while(curr->data!=element){
            curr=curr->next;
        }

        //element is found curr is representing element wala node
        node* temp=new node(d);
        temp->next=curr->next;
        curr->next=temp;
    }
}


void display(node* tail){
     node* temp = tail;

    //empty list
    if(tail == NULL) {
        cout << "List is Empty "<< endl;
        return ;
    }

    do {
        cout << tail -> data << " ";
        tail = tail -> next;
    } while(tail != temp);

    cout << endl;
}


void deletenode(node* &tail,int value){

    //empty list
    if(tail==NULL){
        cout<<"list is empty."<<endl;
        return;
    }

    else{
        node* prev=tail;
        node* curr=prev->next;
        // int count=1;
        while(curr->data!=value){
            prev=curr;
            curr=curr->next;
        }

        prev->next=curr->next;
        //1 node LL
        if(curr==prev){
            tail=NULL;
        }
        //>=2 node LL
        if(tail==curr){
            tail=prev;
        }
        curr->next=NULL;
        delete curr;

    }
}
int main(){
    node* temp=NULL;
    display(temp);
    insert(temp,5,3);
    display(temp);
    // // insert(temp,3,5);
    // display(temp);
    // insert(temp,3,10);
    // display(temp);

    deletenode(temp,10);
    display(temp);
   
}