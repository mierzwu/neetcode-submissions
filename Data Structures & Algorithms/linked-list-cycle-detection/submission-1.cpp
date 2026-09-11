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
    bool hasCycle(ListNode* head) {
        int i = 0;
        set<ListNode*> visited;
        while(head!=nullptr){
            i++;
            visited.insert(head);
            if(visited.size() != i) return true;
            head = head->next;
        }
        return false;
    }
};
