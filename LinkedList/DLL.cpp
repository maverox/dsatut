#include <iostream>
using namespace std;
// Node class represents a single node in the linked list
class Node
{
public:
    int data;   // Data stored in the node
    Node *next; // Pointer to the next node
    Node *prev; // Pointer to the previous node

    // Constructor
    Node(int value) : data(value), next(nullptr), prev(nullptr) {} // The initialization list : data(value), next(nullptr) follows the constructor declaration and specifies how the member variables of the class should be initialized. In this case, it initializes the data member with the value passed to the constructor (value)
};

// Linked list class
class DoubleLL
{
private:
    Node *head;
    Node *tail;

public:
    DoubleLL() : head(nullptr), tail(nullptr)
    { // default constuctor
        tail = head;
    }
    ~DoubleLL()
    { // destructor
        Node *itr = head;
        while (itr != nullptr)
        {
            Node *temp = itr;
            itr = itr->next;
            delete temp;
        }
    }
    // to prepend node at head
    void prepend(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            head->prev = nullptr;
            head->next = nullptr;
            tail = head;//note this caused segFault
        }
        else
        {
            head->prev = newNode;
            newNode->next = head;
            newNode->prev = nullptr;
            head = newNode;
        }
    }
    // to append node at tail
    void append(int value)
    {
        Node *newNode = new Node(value);
        if (tail == nullptr)
        {
            tail = newNode;
            tail->prev = nullptr;
            tail->next = nullptr;
            head = tail;//note this caused segFault by symmetry as above
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            newNode->next = nullptr;
            tail = newNode;
        }
    }
    // to insert at given position
    void insert(int value, int pos)
    {
        Node *newNode = new Node(value);
        if (pos == 1)
        {
            prepend(value);
        }
        else if (pos == length())
        {
            append(value);
        }
        else
        {
            Node *itr = head;
            for (int i = 1; i < pos - 1; i++)
            {
                itr = itr->next;
            }
            newNode->next = itr->next;
            itr->next->prev = newNode;
            newNode->prev = itr;
            itr->next = newNode;
        }
    }

    // returns length of the doubly linked list
    int length()
    {
        Node *itr = head;
        int cnt = 0;
        while (itr != nullptr)
        {
            cnt++;
            itr = itr->next;
        }
        return cnt++;
    }
    // to remove a node from a specified position
    void del(int pos)
    {
        if (pos == 1)
        {
            Node *temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
        else if (pos == length())
        {
            Node *temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
        else
        {
            Node *itr = head;
            for (int i = 1; i < pos - 1; i++)
            {
                itr = itr->next;
            }
            Node *temp = itr->next;
            itr->next = temp->next;
            itr->next->prev = itr;
            delete temp;
        }
    } // reverse function helper
    Node* reverseHelper(Node *head)
    {
        if (head->next == nullptr) {
            return head;
        }
        Node* subHead = reverseHelper(head->next);
        head->next->next = head;//reverses the direction of next at each level of recursion
        head->prev = head->next;// reverses the direction of prev at each level of recursion
        head->next = nullptr;;
        return subHead;
    }
    // reverse doubly linked list
    void reverse()
    {
        tail = head;
        head = reverseHelper(head);
    }
    Node *Head()
    {
        return head;
    } // returns the tail pointer
    Node *Tail()
    {
        return tail;
    }
    
    // Function to display the elements in the list
    void display()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << "->";
            current = current->next;
        }
        cout << 'x' << endl;
    }
};

// Test the linked list implementation
int main()
{
    DoubleLL list;

    list.append(1);
    list.append(2);
    list.append(3);
    list.prepend(0);
    list.display();
    list.reverse();
    list.display();
    list.del(list.length());
    list.display();
    return 0;
}
