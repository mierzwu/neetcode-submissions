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
    void reorderList(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* temp;
        ListNode* temp1 = nullptr;
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        while(slow != nullptr){
            temp = slow->next;
            slow->next = temp1;
            temp1 = slow;
            slow = temp;
        }
        while(temp1->next!=nullptr){
            temp = head->next;
            head -> next = temp1;
            temp1 = temp1->next;
            head = head->next;
            head->next = temp;
            head = head->next;
        }

    }
};
