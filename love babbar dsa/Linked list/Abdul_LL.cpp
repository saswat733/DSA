#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
class node
{
public:
    int data;
    node *next;

    // constructor
    node(int d)
    {
        this->next = NULL;
        this->data = d;
    }

    // destructor
    ~node()
    {
        int value = this->data;

        // freeing memory
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "memory is free for node with data: " << value << endl;
    }
};

void insertathead(int d, node *&head)
{
    node *temp = new node(d);
    temp->next = head;
    head = temp;
}

void insertattail(int d, node *&tail)
{
    node *temp = new node(d);
    tail->next = temp;
    tail = temp;
}

void insertatmiddle(int d, node *&head, node *&tail, int position)
{

    if (position == 1)
    {
        insertathead(d, head);
        return;
    }

    node *temp = head;
    int count = 1;

    while (count < position - 1)
    {
        count++;
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        insertattail(d, tail);
        return;
    }

    node *curr = new node(d);
    curr->next = temp->next;
    temp->next = curr;
}
void display(node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty " << endl;
        return;
    }
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// printing
void print(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// recursive printing
void printRD(node *head)
{
    if (head != NULL)
    {
        cout << head->data << " ";
        printRD(head->next);
    }
    cout << endl;
}

int count(node *head)
{
    int c = 0;
    while (head != NULL)
    {
        c++;
        head = head->next;
    }
    return c;
}

// recursive function
int countRD(node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        return countRD(head->next) + 1;
    }
}

// sum of all the node
int sum(node *head)
{
    int sum = 0;
    while (head != NULL)
    {
        sum = sum + head->data;
        head = head->next;
    }
    return sum;
}

