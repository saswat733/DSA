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
        int x=this->data;
        while(this->next!=NULL){
            this->next=NULL;
            delete next;
        }
        cout<<"the memory is free for:"<<x<<endl;
    }


};

void insertnode(node* &tail,int ele,int d){
    if(tail==NULL){
        node* newnode=new node(d);
        tail=newnode;
        newnode->next=newnode;
    }
    else{
        node* curr=tail;
        while(curr->data != ele){
            curr=curr->next;
        }

        node* temp=new node(d);
        temp->next=curr->next;
        curr->next=temp;

    }
}

void deletenode(node* &tail,int pos){
    if(pos==1){
        node* temp=tail;
        while(temp->next!=tail){
            temp=temp->next;
        }
        temp->next=tail->next;
        delete tail;
        tail=temp->next;
    }
    else{

   node* curr=tail;
        node* prev=NULL;
        int count=1;
        while(count<pos){
            prev=curr;
            curr=curr->next;
            count++;
        }

        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    
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
int main(){
    node* temp=NULL;
    
    node* tail=temp;
    display(tail);
    insertnode(tail,2,45);
    insertnode(tail,45,5);
    display(tail);

    insertnode(tail,5,50);
    insertnode(tail,50,90);
    insertnode(tail,90,500);
    display(tail);
    deletenode(tail,1);
    display(tail);
    deletenode(tail,2);
    display(tail);

}