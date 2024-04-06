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









