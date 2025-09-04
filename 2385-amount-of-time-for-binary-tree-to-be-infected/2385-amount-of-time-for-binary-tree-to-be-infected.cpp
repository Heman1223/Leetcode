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
    void parentMarker(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp->left){
                parent[temp->left] = temp;
                q.push(temp->left);
            }
            if(temp->right){
                parent[temp->right] = temp;
                q.push(temp->right);
            }
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> parent;
        parentMarker(root,parent);
        
        unordered_map<TreeNode*,bool> vis;
        queue<TreeNode*> q;
        
        q.push(root);
        TreeNode* str;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp->val == start){
                str = temp;
            }
            if(temp->left){
                parent[temp->left] = temp;
                q.push(temp->left);
            }
            if(temp->right){
                parent[temp->right] = temp;
                q.push(temp->right);
            }
        }
       
        q.push(str);
        vis[str] = true;
        int t = -1;

        while(!q.empty()){
            int size = q.size();
            for(int i = 0;i < size;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left && !vis[temp->left]){
                    q.push(temp->left);
                    vis[temp->left] = true;
                }
                if(temp->right && !vis[temp->right]){
                    q.push(temp->right);
                    vis[temp->right] = true;
                }
                if(parent[temp] && !vis[parent[temp]]){
                    q.push(parent[temp]);
                    vis[parent[temp]] = true;
                }
            }
            t++;
        }
        return t;
    }
};