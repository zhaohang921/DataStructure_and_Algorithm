// 题目描述
// 从上往下打印出二叉树的每个节点，同层节点从左至右打印

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

//思路：层序遍历，使用队列

class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> q;
        TreeNode* a;
        if(root==nullptr)
            return result;
        q.push(root);
        while(!q.empty())
        {
            a=q.front();
            result.push_back(a->val);
            if(a->left!=nullptr)
                q.push(a->left);
            if(a->right!=nullptr)
                q.push(a->right);
            q.pop();
        }
        return result;
    }
};
