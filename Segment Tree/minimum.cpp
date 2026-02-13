#include<iostream>
#include<vector>
#include <queue>
#include <iomanip>

using namespace std;


struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int x){
    val = x;
    left = nullptr;
    right = nullptr;
  }

};

TreeNode* makeTree(const vector<int>& arr,int l,int r){
    if(l == r){
        return new TreeNode(arr[l]); 
    }

    int mid = l + (r-l) / 2;

    TreeNode* left = makeTree(arr,l,mid); 
    TreeNode* right = makeTree(arr,mid+1,r); 

    int value = min(left->val,right->val);

    TreeNode* node = new TreeNode(value);
    node->left = left;
    node->right = right;
    return node;
}


int findAns(TreeNode* root, int l, int r){
    int ans = 0;


    return ans;
}

void printTree(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* currentNode = q.front();
            q.pop();
            
            if (currentNode) {
                cout << setw(3) << currentNode->val;
                q.push(currentNode->left);
                q.push(currentNode->right);
            } else {
                cout << "   ";
            }

            if (i < levelSize - 1) cout << " ";
        }
        cout << endl;
    }
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8};

    TreeNode* root = makeTree(arr,0,arr.size() - 1);

    printTree(root);


}