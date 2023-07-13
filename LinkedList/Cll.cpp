#include <iostream>
#include <map>
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
        do
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        } while (current->next != head);
    }

    // Function to add a new node at the beginning of the list
    void prepend(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            head->next = head;
            tail = head;
        }
        else
        {
            tail->next = newNode;
            newNode->next = head;
            head = newNode;
        }
        display();
    }

    // Function to add a new node at the end of the list
    void append(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            head->next = head;
            tail = head;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
        display();
    }
    // to insert at a pos
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
            itr->next = newNode;
        }
        display();
    }
    // Function to display the elements in the list
    void display()
    {
        Node *current = head;
        do
        {
            cout << current->data << "->";
            current = current->next;
        } while (current != head);
        cout << 'x' << endl;
    }
    // function to return the length of LL
    int length()
    {
        Node *current = head;
        int cnt = 0;
        do
        {
            cnt++;
            current = current->next;
        } while (current->next != head);
        return cnt++;
    }
    // function to delete a node at position
    void del(int pos)
    {
        if (pos == 1)
        {
            Node *temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
        }
        else if (pos == length())
        {
            Node *current = head;
            while (current->next->next != head)
            {
                current = current->next;
            }
            delete current->next;
            tail = current;
            tail->next = head;
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
        display();
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
        if (head->next == tail)
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
        tail->next = head; // basically the same code as singly linked list as circular can be imagined as opening and reversing then finally closing with this line of code.
        display();
    }
    // to detect loop
    bool isCyclic()
    {
        if (head == nullptr)
            cout << "empty list\n";
        map<Node *, bool> visited;
        Node *itr = head->next;
        while (itr != nullptr)
        {
            if (visited[itr])
                return true;
            visited[itr] = true;
            itr = itr->next;
        }
        return false;
    }
};

// Test the linked list implementation
int main()
{
    LinkedList list;

    list.prepend(0);
    list.prepend(-1);
    list.prepend(-2);
    list.append(1);
    list.append(2);
    list.append(3);
    (list.isCyclic()) ? cout << "Cycle detected \n" : cout << " no Cycle detected \n";
    list.reverse();

    list.del(list.length());

    return 0;
}
