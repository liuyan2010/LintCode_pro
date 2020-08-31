#include <stdio.h>
#include <iostream>  
#include <string> 
#include <exception> 
#include <stdarg.h>
#include <vector>
#include <algorithm>

using namespace std;

/*
    �ڶ�������Ѱ��ֵ���Ľڵ㲢����

    demoʾ����TreeNode��Ҫ�Լ������壬û�п⺯��
    ʹ�õݹ���ʵ��

    ������ 
        1��������������1��״̬���Ƚ�root����ڵ㣬�ҽڵ�
        2�������������������еݹ�������� 
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
        //�жϸ��ڵ��Ƿ�ΪNULL
        if (root == NULL)
            return root;

        //�����������б���
        TreeNode* left = maxNode(root->left);
        //�����������б���
        TreeNode* right = maxNode(root->right);
        //�Ƚ�����������������root
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