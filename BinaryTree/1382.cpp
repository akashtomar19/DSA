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
    TreeNode* prev = NULL;
    TreeNode* f = NULL;
    void solve(TreeNode* root){
        if(!root)return;
        solve(root->left);
        auto temp = root->right;
        root->left = NULL;
        if(!prev)prev = root, f = root;
        else prev->right = root;
        prev = root;
        solve(temp);
    }
    // void s(TreeNode* root){
    //     if(root == NULL)return;
    //     if(root == NULL)exit(0);
    //     cout<<root->val<<endl;
    //     s(root->left);
        
    //     s(root->right);
    // }
    TreeNode* bal(TreeNode* root){
        if(!root)return NULL;
        if(!root->right)return root;
        //
        auto slow = root, fast = root;
        TreeNode* pr = NULL;
        while(slow and fast and fast->right){
            pr = slow;
            slow=slow->right;
            fast = fast->right->right;
        }
        pr->right = NULL;
        slow->left = bal(root);
        slow->right = bal(slow->right);
        return slow;
    }
    TreeNode* balanceBST(TreeNode* root) {
        solve(root);
        return bal(f);
        return NULL;
    }
};

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
    vector<TreeNode*>inorder;
    void inorderTraversal(TreeNode* root){
        if(root == NULL)return;
        inorderTraversal(root->left);
        inorder.push_back(root);
        inorderTraversal(root->right);
    }
    TreeNode* solve(int l, int r){
        cout<<l<<" "<<r<<endl;
        if(l > r)return NULL;
        
        int mid = (l + r) / 2;
        auto root = inorder[mid];
        root->left = solve(l, mid - 1);
        root->right = solve(mid + 1, r);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorderTraversal(root);
        return solve(0, (int)inorder.size() - 1);
    }
};