#include <iostream>
using namespace std;
// Node class represents a single node in the linked list
class Node
{
public:
    int data;   // Data stored in the node
    Node *next; // Pointer to the next node

    // Constructor
    Node(int value) : data(value), next(nullptr) {} // The initialization list : data(value), next(nullptr) follows the constructor declaration and specifies how the member variables of the class should be initialized. In this case, it initializes the data member with the value passed to the constructor (value)
};

// Linked list class
class LinkedList
{
private:
    Node *head; // Pointer to the head of the list
    Node *tail; // Pointer to the tail of the list
public:
    // Constructor
    LinkedList() : head(nullptr), tail(nullptr){}

    // Destructor
    ~LinkedList()
    {
        // Delete all nodes in the list
        Node *current = head;
        while (current != nullptr)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
    }

    // Function to add a new node at the beginning of the list
    void prepend(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Function to add a new node at the end of the list
    void append(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = nullptr;
        }
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
    // function to return the length of LL
    int length()
    {
        Node *current = head;
        int cnt = 0;
        while (current != nullptr)
        {
            cnt++;
            current = current->next;
        }
        return cnt++;
    }
    // function to delete a node at position
    void del(int pos)
    {
        if (pos == 1)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        else if (pos == length())
        {
            Node *current = head;
            while (current->next->next != nullptr)
            {
                current = current->next;
            }
            delete current->next->next;
            current->next = nullptr;
        }
        else
        {
            Node *itr = head;
            for (int i = 1; i < pos - 1; i++)
            {
                itr = itr->next;
            }
            Node *temp = itr->next;
            itr->next = itr->next->next;
            delete temp;
        }
    }
};

// Test the linked list implementation
int main()
{
    LinkedList list;

    list.append(1);
    list.append(2);
    list.append(3);

    list.prepend(0);

    list.display();
    list.del(2);
    list.display();
    return 0;
}
