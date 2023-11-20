#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* prev;
    node* next;

    //constructor
    node(int d){
        this->data=d;
        this->next=NULL;
        this->prev=NULL;
    }

    //destructor
    ~node(){
        int value=this->data;

        //freeing memory
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"memory is free for node with data: "<<value<<endl;
    }
};
//displaying the LL
void display(node* temp){
    node* head=temp;
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
   
    cout<<endl;
}
//getting the length of LL
int length(node* head){
    int len=0;
    node*temp=head;
    while (temp!=NULL)
    {
        len++;
        temp=temp->next;
    }
    return len;
}

//inserting data at head
void insertnodeatHead(node* &tail,node* &head,int d){
    if(head==NULL){
        node* temp=new node(d);
        head=temp;
        tail=temp;
    }
    else{
    node* temp=new node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;
    }
}

//inserting data at tail
void insertnodeatTail(node* &head,node* &tail,int d){
    if(tail==NULL){
        node* temp=new node(d);
        tail=temp;
        head=temp;
    }
    else{
    node* temp=new node(d);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
    }
}

//inserting data at middle
void insertatanyPosition(node* &head,node* &tail,int d,int pos){
    //insert at Start
    if(pos == 1) {
        insertnodeatHead(tail,head, d);
        return;
    }

    node* temp  = head;
    int cnt = 1;

    while(cnt < pos-1) {
        temp = temp->next;
        cnt++;
    }

    //inserting at Last Position
    if(temp -> next == NULL) {
        insertnodeatTail(tail,head,d);
        return ;
    }

    //creating a node for d
    node* nodeToInsert = new node(d);

    nodeToInsert ->next = temp -> next;
    temp -> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;

}
void deleteNode(int position,node* &head){
    //deleting first or start node
    if(position==1){
        node* temp=head;
        
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }

    else{
        //deleting any middle ele or last one

        node* curr=head;
        node* prev=NULL;
        int count=1;
        while(count<position){
            prev=curr;
            curr=curr->next;
            count++;
        }

        curr->prev=NULL;
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}

                                        //Reversing the Linked List
void ReverseLL(node* &head){
    node* p=head;
    node* q=NULL;
    node* r=NULL;
    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    head=q;
}

void ReverseLL2(node* &head){           //using array
    node* p=head;
    int i=0;
    int a[10];
    while(p!=NULL){
        a[i]=p->data;
        p=p->next;
        i++;
    }
    p=head;
    i--;
    while(p!=NULL){
        p->data=a[i--];
        p=p->next;
    }

}

void ReverseLLR(node* &head,node* tail){
    node* p=head;
    node* q=NULL;
    if(p!=NULL){
        ReverseLLR(p,p->next);
        p->next=q;

    }
    else{
        head=q;
    }

}

node* reverse_DLL(node* &head) {
    node* curr = head;
    node* forward;

    while (curr != NULL) {
        forward = curr->next;
        curr->next = curr->prev;
        curr->prev = forward;
        curr = forward;
    }

    // At the end of the loop, curr will be NULL, so return the last non-NULL node's prev
    return head->prev;
}

int main(){
    node* node1=new node(10);
    node* head=node1;
    node* tail=node1;

    insertnodeatHead(tail,head,20);
    // display(head);
    // cout<<"head "<<head->data<<endl;
    // cout<<"tail "<<tail->data<<endl;
cout<<endl;
    // insertnodeatHead(tail,head,30);
    // display(head);
    // cout<<"head "<<head->data<<endl;
    // cout<<"tail "<<tail->data<<endl;
cout<<endl;
    // insertnodeatTail(head,tail,40);
    display(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
cout<<endl;
    insertnodeatTail(head,tail,50);
    display(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
    cout<<length(tail)<<endl;
    cout<<length(head)<<endl;
cout<<endl;

    insertatanyPosition(head,tail,100,2);
    display(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
cout<<endl;
cout<<length(tail)<<endl;
    cout<<length(head)<<endl;

    insertatanyPosition(head,tail,101,3);
    display(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
    cout<<length(tail)<<endl;
    cout<<length(head)<<endl;

    // deleteNode(7,head);
    display(head);
    // ReverseLL(head);
    // ReverseLL2(head);
    // ReverseLLR(head,head);
    head=reverse_DLL(head);
    display(head);
}