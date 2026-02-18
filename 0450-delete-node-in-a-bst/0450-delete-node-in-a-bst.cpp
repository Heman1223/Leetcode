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
    private:
        TreeNode* minvalue(TreeNode* root){
            TreeNode* temp = root;
            while(temp->left != NULL){
                temp = temp->left;
            }
            return temp;
        }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return NULL;
        }
        if(root->val == key){
            if(root->right == NULL && root->left == NULL){
                delete root;
                return NULL;
            }
            if(root->right != NULL && root->left == NULL){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            if(root->right == NULL && root->left != NULL){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            if(root->right != NULL && root->left != NULL){
                int min = minvalue(root->right)->val;
                root->val = min;
                root->right = deleteNode(root->right,min);
                return root;
            }
        }else if(root->val > key){
            root->left = deleteNode(root->left,key);
            return root;
        }else{
            root->right = deleteNode(root->right,key);
            return root;
        }
        return root;
    }
};