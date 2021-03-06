/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
//Recursive
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        else
            return ok(root->left,root->right);
    }
    bool ok(TreeNode* r1,TreeNode* r2){
        if(r1==NULL&&r2==NULL) return true;
        if(r1&&r2&&r1->val==r2->val)
            return ok(r1->right,r2->left)&&ok(r1->left,r2->right);
        else
            return false;
    }
};

//BFS
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        bool ret=true;
        TreeNode* v[9000];
        int fr=0,ta=2;
        v[0]=root;v[1]=root;
        while(fr!=ta){
            TreeNode* now1=v[fr++];
            TreeNode* now2=v[fr++];
            if(!now1&&!now2) 
                continue;
            if(now1==NULL||now2==NULL||now1->val!=now2->val)
                return false;
            v[ta++]=now1->left;
            v[ta++]=now2->right;
            v[ta++]=now1->right;
            v[ta++]=now2->left;
        }
        return ret;
    }

};