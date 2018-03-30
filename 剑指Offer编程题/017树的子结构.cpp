// 题目描述
// 输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {

    }
};

//思路

class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1==nullptr || pRoot2==nullptr)
            return false;
        if(pRoot1->val==pRoot2->val)//先找到根相等的
        {
            if(IsSub(pRoot1,pRoot2))//然后判断这个根下面的子树是否相等
                return true;
        }
        //先去左子树找，再去右子树找
        return HasSubtree(pRoot1->left,pRoot2) || HasSubtree(pRoot1->right,pRoot2);
    }
    
    bool IsSub(TreeNode* p1,TreeNode* p2)
    {
        if(p2==nullptr)
            return true;
        if(p1==nullptr)
            return false;
        if(p1->val!=p2->val)
            return false;
        //左右子树必须严格匹配
        return IsSub(p1->left,p2->left) && IsSub(p1->right,p2->right);
    }
};






















