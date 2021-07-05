#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
   public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, postorder, 0, inorder.size() - 1, 0,
                     postorder.size() - 1);
    }
    TreeNode* build(vector<int>& inorder,
                    vector<int>& postorder,
                    int l1,
                    int r1,
                    int l2,
                    int r2) {
        if (l1 > r1)
            return nullptr;
        TreeNode* root = new TreeNode(postorder[r2]);
        int mid = l1;
        while (inorder[mid] != root->val) {
            ++mid;
        }
        int leftsize = mid - l1;
        root->left =
            build(inorder, postorder, l1, mid - 1, l2, l2 + leftsize - 1);
        root->right =
            build(inorder, postorder, mid + 1, r1, l2 + leftsize, r2 - 1);
        return root;
    }
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};