#include <iostream>
using namespace std;

struct ListNode {
int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
   /* ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temp = head;
        ListNode* leftNode=nullptr, * rightNode=nullptr;
        while (temp != nullptr) {
            if (left == temp->val ) {
                leftNode = temp;
    
    }
            else if (right == temp->val) {
                rightNode = temp;
            }
            temp = temp->next;
        }

        ListNode* prev = nullptr, *curr = leftNode, *next;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }
    }*/

   /* ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head; 

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        ListNode* curr = prev->next;
        ListNode* nextP = nullptr;

        for (int i = left; i <= right; i++) {
            nextP = curr->next;
            curr->next = nextP->next;
            nextP->next = prev->next;
            prev->next = nextP;
        }

        return dummy->next;  
    }*/

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;  
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        ListNode* curr = prev->next;
        ListNode* nextP = nullptr;

        for (int i = left; i < right; i++) {
            nextP = curr->next;
            curr->next = nextP->next;
            nextP->next = prev->next;
            prev->next = nextP;
        }

        return dummy->next; 
    }
};
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    printList(head);

    Solution solution;
    head = solution.reverseBetween(head, 2, 4);  // Reverse from position 2 to 4.

    cout << "List after reversal: ";
    printList(head);

    return 0;
}