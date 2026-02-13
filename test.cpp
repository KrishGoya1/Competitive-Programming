#include <iostream>
#include <queue>
#include <iomanip>

using namespace std;

// Define a structure for the binary tree node
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to print the binary tree in the desired format
void printTree(TreeNode* root) {
    if (!root) return;

    // First, we need to determine the height of the tree for proper spacing
    int height = 0;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* currentNode = q.front();
            q.pop();
            if (currentNode) {
                q.push(currentNode->left);
                q.push(currentNode->right);
            }
        }
        height++;
    }

    // Print the tree with proper indentation
    queue<pair<TreeNode*, int>> printQueue;  // Will store nodes and their level
    printQueue.push({root, 0});

    while (!printQueue.empty()) {
        int levelSize = printQueue.size();
        for (int i = 0; i < levelSize; ++i) {
            auto node = printQueue.front();
            printQueue.pop();
            TreeNode* currentNode = node.first;
            int currentLevel = node.second;

            // Indentation based on tree height
            int spaces = (1 << (height - currentLevel - 1)) - 1;
            if (currentNode) {
                cout << setw(spaces + 1) << currentNode->val;
            } else {
                cout << setw(spaces + 1) << " ";
            }

            if (i == 0 && currentNode) {
                if (currentNode->left || currentNode->right) {
                    // Print left child branch
                    cout << " / ";
                }
            }
            if (i == 1 && currentNode) {
                if (currentNode->left || currentNode->right) {
                    // Print right child branch
                    cout << " \\ ";
                }
            }
            if (currentNode) {
                printQueue.push({currentNode->left, currentLevel + 1});
                printQueue.push({currentNode->right, currentLevel + 1});
            }
        }
        cout << endl;
    }
}

int main() {
    // Create the binary tree
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(3);
    root->right = new TreeNode(4);

    // Print the binary tree in the desired format
    printTree(root);

    return 0;
}
