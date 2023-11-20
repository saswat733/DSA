#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;

    //constructor
    node(int d){
        this->data=d;
        this->next=NULL;
        this->prev=NULL;
    }

    //desturctor
    ~node(){
        int x=this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"the memory is freed for:"<<x<<endl;
    }
};

void insertathead(int d,node* &head){
    node* temp=new node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;
}

void insert(node* &head,int d,int pos){
    if(pos==1){
        node* temp=new node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;

    }
    else{
         node* p=head;
    int count=0;
    while(count<pos-1){
        p=p->next;
        count++;
    }
    node* temp=new node(d);
    temp->next=p->next;
    temp->prev=p;
    if(p->next){
        p->next->prev=temp;
    }

    p->next=temp;
    }
}
void insertatanypos(node* &head,int d,int pos){
    node* p=head;
    int count=0;
    while(count<pos-1){
        p=p->next;
        count++;
    }
    node* temp=new node(d);
    temp->next=p->next;
    temp->prev=p;
    if(p->next){
        p->next->prev=temp;
    }

    p->next=temp;
}


//deleting
void removeFromhead(node* &head){
    node* temp=head;
    head=head->next;
    temp->next=NULL;
    delete temp;
    if(head){
        head->prev=NULL;
    }
}

void removeFromanyPoint(node* &head,int pos){
       node* curr=head;
        node* prev=NULL;
        int count=1;
        while(count<pos){
            prev=curr;
            curr=curr->next;
            count++;
        }

        curr->prev=NULL;
        prev->next=curr->next;
        if(curr->next){
            curr->next->prev=curr->prev;
        }
        curr->next=NULL;
        delete curr;
}
void display(node* head){
    if(head == NULL) {
        cout << "List is empty "<< endl;
        return ;
    }
    node* temp = head;

    while(temp != NULL ) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}
int main(){
    node* temp=new node(10);
    node* head=temp;
    display(head);
    insertathead(30,head);
    display(head);
    insertatanypos(head,50,2);
    insertatanypos(head,50,2);
    display(head);
    insert(head,67,3);
    insert(head,67,1);
    display(head);
    removeFromhead(head);
    display(head);
    removeFromanyPoint(head,5);
    display(head);
}