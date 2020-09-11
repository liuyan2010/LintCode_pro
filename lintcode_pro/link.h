#include <stdio.h>
#include <iostream>  
#include <string> 
#include <exception> 
#include <stdarg.h>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class LinkNode {
public:
    int val;
    LinkNode* next;
    LinkNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};


class LinkSolution {
public:
    /**
     *  计算链表中有多少个节点
     */
    int countNodes(LinkNode* head);
    /**
    *  翻转一个链表
    */
    LinkNode* reverse(LinkNode* head);
};

int LinkSolution::countNodes(LinkNode* head) {
    int res = 0;

    while (head != NULL) {
        res++;
        head = head->next;
    }
    return res;
}

LinkNode* LinkSolution::reverse(LinkNode* head) {
    // write your code here
    LinkNode* prev = NULL;

    while (head != NULL) {
        LinkNode* temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }
    return prev;
}
