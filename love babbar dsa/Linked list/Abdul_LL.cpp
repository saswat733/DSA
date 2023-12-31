#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class node{
  public:
  int data;
  node* next;

  //constructor
  node(int d){
    this->next=NULL;
    this->data=d;
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

void insertathead(int d,node* &head){
    node* temp=new node(d);
    temp->next=head;
    head=temp;
}

void insertattail(int d,node* &tail){
    node* temp=new node(d);
    tail->next=temp;
    tail=temp;
}

void insertatmiddle(int d,node* &head,node* &tail,int position){

    if(position==1){
        insertathead(d,head);
        return;
    }

    node* temp=head;
    int count=1;

    while(count<position-1){
        count++;
        temp=temp->next;
    }

    if(temp->next==NULL){
        insertattail(d,tail);
        return;
    }

    node* curr=new node(d);
    curr->next=temp->next;
    temp->next=curr;


}
void display(node* &head){
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

//printing
void print(node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

//recursive printing
void printRD(node* head){
    if(head!=NULL){
        cout<<head->data<<" ";
        printRD(head->next);
    }
    cout<<endl;
}


int count(node* head){
    int c=0;
    while(head!=NULL){
        c++;
        head=head->next;
    }
    return c;
}


//recursive function
int countRD(node* head){
    if(head==NULL){
        return 0;
    }
    else{
        return countRD(head->next)+1;

    }
}

//sum of all the node
int sum(node* head){
    int sum=0;
    while(head!=NULL){
        sum=sum+head->data;
        head=head->next;
    }
    return sum;
}

//recursive function for sum
int sumRD(node* head){
    int sum=0;
    if(head==NULL){
        return 0;
    }
    else{
        return sumRD(head->next)+head->data;
    }
}
void deletenode(int position,node* &head){
    if(position==1){
        node* temp=head;
        head=head->next;
        //memory free krdo
        temp->next=NULL;
        delete temp;
        
    }
    else{
        node* curr=head;
        node* prev=NULL;

        int count=1;
        while(count<position){
            prev=curr;
            count++;
            curr=curr->next;
        }

        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}




                                    //function to get max node
int maxele(node * head){
    int max=INT_MIN;
    while(head!=NULL){
        if(head->data>max){
            max=head->data;
        }
        head=head->next;
    }
    return max;
}

//recursive function
int maxeleRD(node* head){
    int x=0;
    if(head==NULL){
        return INT_MIN;
    }
    else{
        x=maxeleRD(head->next);
        if(x>head->data){
            return x;
        }
        else{
            return head->data;
        }

    }
}


                                    //program for searhing in LL
node* search(node* head,int key){
    while(head!=NULL){
        if(head->data==key){
            return head;
        }
        head=head->next;
    }
    return NULL;
}


                                        //inserting in a LL
void insertedAtHead(node* &head,int d){
    node* temp=new node(d);
    temp->next=head;
    head=temp;
}

void insertedatanyPosition(node* &head,int d,int position){
    node* first=head;
    for(int i=0;i<position;i++){
        first=first->next;
    }

    node* temp=new node(d);
    temp->next=first->next;
    first->next=temp;
}

void insertedatLast(node* &head,node* &tail,int d){
    node* temp = new node(d);
    if(head==NULL){
        head=tail=temp;
    }
    else{
        tail->next=temp;
        tail=temp;
    }

}

                                    //inserting in a sorted LL

void insertinsorted(node* &head,int d){
    node* temp=head;
    node* q=NULL;
    while(temp!=NULL && temp->data<d){
        q=temp;
        temp=temp->next;
    }

    node* ele=new node(d);
    ele->next=q->next;
    q->next=ele;
    }


                                    //Delete function
void deletedAtHead(node* &head){
    node* temp=head;
    head=head->next;
    temp->next=NULL;
    delete temp;
}

void deletedAtAnyPosition(node* &head,int pos){
    node* p=head;
    node* q=NULL;
    for(int i=0;i<pos-1;i++){
        q=p;
        p=p->next;
    }
    q->next=p->next;
    p->next=NULL;
    delete p;
}

void deleteBoth(node* &head,int pos){
    if(pos==0){
        node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        node* curr=head;
        node* prev=NULL;

        for(int i=0;i<pos-1;i++){
            prev=curr;
            curr=curr->next;
        }

        prev->next=curr->next;
        curr->next=NULL;
        delete curr;

    }
}

                                    //removing duplicates
void RemoveDuplicates(node* &head){
    node* p=head;
    node* q=head->next;
    while(q!=NULL){
        if(p->data!=q->data){
            p=q;
            q=q->next;
        }
        else{
            p->next=q->next;
            delete q;
            q=p->next;
        }
    }
}
bool sortedornot(node* &head){
    int x=-32768;
    node* temp=head;
    while(temp!=NULL){
        if(temp->data<x){
            return false;
        }
        x=temp->data;
        temp=temp->next;
       

    }
     return true;
}

bool isLoop(node* &head){
    node* p;
    node* q;
    p=q=head;
    do{
        p=p->next;
        q=q->next;
        q=q!=NULL?q->next:NULL;
    }while(p && q);{
        return p==q?true:false;
    }
    
}


void reverse(node* &head){
    node* forward=head;
    node* prev=NULL;
    node* curr=NULL;

    while(forward!=NULL){
        prev=curr;
        curr=forward;
        forward=forward->next;
        curr->next=prev;
    }
    head=curr;
}

node* reverseDLL(node* head) {

    if(head == NULL || head -> next == NULL) {

        return head;

    }



    node* newHead = reverseDLL(head -> next);

    head->next->next=head;

    head->prev=head->next;

    head->next=NULL;



    return newHead;

}
int main(){
    node* node1=new node(100);

    node* head=node1;
    node* tail=node1;
    
    insertedAtHead(head,90);
    insertedAtHead(head,85);
    insertedatanyPosition(head,85,0);
    insertedatLast(head,tail,120);
    insertedatLast(head,tail,110);
    insertinsorted(head,110);
    // print(head);
    // deletedAtHead(head);

    // deleteBoth(head,3);

    // deletedAtAnyPosition(head,4);
    // print(head);
    print(head);
//    cout<< sortedornot(head);

    // RemoveDuplicates(head);
    // cout<<isLoop(head)<<endl;
    reverse(head);
    print(head);
    reverseDLL(head);
    print(head);

}