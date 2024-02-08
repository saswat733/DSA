#include <iostream>
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

void print(node* head){
    do{
        cout<<head->data<<" ";
        head=head->next;
    }while(head!=NULL);
    cout<<endl;
}

void insert(node* &head,int d){
    //inserting at head
    
    node* temp=new node(d);
    temp->next=head;
    head=temp;

}
void insertAtTail(node* &tail,int d){
   node* temp=new node(d);
    tail->next=temp;
    tail=temp;
}

void insertAtMiddle(node* &head,node* &tail,int d,int pos){

    if(pos==0){
        insert(head,d);
        return;
    }
    node* temp=head;
    int i=0;
    while(i<pos-1){
        temp=temp->next;
        i++;
    }
    if(temp->next==NULL){
        insertAtTail(tail,d);
        return;
    }

    node* newLink=new node(d);
    newLink->next=temp->next;
    temp->next=newLink;
}

int count_LL(node* &head){
    int count=0;
    while(head!=NULL){
        head=head->next;
        count++;
    }
    return count;
}

int sum_LL(node* head){
    int sum=0;
    while(head!=NULL){
        sum=sum+head->data;
        head=head->next;
    }
    return sum;
}


void delete_LL(node* &head,int pos){
    if(pos==0){
        node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        node* curr=head;
        node* prev=NULL;
        
        int count=0;
        while(count<pos){
            prev=curr;
            count++;
            curr=curr->next;
        }

        prev->next=curr->next;
        curr->next=NULL;
        delete curr;

    }
}

int max_LL(node* head){
    int max=INT_MIN;
    while(head!=NULL){

        if(head->data>max){
            max=head->data;
        }
        head=head->next;

    }
    return max;
}

int search(node* head,int num){
    node* temp=head;
    while(temp!=NULL){
        if(temp->data==num){
            return true;
        }
        temp=temp->next;
    }
    return false;
}

void removeDuplicates(node* &head){
    node* temp=head;
    node* num=head->next;

    while(num!=NULL){
        if(temp->data!=num->data){
            temp=num;
            num=num->next;
        }
        else{
            temp->next=num->next;
            num->next=NULL;
            delete num;
            num=temp->next;
        }
    }
}

int sortedornot(node* &head){
    int min=-32768;
    while(head!=NULL){
        if(head->data<min){
            return false;
        }
            min=head->data;
            head=head->next;
       
    }
    return true;
}
bool isloop(node* &head){
    node* p=head;
    node* q=head;
    do{
        p=p->next;
        q=q->next;
        q=(q!=NULL)?q->next:NULL;
    }while(p && q);
    return (p==q);
}

node* reverse_LL( node* &head){
    node* prev=NULL;
    node* curr=head;
    node* forward;

    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;

}
void Recursive_reverse(node* &head,node* curr, node* prev){
    if(curr==NULL){
        head = prev;
        return;
    }
    else{
        node* forward=curr->next;
        Recursive_reverse(head,forward,curr);
        curr->next=prev;

    }
}

node* recurseive_LL(node* &head){
    //base case
    if(head == NULL || head->next==NULL){
        return head;
    }
    node* chotahead=recurseive_LL(head->next);

    head->next->next=head;
    head->next=NULL;

    return chotahead;


}

node* middle_LL(node* &head){
    // if(head->next==NULL || head==NULL){
    //     return;
    // }
    int len=count_LL(head);
    int ans=(len/2);
    node* temp=head;
    int count=0;
    while(count<ans){
        temp=temp->next;
        count++;
    }
    return temp;
}
void middle_LinkedList(node* &head){
    node* slow=head;
    node* fast=head;
    while(slow!=NULL && fast!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<"the middle element is:"<<slow->data;
}

node* middle_reverse(node* &head,int k){
    if (head == NULL) {
        return NULL;
    }
    node* next = NULL;
    node* curr = head;
    node* prev = NULL;
    int i = 0;
    while (curr != NULL && i < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        i++;
    }

    if (next != NULL) {
        head->next = middle_reverse(next, k);
    }

    // Return the new head of the reversed list
    return prev;
}


int main() {
    // Initialize a linked list
    node* node1 = new node(10);
    node* head = node1;
    node* tail = node1;

    // Print the initial linked list
    print(head);

    // Insert nodes at the tail
    insertAtTail(tail, 20);
    insertAtTail(tail, 90);

    // Print the linked list after insertions
    print(head);

    // Insert nodes at the tail
    insertAtTail(tail, 30);
    insertAtTail(tail, 40);
    insertAtTail(tail, 490);
    insertAtTail(tail, 408);

    // Print the linked list after more insertions
    print(head);

    // Insert a node at the middle
    insertAtMiddle(head, tail, 50, 3);

    // Print the linked list after the middle insertion
    print(head);

    // Reverse the linked list recursively
    // node1 = recursive_LL(node1);

    // Print the reversed linked list
    print(node1);
    cout << endl;

    // Find and print the middle node
    // node* middleNode = middle_LL(head);

    // if (middleNode != nullptr) {
    //     std::cout << "The middle node data is: " << middleNode->data << std::endl;
    // } else {
    //     std::cout << "The linked list is empty." << std::endl;
    // }

    // middle_LinkedList(node1);
   node1=middle_reverse(node1,2);
    print(node1);

    return 0;
}
