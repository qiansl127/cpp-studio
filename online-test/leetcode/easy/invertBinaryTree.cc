/*
* # 226
* Invert Binary Tree
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void invert(TreeNode *tn) {
    if (!tn)
        return;
    invert(tn->left);
    TreeNode* temp = tn->right;
    tn->right = tn->left;
    tn->left = temp;
    invert(tn->left);
}

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    Solution *s = new Solution();
    s->invertTree(root);
    cout << root->val << endl;
    delete root;
    delete s;
    return 0;
}
