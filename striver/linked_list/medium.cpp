/**********************************************************************
 * Function: detectCycle
 * ---------------------
 * Determines whether a linked list contains a cycle using Floyd's
 * Cycle Detection Algorithm.
 *
 * Parameters:
 *     head: Pointer to the head of the linked list.
 *
 * Returns:
 *     true if the linked list contains a cycle, false otherwise.
 **********************************************************************/
bool detectCycle(Node *head) {
    Node *slow = head;
    Node *fast = head;
    
    // Move slow and fast pointers until fast reaches the end or both meet
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        
        // If fast pointer meets slow pointer, cycle detected
        if (fast == slow) {
            return true;
        }
    }

    // No cycle detected
    return false;
}



//*************************************************************************

/**********************************************************************
 * Function: firstNode
 * -------------------
 * Finds the first node of a cycle in a linked list, if a cycle exists,
 * using Floyd's Cycle Detection Algorithm.
 *
 * Parameters:
 *     head: Pointer to the head of the linked list.
 *
 * Returns:
 *     Pointer to the first node of the cycle if a cycle exists,
 *     nullptr otherwise.
 **********************************************************************/
Node *firstNode(Node *head) {
    Node *slow = head;
    Node *fast = head;
    Node *meetingPoint = nullptr;

    // Find the meeting point of slow and fast pointers
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            meetingPoint = slow;
            break; // Meeting point found, exit the loop
        }
    }

    // If no meeting point found, no cycle exists
    if (meetingPoint == nullptr) {
        return nullptr;
    }

    // Move one pointer to the head and another from meeting point until they meet
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    // Now both pointers are at the start of the cycle
    return slow; // Return the first node of the cycle
}



//***************************************************************

//check for palindrome in linked list

//brute force approach

Node* reverseLL(Node* head){
    Node* prev=nullptr;
    Node* curr=head;

    while(curr!=nullptr){
       Node* nextNode=curr->next;
       curr->next=prev;
       prev=curr;
       curr=nextNode;
    }

    return prev;
}
bool isPalindrome(Node *head)
{
    Node* temp=head;
    Node* reversedTemp=reverseLL(head);

    while (reversedTemp->next != nullptr && temp->next != nullptr) {
       if (reversedTemp->data != temp->data){
           return false;
       }
    }

    return true;
}


//optimal approach using floyd's cycle algorithm

/**********************************************************************
 * Function: reverseLL
 * -------------------
 * Reverses a linked list.
 *
 * Parameters:
 *     head: Pointer to the head of the linked list.
 *
 * Returns:
 *     Pointer to the head of the reversed linked list.
 **********************************************************************/
Node* reverseLL(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;

    // Traverse the list, reversing pointers as we go
    while (curr != nullptr) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    // Return the head of the reversed list
    return prev;
}

/**********************************************************************
 * Function: isPalindrome
 * -----------------------
 * Checks whether a linked list is a palindrome.
 *
 * Parameters:
 *     head: Pointer to the head of the linked list.
 *
 * Returns:
 *     true if the linked list is a palindrome, false otherwise.
 **********************************************************************/
