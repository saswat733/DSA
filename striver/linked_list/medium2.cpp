/*
*
 * Deletes all occurrences of a given value from a doubly linked list.
 *
 * @param head A pointer to the head of the doubly linked list.
 * @param k The value to be deleted from the list.
 * @return A pointer to the head of the modified list after deletion.
 */
Node* deleteAllOccurrences(Node* head, int k) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == k) {
            // Save the node to be deleted
            Node* delNode = temp;
            // Adjust head pointer if necessary
            if (delNode == head) {
                head = head->next;
                if (head != nullptr)
                    head->prev = nullptr;
            } else {
                // Update pointers of surrounding nodes
                delNode->prev->next = delNode->next;
                if (delNode->next != nullptr)
                    delNode->next->prev = delNode->prev;
            }
            // Move to the next node
            temp = temp->next;
            // Delete the node
            delete delNode;
        } else {
            // Move to the next node
            temp = temp->next;
        }
    }
    return head;
}


//*******************************************************************************************************************
// time complexity:nearly O(n2)
//space comlexity: O(1)
/**
 * Finds pairs of elements in a doubly linked list whose values sum up to a given integer.
 * @param head Pointer to the head node of the doubly linked list.
 * @param k The target sum.
 * @return A vector of pairs, each containing two values whose sum equals k.
 */
vector<pair<int, int>> findPairs(Node* head, int k)
{
    // Initialize an empty vector to store pairs of values.
    vector<pair<int, int>> arr;
    
    // Pointer to traverse the linked list.
    Node* firstNode = head;
    
    // Iterate through each node of the linked list.
    while(firstNode != nullptr) {
        // Pointer to traverse the list starting from the node following firstNode.
        Node* secondNode = firstNode->next;
        
        // Check pairs of nodes for their sum.
        while(secondNode != nullptr) {
            // If the sum of the data values of firstNode and secondNode equals k, add the pair to the vector.
            if(firstNode->data + secondNode->data == k) {
                arr.push_back(make_pair(firstNode->data, secondNode->data));
            }
            // Move to the next node.
            secondNode = secondNode->next;
        }
        // Move to the next node for the next iteration.
        firstNode = firstNode->next;
    }
    // Return the vector containing pairs of values whose sum equals k.
    return arr;
}



/**
 * Finds pairs of elements in a doubly linked list whose values sum up to a given integer.
 * Optimized version with O(n) time complexity.
 * @param head Pointer to the head node of the doubly linked list.
 * @param k The target sum.
 * @return A vector of pairs, each containing two values whose sum equals k.
 */
vector<pair<int, int>> findPairs(Node* head, int k)
{
    // Initialize an empty vector to store pairs of values.
    vector<pair<int,int>> ans;
    
    // If the linked list is empty, return an empty vector.
    if(head == nullptr ) {
        return ans;
    } 

    // Initialize pointers to traverse the linked list from the beginning and end.
    Node* left = head;
    Node* right = findTail(head);

    // Iterate until the left and right pointers meet or cross each other.
    while(left->data < right->data){
       // If the sum of the data values pointed by left and right pointers equals k, add the pair to the vector.
       if(left->data + right->data == k){
           ans.push_back({left->data, right->data});
           // Move left to the next node and right to the previous node.
           left = left->next;
           right = right->prev;
       }
       // If the sum is less than k, move left to the next node.
       else if(left->data + right->data < k){
           left = left->next;
       }
       // If the sum is greater than k, move right to the previous node.
       else{
           right = right->prev;
       }
    }
    
    // Return the vector containing pairs of values whose sum equals k.
    return ans;
}



/**
 * Removes duplicate nodes from a sorted doubly linked list.
 * @param head Pointer to the head node of the doubly linked list.
 * @return Pointer to the head node of the modified doubly linked list without duplicates.
 */
Node* removeDuplicates(Node* head)
{
    // If the linked list is empty, return nullptr.
    if(head == nullptr) {
        return head;
    }

    // Pointer to traverse the linked list.
    Node* current = head;

    // Traverse the linked list to remove duplicates.
    while(current->next != nullptr && current != nullptr) {
        // If current node's data is equal to the data of the next node, remove the duplicate.
        if(current->data == current->next->data) {
            // Store the next node to be deleted.
            Node* delNode = current->next;
            // Update current's next to skip the duplicate node.
            current->next = delNode->next;
            // If the next node exists, update its previous pointer.
            if(delNode->next != nullptr) {
                delNode->next->prev = current;
            }
            // Free the memory of the duplicate node.
            delete delNode;
        } else {
            // Move to the next node.
            current = current->next;
        }
    }

    // Return the pointer to the head node of the modified linked list.
    return head;
}





//*****************************************************************************************************


/**
 * Counts the number of nodes in a singly-linked list.
 * @param head Pointer to the head node of the singly-linked list.
 * @return Number of nodes in the list.
 */
int count_LL(Node* head) {
    int length = 0;
    Node* temp = head;
    while(temp != NULL) {
        length++;
        temp = temp -> next;
    }
    return length;
}

/**
 * Reverses every k nodes in a singly-linked list.
 * @param head Pointer to the head node of the singly-linked list.
 * @param k Number of nodes to reverse.
 * @return Pointer to the head node of the reversed list.
 */
Node* kReverse(Node* head, int k) {
    int length = count_LL(head);
    // Check if the linked list is empty or k is 1 or the length of the list is less than k
    if(head == NULL || head -> next == NULL || k == 1 || length < k)
        return head;

    Node* next = nullptr;
    Node* prev = nullptr;
    Node* curr = head;
    int i = 0;

    // Reverse the first k nodes
    while (i < k && curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        i++;
    }

    // Recursive call to reverse the next k nodes
    if (next != nullptr) {
        head->next = kReverse(next, k);
    }

    return prev;
}