// recursive function for sum
int sumRD(node *head)
{
    int sum = 0;
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        return sumRD(head->next) + head->data;
    }
}
void deletenode(int position, node *&head)
{
    if (position == 1)
    {
        node *temp = head;
        head = head->next;
        // memory free krdo
        temp->next = NULL;
        delete temp;
    }
    else
    {
        node *curr = head;
        node *prev = NULL;

        int count = 1;
        while (count < position)
        {
            prev = curr;
            count++;
            curr = curr->next;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

// function to get max node
int maxele(node *head)
{
    int max = INT_MIN;
    while (head != NULL)
    {
        if (head->data > max)
        {
            max = head->data;
        }
        head = head->next;
    }
    return max;
}

// recursive function
int maxeleRD(node *head)
{
    int x = 0;
    if (head == NULL)
    {
        return INT_MIN;
    }
    else
    {
        x = maxeleRD(head->next);
        if (x > head->data)
        {
            return x;
        }
        else
        {
            return head->data;
        }
    }
}

// program for searhing in LL
node *search(node *head, int key)
{
    while (head != NULL)
    {
        if (head->data == key)
        {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// inserting in a LL
void insertedAtHead(node *&head, int d)
{
    node *temp = new node(d);
    temp->next = head;
    head = temp;
}

void insertedatanyPosition(node *&head, int d, int position)
{
    node *first = head;
    for (int i = 0; i < position; i++)
    {
        first = first->next;
    }

    node *temp = new node(d);
    temp->next = first->next;
    first->next = temp;
}

void insertedatLast(node *&head, node *&tail, int d)
{
    node *temp = new node(d);
    if (head == NULL)
    {
        head = tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

// inserting in a sorted LL

void insertinsorted(node *&head, int d)
{
    node *temp = head;
    node *q = NULL;
    while (temp != NULL && temp->data < d)
    {
        q = temp;
        temp = temp->next;
    }

    node *ele = new node(d);
    ele->next = q->next;
    q->next = ele;
}

// Delete function
void deletedAtHead(node *&head)
{
    node *temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
}

void deletedAtAnyPosition(node *&head, int pos)
{
    node *p = head;
    node *q = NULL;
    for (int i = 0; i < pos - 1; i++)
    {
        q = p;
        p = p->next;
    }
    q->next = p->next;
    p->next = NULL;
    delete p;
}

void deleteBoth(node *&head, int pos)
{
    if (pos == 0)
    {
        node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        node *curr = head;
        node *prev = NULL;

        for (int i = 0; i < pos - 1; i++)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

// removing duplicates
void RemoveDuplicates(node *&head)
{
    node *p = head;
    node *q = head->next;
    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}
bool sortedornot(node *&head)
{
    int x = -32768;
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data < x)
        {
            return false;
        }
        x = temp->data;
        temp = temp->next;
    }
    return true;
}

bool isLoop(node *&head)
{
    node *p;
    node *q;
    p = q = head;
    do
    {
        p = p->next;
        q = q->next;
        q = q != NULL ? q->next : NULL;
    } while (p && q);
    {
        return p == q ? true : false;
    }
}

void reverse(node *&head)
{
    node *forward = head;
    node *prev = NULL;
    node *curr = NULL;

    while (forward != NULL)
    {
        prev = curr;
        curr = forward;
        forward = forward->next;
        curr->next = prev;
    }
    head = curr;
}

// node* reverseDLL(node* head) {

//     if(head == NULL || head -> next == NULL) {

//         return head;

//     }

//     node* newHead = reverseDLL(head -> next);

//     head->next->next=head;

//     head->prev=head->next;

//     head->next=NULL;

//     return newHead;

// }

bool isLooop(node *&head)
{
    if (head == NULL)
    {
        return false;
    }
    map<node *, bool> visited;
    node *temp = head;
    while (temp != NULL)
    {
        if (visited[temp] == true)
        {
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

bool floydLoop(node *&head)
{
    if (head == NULL)
    {
        return false;
    }

    node *p = head;
    node *q = head;

    while (q != NULL && q->next != NULL)
    {
        p = p->next;
        q = q->next->next;

        if (p == q)
        {
            return true;
        }
    }
    return false;
}

node *floydLoopHead(node *&head)
{
    // if(head==NULL){
    //     return false;
    // }
    // initialize both the pointer to the head
    node *p = head;
    node *q = head;

    // traverse the LL to find the meeting point
    while (q != NULL && q->next != NULL)
    {
        p = p->next;
        q = q->next->next;
        // if both the points meet thier is a cycle
        if (p == q)
        {
            q = head;
            // move both the pointers again until once again meet
            while (p != q)
            {
                p = p->next;
                q = q->next;
            }
            // return the start of the cycle
        }
        return q;
    }
    return NULL;
}

void floydLoopHeadRemove(node *head)
{
    node *startOfloop = floydLoopHead(head);
    node *temp = startOfloop;
    while (temp->next != startOfloop)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}

node *RemoveDuplicatees(node *&head)
{
    if (head == NULL)
    {
        return NULL;
    }

    node *current = head;

    while (current != NULL)
    {
        // Check for consecutive duplicates
        while (current->next != NULL && current->data == current->next->data)
        {
            node *next_node = current->next->next;
            delete current->next;
            current->next = next_node;
        }

        current = current->next; // Move to the next node
    }

    return head; // Updated head if needed
}

node *sort_LL(node *&head)
{
    node *temp = head;
    node *newnode = head;
    int zeros = 0;
    int ones = 0;
    int twos = 0;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zeros++;
        }
        if (temp->data == 1)
        {
            ones++;
        }
        if (temp->data == 2)
        {
            twos++;
        }
        temp = temp->next;
    }
    while (zeros > 0)
    {
        zeros--;
        newnode->data = 0;
        newnode = newnode->next;
    }
    while (ones > 0)
    {
        ones--;
        newnode->data = 1;
        newnode = newnode->next;
    }
    while (twos > 0)
    {
        twos--;
        newnode->data = 2;
        newnode = newnode->next;
    }

    return head;
}

node *sorting_LL(node *&head)
{
    // creating the dummy nodes
    node *zeroHead = new node(-1);
    node *oneHead = new node(-1);
    node *twoHead = new node(-1);

    // creating tail pointers to keep track of these nodes
    node *zeroTail = zeroHead;
    node *oneTail = oneHead;
    node *twoTail = twoHead;

    // pointer to traverse the original list
    node *curr = head;

    while (curr)
    {
        if (curr->data == 0)
        {
            zeroTail->next = curr;
            zeroTail = curr;
        }
        else if (curr->data == 1)
        {
            oneTail->next = curr;
            oneTail = curr;
        }
        else
        {
            twoTail->next = curr;
            twoTail = curr;
        }
        curr = curr->next;
    }

    // connect the threee lists
    zeroTail->next = oneHead->next ? oneHead->next : twoHead->next;
    oneTail->next = twoHead->next;

    // set the head of the sorted lists
    node *sortedHead = zeroHead->next;

    // delete the dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    // return the head of the sorted lists
    return sortedHead;
}

node *merge_sorted_LL(node *&head1, node *head2)
{
    node *temp1 = head1;
    node *temp2 = head2;

    // Initialize main pointer
    node *main = new node(-1);
    node *current = main;

    while (temp1 != nullptr && temp2 != nullptr)
    {
        if (temp1->data < temp2->data)
        {
            current->next = temp1;
            temp1 = temp1->next;
        }
        else
        {
            current->next = temp2;
            temp2 = temp2->next;
        }
        // Move the current pointer to the newly added node
        current = current->next;
    }

    // Check for remaining nodes in either list
    while (temp1 != nullptr)
    {
        current->next = temp1;
        temp1 = temp1->next;
        current = current->next;
    }

    while (temp2 != nullptr)
    {
        current->next = temp2;
        temp2 = temp2->next;
        current = current->next;
    }

    // Update head1 to point to the merged list
    head1 = main->next;

    // Delete the dummy node
    delete main;

    return head1;
}
bool checkPalindrome(node *&head1)
{
    node *temp = head1;
    vector<int> a;

    // Populate the vector
    while (temp != NULL)
    {
        a.push_back(temp->data);
        temp = temp->next;
    }

    int start = 0;
    int end = a.size() - 1; // Initialize end with the last index of the vector

    while (start < end)
    {
        if (a[start] != a[end])
        {
            return 0; // Not a palindrome
        }
        else
        {
            start++;
            end--;
        }
    }

    return 1; // It's a palindrome
}
int main()
{
    node *head1 = new node(1);
    head1->next = new node(3);
    head1->next->next = new node(2);

    node *head2 = new node(2);
    head2->next = new node(4);
    head2->next->next = new node(6);

    // Print the original linked lists
    // std::cout << "Original Linked List 1: ";
    // print(head1);

    // std::cout << "Original Linked List 2: ";
    // print(head2);

    // Merge the two sorted linked lists
    // merge_sorted_LL(head1, head2);

    // Print the merged linked list
    // std::cout << "Merged Linked List: ";
    // print(head1);

    // Clean up memory (delete nodes)
    // ... (implement deletion as needed)

    if (checkPalindrome(head1))
    {
        cout << "yes palindrome";
    }
    else
    {
        cout << "no";
    }
}