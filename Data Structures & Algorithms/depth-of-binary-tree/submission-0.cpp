/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maxDepth(TreeNode* head) {
        stack<pair<TreeNode*, int>>path;
        int depth = 0;
        int maxDepth = 0;
        if(head==nullptr) return 0;
        depth++;
        maxDepth++;
        if(head->left!=nullptr) path.push({head->left, depth+1});
        if(head->right!=nullptr) path.push({head->right, depth+1});
        while(!path.empty()){
            head = path.top().first;
            depth = path.top().second;
            path.pop();
            if(head->left!=nullptr) path.push({head->left, depth+1});
            if(head->right!=nullptr) path.push({head->right, depth+1});
            maxDepth = max(depth, maxDepth);

        }
        return maxDepth;
    }
};
