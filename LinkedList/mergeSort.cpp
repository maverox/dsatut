

struct ListListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptrptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* findMid(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head->next;
    while(fast!=nullptr && fast->next !=nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
//to merge to sorted list
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;
        
        while (curr1!=nullptr && curr2 != nullptr){
            ListNode* temp;
            if (curr1->val < curr2->val) {
                temp = curr1;
                curr1=curr1->next;
            } else {
                temp = curr2;
                curr2=curr2->next;
            }
            tail->next = temp;
            tail = tail->next;
            tail->next = nullptr;
        }

        while(curr1!=nullptr) {
            tail->next= curr1;
            curr1 = curr1->next;
            tail = tail->next;

        } while(curr2!=nullptr) {
            tail->next= curr2;
            curr2 = curr2->next;
            tail = tail->next;
            
        }
        tail->next = nullptr;
        dummy = dummy->next;
        return dummy;
    }
ListNode* sortList(ListNode *head) {
    // Write your code here.
    if (head == nullptr || head->next==nullptr) return head;
    ListNode* mid = findMid(head);
    ListNode* left = head;
    ListNode* right = mid->next;
    mid->next = nullptr;
    left = sortList(left);
    right = sortList(right);
    return mergeTwoLists(left, right);
    }
};