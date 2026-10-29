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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        stack<TreeNode*> to_visit;
        to_visit.push(root);
        while(!to_visit.empty()) {
            TreeNode* node = to_visit.top();
            to_visit.pop();
            TreeNode* _left = node -> left;
            TreeNode* _right = node -> right;
            if(_left != nullptr) {
                if(_left -> left == nullptr && _left -> right == nullptr) {sum += _left -> val; }
                else { to_visit.push(_left); }
            }
            if(_right != nullptr) {
                if(_right -> left != nullptr || _right -> right != nullptr) { to_visit.push(_right); }
            }
        }
        return sum;
    }
};
