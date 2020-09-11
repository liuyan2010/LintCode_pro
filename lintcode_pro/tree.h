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
     * ����һ���ڵ㵽��������
     * ���������ԣ�left<root<right
     */
    TreeNode* insertNode(TreeNode* root, TreeNode* node);

    /*
    * ǰ�����(ǰ�������) �� �ȱ���root���ٱ���left���ٱ���right
    */
    vector<int> preorderTraversal(TreeNode* root);
    void traversePrev(TreeNode* root, vector<int>& result);

    /*
    * �������(ǰ�������) �� �ȱ���left���ٱ���root���ٱ���right
    */
    vector<int> inorderTraversal(TreeNode* root);
    void traverseNorder(TreeNode* root, vector<int>& result);

    /*
    * ��������(ǰ�������) �� �ȱ���left���ٱ���right���ٱ���root
    */
    vector<int> postorderTraversal(TreeNode* root);
    void traversePostorder(TreeNode* root, vector<int>& result);

    /*
    * ��α���(ǰ�������) �� ���ղ�����α���
    */
    vector<vector<int>> levelOrder(TreeNode* root);
    void buildVector(TreeNode* root, int depth, vector<vector<int>>& res);

    /*
    * �ڶ�������Ѱ��ֵ���Ľڵ㲢����
    */
    TreeNode* maxNode(TreeNode* root);
    TreeNode* max(TreeNode* a, TreeNode* b);


};

TreeNode* Tree::insertNode(TreeNode* root, TreeNode* node) {
    //���ΪNULL������node
    if (root == NULL) {
        return node;
    }
    //��node<root,�������������������������
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
    result.push_back(root->val);        //����root
    traversePrev(root->left, result);   //����������
    traversePrev(root->right, result);  //����������
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
    traverseNorder(root->left, result);    //����������
    result.push_back(root->val);            //����root
    traverseNorder(root->right, result);   //����������
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
    traversePostorder(root->left, result);    //����������
    traversePostorder(root->right, result);   //����������
    result.push_back(root->val);            //����root
}

vector<vector<int>> Tree::levelOrder(TreeNode* root) {
    vector<vector<int>> res(0);      //��ά��vector
    buildVector(root, 0, res);       //��ʼ����
    return res;
}

void Tree::buildVector(TreeNode* root, int depth, vector<vector<int>>& res) {
    if (root == NULL)
        return;

    //ÿһ�����֮ǰ,����һ��vector<int>()
    if (depth == res.size())
        res.push_back(vector<int>());

    res[depth].push_back(root->val);            //����root��һ�������<�������������>
    buildVector(root->left, depth + 1, res);    //����������
    buildVector(root->right, depth + 1, res);   //����������
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
