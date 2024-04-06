#include<iostream>
#include<vector>
using namespace std;
class node{
    public:
    int data;
    node* next;

    //constructor
    node(int data){
        this->data=data;
        this->next=nullptr;
    }

};

void insert(node* &head,int d){
    node* temp=new node(d);
    temp->next=head;
    head=temp;
}



//*************************************************************
// make a linked list from the array
/**
 * Constructs a linked list from a vector of integers.
 * 
 * @param arr A vector of integers to construct the linked list from.
 * @return A pointer to the head of the constructed linked list.
 */
Node* constructLL(vector<int>& arr) {
    // Check if the vector is empty
    if (arr.empty()) {
        return nullptr; // Return nullptr if the vector is empty
    }

    // Create the first node of the linked list
    Node* tail = new Node(arr[0]); // Create a new node with the first element
    Node* head = tail; // Set the head to the first node

    // Iterate through the vector to create the rest of the linked list
    for (int i = 1; i < arr.size(); i++) {
        // Create a new node for the current element
        Node* temp = new Node(arr[i]);
        // Link the current tail to the new node
        tail->next = temp;
        // Update the tail to the newly added node
        tail = temp;
    }

    // Return a pointer to the head of the constructed linked list
    return head;
}



//****************************************************************

/**
 * Inserts a new node with the given value at the beginning of the linked list.
 * 
 * @param list Reference to the pointer to the head of the linked list.
 * @param newValue The value to insert in the new node.
 */
void insertAtFirst(Node* &list, int newValue) {
    // Create a new node with the given value
    Node* temp = new Node(newValue);
    // Set the next of the new node to the current head of the linked list
    temp->next = list;
    // Update the head of the linked list to the new node
    list = temp;
}


//***************************************************************
/**
 * Deletes the last node of the singly-linked list.
 * 
 * @param list Pointer to the head of the singly-linked list.
 * @return Pointer to the head of the list after deletion.
 */
Node *deleteLast(Node *list) {
    // Check if the list is empty or contains only one node
    if (list == nullptr || list->next == nullptr) {
        delete list; // Delete the node
        return nullptr; // Return nullptr since the list is now empty
    }

    Node *prev = nullptr;
    Node *curr = list;

    // Traverse the list to find the last node
    while (curr->next != nullptr) {
        prev = curr;
        curr = curr->next;
    }

    // Set the next of the second-to-last node to nullptr
    prev->next = nullptr;

    // Delete the last node
    delete curr;

    // Return the head of the list
    return list;
}



//****************************************************************
/**
 * Calculates the length of the singly-linked list.
 * 
 * @param head Pointer to the head of the singly-linked list.
 * @return Length of the list.
 */
int length(Node *head) {
    // Initialize count to 0
    int count = 0;

    // Traverse the list and count nodes
    while (head != nullptr) {
        count++;
        head = head->next;
    }

    // Return the count
    return count;
}


//**************************************************************
/**
 * Searches for a given integer in a linked list.
 * 
 * @param head Pointer to the head of the linked list.
 * @param k Integer to search for.
 * @return 1 if the integer is found, 0 otherwise.
 */
int searchInLinkedList(Node<int> *head, int k) {
    // Check if the list is empty
    if (head == nullptr) {
        return 0;
    }

    // Traverse the list and search for the integer
    while (head != nullptr) {
        if (head->data == k) {
            return 1; // Return 1 if the integer is found
        }
        head = head->next;
    }

    // Return 0 if the integer is not found
    return 0;
}



                                                                //doubly linked list

//***************************************************************
/**
 * Constructs a doubly-linked list from a vector of integers.
 * 
 * @param arr Vector of integers to construct the doubly-linked list from.
 * @return Pointer to the head of the constructed doubly-linked list.
 */
Node* constructDLL(vector<int>& arr) {
    // Check if the vector is empty
    if (arr.empty()) {
        return nullptr;
    }

    // Initialize head and tail to the first node
    Node* head = new Node(arr[0]);
    Node* tail = head;

    // Iterate through the vector to construct the doubly-linked list
    for (int i = 1; i < arr.size(); i++) {
        // Create a new node with the current element
        Node* temp = new Node(arr[i]);
        // Link the current tail to the new node
        tail->next = temp;
        // Set the previous pointer of the new node to the current tail
        temp->prev = tail;
        // Update the tail to the newly added node
        tail = temp;
    }

    // Return the head of the constructed doubly-linked list
    return head;
}


//*****************************************************************
/**
 * Inserts a new node with the given value at the tail of the doubly linked list.
 * 
 * @param head Pointer to the head of the doubly linked list.
 * @param k Value to insert.
 * @return Pointer to the head of the doubly linked list after insertion.
 */
