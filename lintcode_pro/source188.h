#include <stdio.h>
#include <iostream>  
#include <string> 
#include <exception> 
#include <stdarg.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack> 

using namespace std;

/*
        ����һ�����֣������ֵ�����λ�ò���һ��5��ʹ�ò���������������
        1. ������ת����string
        2. �ж��������������Ǹ������ҵ���5��Ҫ�����λ��
        3. �����ַ���

        ע�⣺ �÷��������ͨ���������Ӵ���ת����ʵ�������յĽ����

        demo����ʾ����
                Solution188 sol;
                int result;

                result = sol.InsertFive(234);
                result = sol.InsertFive(4937);
                result = sol.InsertFive(-4937);
*/

#define NUMBER_INSERT 5

class Solution188 {
public:
    /**
     * @param a: A number
     * @return: Returns the maximum number after insertion
     */
    int InsertFive(int a) {
        // write your code here
        string str_a = to_string(a);
        int result = 0;
        int length = str_a.length();

        int pos = -1;
        if (a >= 0) {
            for (int i = 0; i < length; i++) {
                if (str_a[i] < '5') {
                    pos = i;
                    break;
                }
            }
        }
        else {
            for (int i = 1; i < length; i++) {
                if (str_a[i] >= '5') {
                    pos = i;
                    break;
                }
            }
        }

        if (pos >= 0)
            str_a = str_a.substr(0, pos) + '5' + str_a.substr(pos, length);
        else
            str_a = str_a + '5';

        cout << "str_a=" << str_a;

        result = stoi(str_a);

        return result;
    }
};