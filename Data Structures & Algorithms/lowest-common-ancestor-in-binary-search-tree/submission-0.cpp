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
    pair<TreeNode*,int> dfs(pair<TreeNode*, int>temp, TreeNode* p, TreeNode* q){
        stack<pair<TreeNode*, int>>stk;
        TreeNode* root = temp.first;
        int depth = temp.second;
        stk.push({root,depth});
        pair<TreeNode*,int>lca = {root, depth};
        bool pp=false;
        bool qp=false;
        while(!stk.empty()){  
            root = stk.top().first;
            depth = stk.top().second;
            stk.pop();
            if(root->left!=nullptr) stk.push({root->left, depth+1});
            if(root->right!=nullptr) stk.push({root->right, depth+1});
            if(root->val==p->val) pp = true;
            if(root->val==q->val) qp = true;
            if(pp && qp) return lca;
        }
        lca = {root,0};
        return lca;
        
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<pair<TreeNode*, int>>stk;
        TreeNode* lca;
        pair<TreeNode*,int>temp;
        int maxDepth = 1;
        stk.push({root,1});
        while(!stk.empty()){
            TreeNode* root = stk.top().first;
            int depth = stk.top().second;
            stk.pop();
            if(root->left!=nullptr) stk.push({root->left, depth+1});
            if(root->right!=nullptr) stk.push({root->right, depth+1});
            temp = dfs({root,depth},p,q);
            if(temp.second >= maxDepth){
                maxDepth = temp.second;
                lca = temp.first;
            }
        }
        return lca;  
    }
};
