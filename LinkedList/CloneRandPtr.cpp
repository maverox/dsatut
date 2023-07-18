#include <iostream>
class Node
{
public:
    int data;   // Data stored in the node
    Node *next; // Pointer to the next node
    Node* arb;
    // Constructor
    Node(int value) : data(value), next(nullptr), arb(nullptr){} // The initialization list : data(value), next(nullptr) follows the constructor declaration and specifies how the member variables of the class should be initialized. In this case, it initializes the data member with the value passed to the constructor (value)
};
Node* copyList(Node* head) {
        if (!head)
            return nullptr;

        // Step 1: Insert the copied nodes right after their original nodes
        Node* curr = head;
        while (curr != nullptr) {
            Node* newNode = new Node(curr->data);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next;
        }

        // Step 2: Set the arbitrary pointers for the copied nodes
        curr = head;
        while (curr != nullptr) {
            // Adjust the arbitrary pointer for the copied node
            if (curr->arb)
                curr->next->arb = curr->arb->next;
            curr = curr->next->next;
        }

        // Step 3: Separate the original and copied lists
        Node* cHead = head->next;
        curr = head;
        while (curr != nullptr) {
            Node* temp = curr->next;
            curr->next = temp->next;
            if (temp->next)
                temp->next = temp->next->next;
            curr = curr->next;
        }

        return cHead;
    }
    // running fine on leetcode