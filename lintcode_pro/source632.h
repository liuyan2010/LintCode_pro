#include <stdio.h>
#include <iostream>  
#include <string> 
#include <exception> 
#include <stdarg.h>
#include <vector>
#include <algorithm>

using namespace std;

/*
    在二叉树中寻找值最大的节点并返回

    demo示例：TreeNode需要自己来定义，没有库函数
    使用递归来实现

    分析： 
        1、将二叉树看成1阶状态，比较root，左节点，右节点
        2、依照上述描述，进行递归操作即可 
*/

class TreeNode {
public:
    int val;
    TreeNode* left, * right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

class Solution632 {
public:
    /**
     * @param root the root of binary tree
     * @return the max node
     */
    TreeNode* maxNode(TreeNode* root) {
        // Write your code here
        //判断根节点是否为NULL
        if (root == NULL)
            return root;

        //对左子树进行遍历
        TreeNode* left = maxNode(root->left);
        //对右子树进行遍历
        TreeNode* right = maxNode(root->right);
        //比较左子树，右子树，root
        return max(root, max(left, right));
    }

    TreeNode* max(TreeNode* a, TreeNode* b) {
        if (a == NULL)
            return b;
        if (b == NULL)
            return a;
        if (a->val > b->val) {
            return a;
        }
        return b;
    }
};