Node* insertAtTail(Node* head, int k) {
    // Create a new node with the given value
    Node* newNode = new Node(k);

    // If the list is empty, set the new node as the head and return
    if (head == nullptr) {
        return newNode;
    }

    // Traverse the list to find the last node
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    // Link the last node to the new node
    temp->next = newNode;
    newNode->prev = temp;

    // Return the head of the list
    return head;
}


//*********************************************************************
/**
 * Deletes the last node of the doubly linked list.
 * 
 * @param head Pointer to the head of the doubly linked list.
 * @return Pointer to the head of the doubly linked list after deletion.
 */
Node* deleteLastNode(Node* head) {
    // If the list is empty or contains only one node, return nullptr
    if (head == nullptr || head->next == nullptr) {
        delete head; // Delete the single node or nullptr
        return nullptr; // Return nullptr since the list is now empty
    }

    // Traverse the list to find the second-to-last node
    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    // Delete the last node
    delete temp->next;
    // Set the next pointer of the second-to-last node to nullptr
    temp->next = nullptr;

    // Return the head of the list
    return head;
}



//**********************************************************************

#include<vector>
#include<stack>

//naive solution using stack
/**
 * Reverses the elements of a doubly linked list.
 * 
 * @param head Pointer to the head of the doubly linked list.
 * @return Pointer to the head of the reversed doubly linked list.
 */
Node* reverseDLL(Node* head) {   
    stack<int> st;
    Node* temp=head;
  
    // Push the data of each node onto a stack
    while(temp!=nullptr){
        st.push(temp->data);
        temp=temp->next;
    }

    temp=head;
    // Pop elements from the stack and update the data of each node
    while(temp!=nullptr){
        temp->data=st.top();
        st.pop();
        temp=temp->next;
    }

    return head;
}


//optimal solution using two pointers

#include<vector>
#include<stack>

/**
 * Reverses the doubly linked list in place.
 * 
 * @param head Pointer to the head of the doubly linked list.
 * @return Pointer to the head of the reversed doubly linked list.
 */
Node* reverseDLL(Node* head) {   
    Node* curr=nullptr;
    Node* prev=nullptr;

    // Traverse the list and reverse the pointers
    while(head!=nullptr){
        prev=curr;
        curr=head;
        head=head->next;
        curr->next=prev;
    }
    // Update the head to point to the last node, which is now the first node in the reversed list
    head=curr;

    return head;
}


//*************************************************************

/**
 * Finds the middle node of a singly linked list.
 * 
 * @param head Pointer to the head of the singly linked list.
 * @return Pointer to the middle node of the list.
 */
Node* findMiddle(Node* head) {
    // Initialize slow and fast pointers to the head
    Node* slow = head;
    Node* fast = head;

    // Traverse the list until the fast pointer reaches the end
    // (or null if the list has odd length, or the last valid node if the list has even length)
    while (fast->next != nullptr && fast != nullptr) {
        // Move slow pointer one step forward
        slow = slow->next;
        // Move fast pointer either one or two steps forward
        if (fast->next->next != nullptr) {
            fast = fast->next->next;
        } else {
            fast = fast->next;
        }
    }

    // At this point, the slow pointer will be at the middle node
    return slow;
}


//*********************************************************************
/**
 * Reverses a singly linked list in place using an iterative approach.
 * 
 * @param head Pointer to the head of the singly linked list.
 * @return Pointer to the head of the reversed singly linked list.
 */
Node* reverseLinkedList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;

    while (curr != nullptr) {
        // Store the next node
        Node* nextNode = curr->next;
        // Reverse the link for the current node
        curr->next = prev;
        // Move prev and curr pointers one step forward
        prev = curr;
        curr = nextNode;
    }

    // At the end, 'prev' will be pointing to the new head of the reversed list
    return prev;
}


//******************************************************************

/**********************************************************************
 * Function: reverseLinkedList
 * ---------------------------
 * Reverses a singly linked list iteratively.
 *
 * Parameters:
 *     head: Pointer to the head of the linked list.
 *
 * Returns:
 *     Pointer to the head of the reversed linked list.
 **********************************************************************/
Node* reverseLinkedList(Node *head) {
    // Initialize pointers to track current, previous, and next nodes
    Node *current = head;
    Node *prev = nullptr;
    Node *next = nullptr;

    // Iterate through the linked list, reversing pointers
    while (current != nullptr) {
        // Store the next node to avoid losing its reference
        next = current->next;
        // Reverse the current node's pointer to point to the previous node
        current->next = prev;
        // Move pointers one position ahead
        prev = current;
        current = next;
    }

    // Update the head to point to the last node, which is now the first node in the reversed list
    head = prev;

    return head;
}


//*********************************************************************

int main(){
    vector<int> arr{1,2,3,4};
   node* head=constructLL(arr);



}