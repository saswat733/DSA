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


void reverse(node* head){
    if(head==NULL || head->next==NULL){
        cout<<head<<endl;
    }
        node* curr=head;
        node* prev=NULL;
        node* forward=NULL;
        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
    
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
void deleted(node* head,node* tail,int pos){
    
    if(pos==1){
        head=head->next;
        delete head;
    }else{
        node* prev=head;
        node* curr=NULL;
        for(int i=0;i<pos;i++){
            prev=curr;
            prev=prev->next;
        }
        if(prev){
            curr->next=prev->next;
            delete curr;
        }
    }
}
int main(){
    node* node1=new node(100);

    node* head=node1;
    node* tail=node1;
    
    insertedAtHead(head,90);
    insertedAtHead(head,80);
    insertedatanyPosition(head,85,0);
    insertedatLast(head,tail,120);
    insertedatLast(head,tail,130);
    insertinsorted(head,110);
    // print(head);
    deleted(head,tail,2);
    print(head);

}