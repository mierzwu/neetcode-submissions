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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* temp;
        while(fast != nullptr && slow!=nullptr){
            fast = fast->next;
            count++;
            if(count-1>n){
                slow = slow->next;
            }
        }
        if(count == n){
            head = head->next;
        }
        else{
            slow->next = slow->next->next;
        }
        return head;
    }
};
