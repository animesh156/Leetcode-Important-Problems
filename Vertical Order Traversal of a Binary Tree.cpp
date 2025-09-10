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
    map<int, map<int, multiset<int>>> mp;
  

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<pair<TreeNode*, pair<int,int>>> q;

        q.push({root, {0,0}});

        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            auto node = it.first;
            int col = it.second.first;
            int level = it.second.second;

            mp[col][level].insert(node->val);

            if(node->left) {
                q.push({node->left, {col - 1, level + 1}});
            }

            if(node->right) {
                q.push({node->right, {col + 1, level + 1}});
            }
        }
       
       for(auto &[col, levelMap] : mp) {
        vector<int> colNodes;
        for(auto &[level, nodes] : levelMap) {
            colNodes.insert(colNodes.end(), nodes.begin(), nodes.end());
        }
        res.push_back(colNodes);
       }

        return res;
    }
};
