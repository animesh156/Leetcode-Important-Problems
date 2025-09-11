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
  unordered_map<int,int> mp;
   TreeNode* f(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd){
    if(preStart > preEnd || inStart > inEnd) return nullptr;

    int rootVal = preorder[preStart];
    TreeNode* root = new TreeNode(rootVal);
    int rootInd = mp[rootVal];
    int leftTreeSize = rootInd - inStart;

    root->left = f(preorder, preStart + 1, preStart + leftTreeSize, inorder, inStart, rootInd - 1);
    root->right = f(preorder, preStart + leftTreeSize + 1, preEnd, inorder, rootInd + 1, inEnd);

    return root;
   }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]] = i;
        }

       return  f(preorder, 0 , n - 1, inorder, 0, n - 1);
    }
};
