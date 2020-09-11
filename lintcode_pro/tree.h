#include <stdio.h>
#include <iostream>  
#include <string> 
#include <exception> 
#include <stdarg.h>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

/* define a tree class */
class TreeNode {
public:
    int val;
    TreeNode* left, * right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};


class Tree {
public:
    /*
     * 插入一个节点到二叉树中
     * 二叉树特性：left<root<right
     */
    TreeNode* insertNode(TreeNode* root, TreeNode* node);

    /*
    * 前序遍历(前根序遍历) ： 先遍历root，再遍历left，再遍历right
    */
    vector<int> preorderTraversal(TreeNode* root);
    void traversePrev(TreeNode* root, vector<int>& result);

    /*
    * 中序遍历(前根序遍历) ： 先遍历left，再遍历root，再遍历right
    */
    vector<int> inorderTraversal(TreeNode* root);
    void traverseNorder(TreeNode* root, vector<int>& result);

    /*
    * 后续遍历(前根序遍历) ： 先遍历left，再遍历right，再遍历root
    */
    vector<int> postorderTraversal(TreeNode* root);
    void traversePostorder(TreeNode* root, vector<int>& result);

    /*
    * 层次遍历(前根序遍历) ： 按照层次依次遍历
    */
    vector<vector<int>> levelOrder(TreeNode* root);
    void buildVector(TreeNode* root, int depth, vector<vector<int>>& res);

    /*
    * 在二叉树中寻找值最大的节点并返回
    */
    TreeNode* maxNode(TreeNode* root);
    TreeNode* max(TreeNode* a, TreeNode* b);


};

TreeNode* Tree::insertNode(TreeNode* root, TreeNode* node) {
    //如果为NULL，返回node
    if (root == NULL) {
        return node;
    }
    //当node<root,遍历左子树；否则遍历右子树
    if (node->val < root->val) {
        root->left = insertNode(root->left, node);
    }
    else {
        root->right = insertNode(root->right, node);
    }

    return root;
}

vector<int> Tree::preorderTraversal(TreeNode* root) {
    vector<int> res(0);
    traversePrev(root, res);

    return res;
}

void Tree::traversePrev(TreeNode* root, vector<int>& result) {
    if (root == NULL) {
        return;
    }
    result.push_back(root->val);        //遍历root
    traversePrev(root->left, result);   //遍历左子树
    traversePrev(root->right, result);  //遍历右子树
}

vector<int> Tree::inorderTraversal(TreeNode* root) {
    // write your code here
    vector<int> result(0);
    traverseNorder(root, result);

    return result;
}

void Tree::traverseNorder(TreeNode* root, vector<int>& result) {
    if (root == NULL) {
        return;
    }
    traverseNorder(root->left, result);    //遍历左子树
    result.push_back(root->val);            //遍历root
    traverseNorder(root->right, result);   //遍历右子树
}

vector<int> Tree::postorderTraversal(TreeNode* root) {
    // write your code here
    vector<int> result(0);
    traversePostorder(root, result);

    return result;
}

void Tree::traversePostorder(TreeNode* root, vector<int>& result) {
    if (root == NULL) {
        return;
    }
    traversePostorder(root->left, result);    //遍历左子树
    traversePostorder(root->right, result);   //遍历右子树
    result.push_back(root->val);            //遍历root
}

vector<vector<int>> Tree::levelOrder(TreeNode* root) {
    vector<vector<int>> res(0);      //二维的vector
    buildVector(root, 0, res);       //开始遍历
    return res;
}

void Tree::buildVector(TreeNode* root, int depth, vector<vector<int>>& res) {
    if (root == NULL)
        return;

    //每一层遍历之前,创建一个vector<int>()
    if (depth == res.size())
        res.push_back(vector<int>());

    res[depth].push_back(root->val);            //遍历root这一层的数据<区别与先序遍历>
    buildVector(root->left, depth + 1, res);    //遍历左子树
    buildVector(root->right, depth + 1, res);   //遍历右子树
}

TreeNode* Tree::maxNode(TreeNode* root) {
    TreeNode* result;

    if (root == NULL)
        return root;

    result = root;

    TreeNode* left = maxNode(root->left);
    TreeNode* right = maxNode(root->right);

    result = max(left, right);
    result = max(result, root);
}

TreeNode* Tree::max(TreeNode* a, TreeNode* b) {
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    if (a->val > b->val)
        return a;
    else
        return b;
}
