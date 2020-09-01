#include <stdio.h>
#include <iostream>  
#include <string> 
#include <exception> 
#include <stdarg.h>
#include <vector>
#include <algorithm>

using namespace std;

/*
    ��תһ����������node����prev,cur,last; ����������

*/

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class Solution35 {
public:
    /**
     * @param head: n
     * @return: The new head of reversed linked list.
     */
    ListNode* reverse(ListNode* head) {
        // write your code here
        ListNode* prev = NULL;

        while (head != NULL) {
            ListNode* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
};
