/*
 * Definition for linked list. */
  class Node {
   public:
 		int data;
 		Node *next;
  		Node *child;
 		Node() : data(0), next(nullptr), child(nullptr){};
 		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
  };

//merge two sorted linked list
Node* mergeTwoLists(Node* list1, Node* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        Node* dummy = new Node(-1);
        Node* tail = dummy;
        Node* curr1 = list1;
        Node* curr2 = list2;
        
        while (curr1!=nullptr && curr2 != nullptr){
            Node* temp;
            if (curr1->data < curr2->data) {
                temp = curr1;
                curr1=curr1->child;
            } else {
                temp = curr2;
                curr2=curr2->child;
            }
            tail->child = temp;
            tail = tail->child;
            tail->child = nullptr;
        }

        while(curr1!=nullptr) {
            tail->child= curr1;
            curr1 = curr1->child;
            tail = tail->child;

        } while(curr2!=nullptr) {
            tail->child= curr2;
            curr2 = curr2->child;
            tail = tail->child;
            
        }
        tail->child = nullptr;
        dummy = dummy->child;
        return dummy;
    }
Node* flattenLinkedList(Node* head) 
{
	// Write your code here
	//base case 
	if(head->next == nullptr || head==nullptr) return head;
	Node* down = head;
	Node* right = flattenLinkedList(head->next);
	down->next = nullptr;
	return mergeTwoLists(down, right);
}
// running fine on leetcode