#include <vector>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
    int target;
    TreeNode* root;
    bool find(TreeNode* ptr, TreeNode* ignore, int k){
    if(!ptr) return false;

    if(ptr != ignore && ptr->val == k) return true;

    return find(ptr->left, ignore, k) ||
           find(ptr->right, ignore, k);
}

    bool go(TreeNode* ptr){
        if(!ptr) return false;

        return go(ptr->left) ||
            find(root, ptr, target - (ptr->val)) ||
            go(ptr->right);
    };
public:
    bool findTarget(TreeNode* r, int k) {
        target = k;
        root = r;
        if(!r->left && !r->right) return false;

        return go(r);
    }
};