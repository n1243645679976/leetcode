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
    int ans;
    void dfs(TreeNode* node, int depth){
        if(node->left){
            dfs(node->left, depth+1);
        }
        if(node->right){
            dfs(node->right, depth+1);
        }
        if(this->ans < depth){
            this->ans = depth;
        }
    }
    int maxDepth(TreeNode* root) {
        if(root){
            dfs(root, 1);
            return this->ans;
        }
        else{
            return 0;
        }
    }
};