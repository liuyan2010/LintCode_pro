#include <stdio.h>
#include <iostream>  
#include <string> 
#include <exception> 
#include <stdarg.h> 

using namespace std;

/*
    ��תһ��ֻ��3λ��������
    <���Լ�������һ����һ��ֻ����λ��������������������ڵ���100��С��1000>

    demo����ʾ����
        Solution37 sol;
        int res;
        res = sol.reverseInteger(123);
*/

class Solution37 {
public:
    /**
     * @param number: A 3-digit number.
     * @return: Reversed number.
     */
    int reverseInteger(int number) {
        // write your code here
        int a[3] = { 100, 10, 1 };
        int p;
        int result = 0;

        for (int i = 0; i < 3; i++) {
            p = number % 10;
            result += p * a[i];
            number = number / 10;
        }
        return result;
    }
};
