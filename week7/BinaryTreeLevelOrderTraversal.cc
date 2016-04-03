/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 // using BFS and recursive to realize 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>output;
        Gettheoutput(root,output,0);
        return output;
    }
    void Gettheoutput(TreeNode* root,vector<vector<int>>&output,int depth)
    {
        if(!root)return;
        if(depth==output.size()){
        output.push_back(vector<int>());
        }
        output[depth].push_back(root->val);
        Gettheoutput(root->left,output,depth+1);
        Gettheoutput(root->right,output,depth+1);
    
    }
};