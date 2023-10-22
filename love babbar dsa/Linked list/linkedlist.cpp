// #include<iostream>
// using namespace std;

// struct node{
//     int data;
//     struct node *next;
// }*first=NULL;

// void create(int a[],int n){
//     int i;
//     struct node *t,*last;
//     first = new node;
//     first->data=a[0];
//     first->next=NULL;
//     last=first;

//     for(i=0;i<n;i++){
//         t = new node;
//         t->data=a[i];
//         t->next=NULL;
//         last->next=t;
//         last=t;
//     }

// }

// void display(struct node *p){
//     while(p!=NULL){
//         cout<< p->data<<" ";
//         p=p->next;
//     }
// }
// int main(){
//     int a[]={3,5,7,10,15};

//     create(a,5);
//     display(first);

      
// }

                                //love babbar
#include<iostream>
using namespace std;


                        //creating a linked list
// class node{
//     public:
//     int data;
//     node* next;

//     //constructor
//     node(int data){
//         this->data=data;
//         this->next=NULL;
//     }
// };
// int main(){
//     node* node1=new node(10);
//     cout<<node1->data<<endl;
//     cout<<node1->next<<endl;

// }


// #include "iostream"
// using namespace std;
// class node{
//     public:
//     int data;
//     node *next;

//     //constructor
//     node(int d){
//         this->data=d;
//         this->next=NULL;
//     }
// };

// void insert(node* &head,int d){
//     node* temp=new node(d);
//     temp->next=head;
//     head=temp;
// }
// // void insert(node* &head,int d){
// //     node* temp=new node(10);

// // }
// void display(node* n1){
//     if(n1!=NULL){
//         cout<<n1->data<<" ";
//         display(n1->next);
//     }
// }
// int main(){
//     node* node1=new node(20);
//     insert(node1,34);
//     insert(node1,44);
//     display(node1);
  
// }





                                    //code for singly linked list
#include"iostream"
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

        //freeing memory
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"memory is free for node with data: "<<value<<endl;
    }
};

void insertAtHead(node* &head, int d) {

    // new node create
    node* temp = new node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail(node* &tail, int d) {
     // new node create
    node* temp = new node(d);
    tail -> next = temp;
    tail  = temp;
}

        //inserting at a position
void insertatPosition(node* &head,int position,int d){
    //insertingg at first position
    if(position==1){
        // InsertatHead(head,d);
    }


    //inserting at midle positiion
    node *temp=head;
    int count=1;

    //inseting at last psoition
    if(temp->next==NULL){
        // InsertatTail(head,d);
    }

    while(count<position){
        temp=temp->next;
        count++;
    }


    //creating a node to enter data
    node* nodetoenter=new node(d);
    nodetoenter->next=temp->next;
    temp->next=nodetoenter;


}


void deleteNode(int position,node* &head){
    //deleting first or start node
    if(position==1){
        node* temp=head;
        head=head->next;

        //memory free karo
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

        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
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
int main(){
    node* node1=new node(10);
    // insert(node1,20);
    // InsertatHead(node1,20);

    node* head = node1; 
    node* tail = node1;
    display(head);

    insertAtTail(tail, 12);

    display(head);
    
    insertAtTail(tail, 15);
    display(head);
    // insertatPosition(head,2,100);
}