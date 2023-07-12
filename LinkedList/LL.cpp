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
    LinkedList() : head(nullptr), tail(nullptr)
    {
        tail = head;
    }

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
        if (head == nullptr)
        {
            head = newNode;
            head->next = nullptr;
            tail = head;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    // Function to add a new node at the end of the list
    void append(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            head->next = nullptr;
            tail = head;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            tail->next = nullptr;
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
            delete current->next;
            tail = current;
            tail->next = nullptr;
        }
        else
        {
            if (pos <= length() && pos >= 1)
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
            else
            {
                cerr << "Invalid position\n";
            }
        }
    } // return the head pointer
    Node *Head()
    {
        return head;
    } // returns the tail pointer
    Node *Tail()
    {
        return tail;
    } // helper recursive function
    Node *reverseHelper(Node *head)
    {
        if (head->next == nullptr)
        {
            return head;
        }
        Node *subHead = reverseHelper(head->next);
        head->next->next = head;
        head->next = nullptr;
        return subHead;
    }
    // reverses this linked list using recursion
    void reverse()
    {
        tail = head;
        head = reverseHelper(head);
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
    list.reverse();
    list.display();
    list.del(list.length());
    list.display();
    return 0;
}
