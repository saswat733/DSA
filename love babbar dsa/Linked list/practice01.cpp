// #include<iostream>
// using namespace std;

// class node{
//     public:
//     int data;
//     node* next;

//     //constructor
//     node(int d){
//         this->data=d;
//         this->next=NULL;
//     }

//     //destructor
//     ~node(){
//         int value=this->data;
//         if(this->next!=NULL){
//             delete next;
//             next=NULL;
//         }
//         cout<<"memory is free for:"<<value<<endl;

//     }
// };

// void insertathead(node* &head,int d){
//     node* temp=new node(d);
//     temp->next=head;
//     head=temp;
// }
// void insertatanyposition(node* &head,int d,int pos){
//     node* p=head;
//     for(int i=0;i<pos-1;i++){
//         p=p->next;
//     }
//     node* temp=new node(d);
//     temp->next=p->next;
//     p->next=temp;
//     temp=p;
// }
// int count(node* head){
//     int c=0;
//     while (head!=NULL)
//     {
//         c++;
//         head=head->next;
//     }
//     return c;
    
// }
// //sum of all the node
// int sum(node* head){
//     int sum=0;
//     while(head!=NULL){
//         sum=sum+head->data;
//         head=head->next;
//     }
//     return sum;
// }

// int max(node* head){
//     node* temp=head;
//     int max=INT_MIN;
//     while(temp!=NULL){
//         if(temp->data>max){
//             max=temp->data;
//         }
//         temp=temp->next;
//     }
//     return max;
// }

// node* search(node* temp,int d){
//     while(temp!=NULL){
//         if(temp->data==d){
//             return temp;
//         }
//         temp=temp->next;
//     }
//     return NULL;
// }

// void deletingathead(node* &head){
//     node* temp=head;
//     head=head->next;
//     temp->next=NULL;
//     delete temp;
// }
// void deleteatanyposition(node* &head,int pos){
//     node* curr=head;
//     node* prev=NULL;
//     int count=1;
//     while(count<pos){
//         prev=curr;
//         count++;
//         curr=curr->next;
//     }
//     prev->next=curr->next;
//     curr->next=NULL;
//     delete curr;
// }

// bool sorted(node* head){
//     int x=INT_MIN;
//     while(head!=NULL){
//         if(x>head->data){
//             return false;
//         }
//         x=head->data;
//         head=head->next;
//     }
//     return true;
// }

// void removeDuplicates(node* &head){
//     node* p=head;
//     node* q=head->next;
//     while(q!=NULL){
//         if(p->data!=q->data){
//             p=q;
//             q=q->next;
//         }
//         else{
//             p->next=q->next;
//             q->next=NULL;
//             delete q;
//             q=p->next;
//         }
//     }
// }

// void display(node* temp){
//     while(temp!=NULL){
//         cout<<temp->data<<" ";
//         temp=temp->next;
//     }
//     cout<<endl;
// }
// void reverseLL(node* head){
//      if(head==NULL || head->next==NULL){
//         cout<<head<<endl;
//     }
//         node* curr=head;
//         node* prev=NULL;
//         node* forward=NULL;
//         while(curr!=NULL){
//             forward=curr->next;
//             curr->next=prev;
//             prev=curr;
//             curr=forward;
    
//     }

// }

// int main(){
//     node* temp=new node(150);
//     node* head=temp;
//     // display(head);
//     insertathead(head,5);
//     // display(head);
//     insertatanyposition(head,7,1);
//     insertatanyposition(head,7,1);
//     // display(head);
//     insertatanyposition(head,10,1);
//     insertatanyposition(head,10,1);
//     display(head);
//     // cout<<count(head)<<endl;
//     // cout<<sum(head)<<endl;
//     // display(head);
//     // cout<<max(head)<<endl;
//     // cout<<search(head,10)<<endl;
//     // cout<<sorted(head)<<endl;
//     // removeDuplicates(head);
//     reverseLL(head);
//     display(head);
//     // deletingathead(head);
//     // display(head);
//     // deleteatanyposition(head,2);
//     // display(head);
// }



#include<iostream>
using namespace std;
struct node{
    int data;
    struct node* next;  
}*first;


//create a linked list
void create(int a[],int n){
    int i;
    struct node *t,*last;
    first=(struct node *)malloc(sizeof(struct node));
    first->data=a[0];
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++){
        t=(struct node*)malloc(sizeof (struct node));
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void insert(struct node* head,int d,int pos){
    struct node *t;
    int i;
    t=(struct node *)malloc(sizeof(struct node));
    t->data=d;
    if(pos==0){
        t->next=first;
        first=t;
    }
    else{
        for(i=0;i<pos-1;i++){
            head=head->next;
        }
        t->next=head->next;
        head->next=t;
    }
}

void display(struct node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
int main(){
    int a[]={3,5,7,9,10};
    create(a,5);
    insert(first,30,2);
    insert(first,40,1);
    insert(first,50,0);
    // insert(t,40,1);
    display(first);
}