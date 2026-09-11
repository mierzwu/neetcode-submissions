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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* marged = new ListNode();
        ListNode* head = marged;
        while(list1!=nullptr && list2!=nullptr){
            if(list1->val<=list2->val){
                marged->next = list1;
                list1 = list1->next;
            }
            else{
                marged->next = list2;
                list2 = list2->next;
            }
            marged = marged->next;
        }
        if(list1!=nullptr) marged->next = list1;
        else if(list2!=nullptr) marged->next = list2;
        return head->next;
    }
};
