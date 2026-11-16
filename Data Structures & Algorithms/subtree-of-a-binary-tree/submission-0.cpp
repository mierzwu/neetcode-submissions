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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*>path;
        stack<TreeNode*>path1;
        if(p==nullptr && q!=nullptr) return false;
        if(p!=nullptr && q==nullptr) return false;
        if(p==nullptr && q==nullptr) return true;
        if(p!=nullptr && q!=nullptr && q->val!=p->val) return false;
        
        path.push(p->left);
        path.push(p->right);
        path1.push(q->left);
        path1.push(q->right);
        while(!path.empty()){
            p = path.top();
            path.pop();
            if(p!=nullptr) path.push(p->left);
            if(p!=nullptr) path.push(p->right);
            q = path1.top();
            path1.pop();
            if(q!=nullptr) path1.push(q->left);
            if(q!=nullptr) path1.push(q->right);

            if(p==nullptr && q!=nullptr) return false;
            if(p!=nullptr && q==nullptr) return false;
            if(p!=nullptr && q!=nullptr && q->val!=p->val) return false;

        }
        return true;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        stack<TreeNode*>stk;
        stk.push(root);
        while(!stk.empty()){
            root = stk.top();
            stk.pop();
            if(isSameTree(root, subRoot)) return true;;
            if(root->left!=nullptr) stk.push(root->left);
            if(root->right!=nullptr) stk.push(root->right);
        }
        return false;
    }
};