bool isPalindrome(Node* head) {
    // Initialize two pointers to traverse the linked list
    Node* slow = head;
    Node* fast = head;

    // Move fast pointer to the end of the list and slow pointer to the middle
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the list
    Node* secondHalf = reverseLL(slow);

    // Compare elements of the first and second halves
    Node* firstHalf = head;
    while (secondHalf != nullptr) {
        if (firstHalf->data != secondHalf->data) {
            return false; // Not a palindrome
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    // Linked list is a palindrome
    return true;
}



//******************************************************************************************************************

/**********************************************************************
 * Function: removeKthNode
 * -----------------------
 * Removes the Kth node from the end of a linked list.
 *
 * Parameters:
 *     head: Pointer to the head of the linked list.
 *     K: Position of the node to be removed from the end of the list.
 *
 * Returns:
 *     Pointer to the head of the linked list after removal.
 **********************************************************************/
Node* removeKthNode(Node* head, int K) {
    // Count the number of nodes in the linked list
    int length = countLL(head);

    // Calculate the position of the node to be removed from the beginning of the list
    int DeleteNode = length - K + 1;

    // Special case: if the node to be removed is the head of the list
    if (DeleteNode == 1) {
        Node* newHead = head->next;
        delete head;
        return newHead;
    }

    // Initialize pointers for traversal and preservation of the previous node
    int i = 1;
    Node* temp = head;
    Node* preserve = nullptr;

    // Traverse the linked list to find the node before the one to be removed
    while (i < DeleteNode - 1) {
        preserve = temp;
        temp = temp->next;
        i++;
    }

    // Remove the node from the list
    Node* nodeToRemove = preserve->next;
    preserve->next = nodeToRemove->next;
    delete nodeToRemove;

    // Return the head of the linked list after removal
    return head;
}


//optimised approach

Node* removeKthNode(Node* head, int K) {
    // Initialize two pointers fast and slow to the head of the linked list
    Node* fast = head;
    Node* slow = head;

    // Move the fast pointer K steps ahead
    for (int i = 0; i < K; i++) {
        fast = fast->next;
    }

    // If fast becomes nullptr, it means K is equal to the length of the linked list
    // In this case, return head->next to remove the first node
    if (fast == nullptr) {
        return head->next;
    }

    // Move both fast and slow pointers simultaneously until fast reaches the end of the list
    while (fast->next != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }

    // Now, slow is pointing to the node just before the Kth node from the end
    // Remove the Kth node by updating the next pointer of the node before it to skip over the Kth node
    slow->next = slow->next->next;

    // Delete the Kth node
    delete slow->next;

    // Return the updated head of the linked list
    return head;
}

+[poisa]

 //*************************************************************************/
/*
time complexity: O(max(n1,n2))
space complexity: O(max(n1,n2))
*/

// Function to add two numbers represented as linked lists
Node *addTwoNumbers(Node *num1, Node *num2)
{
    // Initialize a dummy head node to simplify the code
    Node* dummyHead = nullptr;
    // Initialize curr pointer to dummyHead
    Node* curr = dummyHead;
    // Pointers to traverse input linked lists
    Node* temp1 = num1;
    Node* temp2 = num2;
    // Variable to hold carry during addition
    int carry = 0;

    // Loop until both input lists are fully traversed
    while (temp1 != nullptr || temp2 != nullptr) {
        // Initialize sum with carry
        int sum = carry;
        // Add values of nodes if they exist
        if (temp1) {
            sum += temp1->data;
            temp1 = temp1->next;
        }
        if (temp2) {
            sum += temp2->data;
            temp2 = temp2->next;
        }

        // Create a new node with the value of sum % 10
        Node* newNode = new Node(sum % 10);
        // Update carry for the next iteration
        carry = sum / 10;

        // If dummyHead is nullptr, set it to the newly created node
        if (!dummyHead)
            dummyHead = newNode;
        else
            // Otherwise, link the new node to the result linked list
            curr->next = newNode;
        
        // Move curr pointer to the newly added node
        curr = newNode;
    }
    
    // If there is a remaining carry, add it as a new node
    if (carry) {
        curr->next = new Node(carry);
    }
    
    // Return the result linked list (excluding the dummy head)
    return dummyHead;
}


//*********************************************************************************************************************



/**
 * Definition for singly-linked list.
 * struct Node {
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

/**
 * @brief Sorts a linked list containing only 0s, 1s, and 2s.
 * 
 * @param head The head of the linked list.
 * @return Node* The head of the sorted linked list.
 */
Node* sortList(Node* head) {
    // Creating the dummy nodes
    Node* zeroHead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);

    // Creating tail pointers to keep track of these nodes
    Node* zeroTail = zeroHead;
    Node* oneTail = oneHead;
    Node* twoTail = twoHead;

    // Pointer to traverse the original list
    Node* curr = head;

    // Traverse the original list and categorize nodes into three groups
    while (curr) {
        if (curr->data == 0) {
            zeroTail->next = new Node(0);
            zeroTail = zeroTail->next;
        } else if (curr->data == 1) {
            oneTail->next = new Node(1);
            oneTail = oneTail->next;
        } else {
            twoTail->next = new Node(2);
            twoTail = twoTail->next;
        }

        curr = curr->next;
    }

    // Connect the three lists
    zeroTail->next = oneHead->next ? oneHead->next : twoHead->next;
    oneTail->next = twoHead->next;

    // Set the head of the sorted list
    Node* sortedHead = zeroHead->next;

    // Delete the dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    // Return the head of the sorted list
    return sortedHead;
}







*************************************************************************/
//function for adding one number to linked list
/*
time complexity: O(3N)
space complexity: O(1)
*/

// Function to reverse a linked list recursively
Node* reverseLL(Node *current, Node *prev = nullptr) {
    // Base case: If current node is nullptr, return the new head of the reversed list
    if (current == nullptr) {
        return prev;
    }

    // Save the next node
    Node* next = current->next;
    // Reverse the pointer of the current node to point to the previous node
    current->next = prev;

    // Recursive call to process the next node, pass current node as previous for the next node
    return reverseLL(next, current);
}


// Function to add one to a number represented by a linked list
Node *addOne(Node *head) {
    // Reverse the linked list to simplify addition
    head = reverseLL(head);
    
    // Initialize variables for addition and carry
    Node* temp = head;
    int carry = 1;
    
    // Iterate through the reversed list
    while (temp != nullptr) {
        // Add carry to the current node's data
        temp->data += carry;
        
        // If the data is less than 10, break the loop since no further carry is needed
        if (temp->data < 10) {
            carry = 0;
            break;
        } else {
            // If the data is 10 or more, set data to 0 and carry over to the next node
            temp->data = 0;
            carry = 1;
        }
        
        // Move to the next node
        temp = temp->next;
    }
    
    // If there is still a carry after processing all nodes, add a new node at the beginning
    // of the reversed list with value 1
    if (carry == 1) {
        Node* newNode = new Node(carry);
        head = reverseLL(head); // Reverse the list again to restore the original order
        newNode->next = head;
        return newNode;
    }
    
    // Reverse the list again to restore the original order
    head = reverseLL(head);
    return head;
}



// more optimised code for this problem

// Function to recursively add one to the linked list
int helper(Node* temp) {
    // Base case: If the current node is nullptr, return 1 (carry)
    if (temp == nullptr) {
        return 1;
    }

    // Recursive call to process the next node, and get the carry
    int carry = helper(temp->next);

    // Add the carry to the current node's data
    temp->data = temp->data + carry;

    // If the data is less than 10, no further carry needed, return 0
    if (temp->data < 10) {
        return 0;
    }

    // If the data is 10 or more, set data to 0 and return 1 (carry)
    temp->data = 0;
    return 1;
}

// Function to add one to the number represented by the linked list
Node *addOne(Node *head) {
    // Call the helper function to add one recursively
    int carry = helper(head);
    
    // If there is a carry after adding one, insert a new node at the beginning of the list
    if (carry == 1) {
        Node* newNode = new Node(1);
        newNode->next = head;
        return newNode;
    }
    
    // If no carry, return the original head of the list
    return head;
}


//*************************************************************************************************************************

//find the intersection of two linked list
//time complexity : O(n1 X mapp) + O(n2 X mapp)
// space complexity: O(n1)
#include <unordered_map>   // Include necessary header for unordered_map

/**
 * @brief Finds the intersection point of two singly linked lists.
 * 
 * This function takes the heads of two linked lists as input parameters.
 * It traverses the first linked list and stores each node in an unordered map.
 * Then, it iterates through the second linked list and checks if each node exists
 * in the unordered map created from the first list. If a node is found, it is
 * considered the intersection point, and the function returns that node.
 * If no intersection is found, it returns nullptr.
 * 
 * @param firstHead Head of the first linked list
 * @param secondHead Head of the second linked list
 * @return Node* Pointer to the intersection point if found, nullptr otherwise
 */
Node* findIntersection(Node *firstHead, Node *secondHead)
{
    Node* temp1 = firstHead;                    // Initialize temporary pointer for the first linked list
    Node* temp2 = secondHead;                   // Initialize temporary pointer for the second linked list

    std::unordered_map<Node*, int> mpp;         // Create an unordered map to store nodes from the first linked list

    // Traverse the first linked list and store each node in the unordered map
    while (temp1 != nullptr) {
        mpp[temp1] = 1;
        temp1 = temp1->next;
    }

    // Traverse the second linked list and check if each node exists in the map
    while (temp2 != nullptr) {
        // If a node from the second list is found in the map, return it as the intersection point
        if (mpp.find(temp2) != mpp.end()) {
            return temp2;
        }
        temp2 = temp2->next;
    }

    // If no intersection is found, return nullptr
    return nullptr;
}


//better solution

//time complexity: O(n1 + 2n2)
//space complexity: O(1)

/**
 * @brief Finds the collision point of two linked lists given a difference in lengths.
 * 
 * This function is a helper function for finding the intersection point of two linked lists.
 * It takes two pointers to nodes (t1 and t2) and an integer representing the difference in lengths (d).
 * It advances the longer list pointer (t2) by d steps.
 * Then, it iterates through both lists simultaneously until the collision point is reached.
 * 
 * @param t1 Pointer to the head of the first linked list
 * @param t2 Pointer to the head of the second linked list
 * @param d Difference in lengths between the two linked lists
 * @return Node* Pointer to the collision point
 */
Node* collisionPoint(Node* t1, Node* t2, int d) {
    // Advance the pointer of the longer list by d steps
    while (d > 0) {
        d--;
        t2 = t2->next;
    }

    // Iterate through both lists until the collision point is reached
    while (t1 != t2) {
        t1 = t1->next;
        t2 = t2->next;
    }

    // Return the collision point
    return t1;
}

/**
 * @brief Finds the intersection point of two linked lists.
 * 
 * This function takes the heads of two linked lists as input parameters.
 * It calculates the lengths of both lists and finds the difference in lengths.
 * Then, it calls the collisionPoint function to find the intersection point.
 * 
 * @param firstHead Pointer to the head of the first linked list
 * @param secondHead Pointer to the head of the second linked list
 * @return Node* Pointer to the intersection point if found, nullptr otherwise
 */
Node* findIntersection(Node *firstHead, Node *secondHead) {
    // Initialize pointers for traversing both lists
    Node* t1 = firstHead;
    Node* t2 = secondHead;

    // Variables to store the lengths of the two lists
    int n1 = 0, n2 = 0;

    // Calculate the length of the first list
    while (t1 != nullptr) {
        n1++;
        t1 = t1->next;
    }

    // Calculate the length of the second list
    while (t2 != nullptr) {
        n2++;
        t2 = t2->next;
    }

    // Reset pointers to the heads of the lists
    t1 = firstHead;
    t2 = secondHead;

    // Find the difference in lengths between the two lists
    int diff = abs(n1 - n2);

    // Adjust the pointers to the same starting point if one list is longer
    if (n1 < n2) {
        return collisionPoint(firstHead, secondHead, diff);
    } else {
        return collisionPoint(secondHead, firstHead, diff);
    }
}


//best solution


/**
 * @brief Finds the intersection point of two singly linked lists.
 * 
 * This function takes the heads of two linked lists as input parameters.
 * It iterates through both linked lists simultaneously until either it finds
 * an intersection point or reaches the end of both lists.
 * 
 * @param firstHead Pointer to the head of the first linked list
 * @param secondHead Pointer to the head of the second linked list
 * @return Node* Pointer to the intersection point if found, nullptr otherwise
 * 
 * Time Complexity: O(n1 + n2), where n1 and n2 are the lengths of the two linked lists, respectively.
 * Space Complexity: O(1)
 */
Node* findIntersection(Node *firstHead, Node *secondHead)
{
    // If either of the linked lists is empty, there can be no intersection
    if (firstHead == nullptr && secondHead == nullptr) {
        return nullptr;
    }

    // Initialize two pointers to traverse the linked lists
    Node* temp1 = firstHead;
    Node* temp2 = secondHead;

    // Iterate through both linked lists until an intersection point is found or both lists end
    while (temp1 != temp2) {
        // Move temp1 and temp2 one step forward
        temp1 = (temp1 == nullptr) ? secondHead : temp1->next;
        temp2 = (temp2 == nullptr) ? firstHead : temp2->next;
    }
    
    // Return the intersection point if found, otherwise return nullptr
    return temp1;
}
