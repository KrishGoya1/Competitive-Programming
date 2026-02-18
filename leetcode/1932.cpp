#include<vector>
#include<unordered_map>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
bool isPossible(TreeNode* root, long long l, long long r){
    if(root == nullptr)  return true;
    if(root->val < r and root->val > l)
        return isPossible(root->left, l, root->val) and 
                                isPossible(root->right, root->val, r);
    else return false;
}
bool isValidBST(TreeNode* root) {
        long long int min = -1000000000000, max = 1000000000000;
        return isPossible(root, min, max);
}

    void build(TreeNode* parent, unordered_map<int,TreeNode*>& roots){
        if(parent->left && roots.count(parent->left->val)){
            parent->left = roots[parent->left->val];
            roots.erase(parent->left->val);
            build(parent->left,roots);
        }
        if(parent->right && roots.count(parent->right->val)){
            parent->right = roots[parent->right->val];
            roots.erase(parent->right->val);
            build(parent->right,roots);
        }
    }

public:
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        int n = trees.size();
        if(n == 1) return trees[0];
        if(n == 0) return nullptr;

        unordered_map<int,TreeNode*> roots, leafs;
        for(const auto& tree : trees){
            if(tree->left){
                leafs[tree->left->val] =tree->left;
            }
            if(tree->right){
                leafs[tree->right->val] =tree->right;
            }
        }

        TreeNode* ans = nullptr;

        for(auto& it : trees){
            roots[it->val] = it;
            if(leafs.find(it->val) == leafs.end()){
                if(ans) return NULL;
                ans = it;
            }
        }
        if(!ans) return nullptr;
        build(ans,roots);
        if(roots.size() > 1) return nullptr;
        return isValidBST(ans) ? ans : nullptr;

    }
};