/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
 ListNode* swapPairs(ListNode* head) {

     if (head == nullptr || head->next == nullptr) {
         return head; // Return if there are fewer than 2 nodes
     }

     ListNode* newHead = head->next;
     ListNode* pre = NULL;
     ListNode* temp = head;

     while (temp != NULL && temp->next != NULL) {
         ListNode* first = temp;
         ListNode* second = temp->next;

         first->next = second->next;
         second->next = first;

         if (pre != NULL) {
             pre->next = second;
         }
         pre = first;
         temp = first->next;
     }
     return newHead;


 }
};