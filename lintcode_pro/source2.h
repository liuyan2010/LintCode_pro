#include <stdio.h>
#include <iostream>  
#include <string> 
#include <exception> 
#include <stdarg.h> 

using namespace std;

/*
    ���һ���㷨�������n�׳���β����ĸ���

    ��Ҫ��Ѱ��5�ĸ���������ĳ�������Ƚϴ������ʱ��ʱ�临�Ӷ�̫��
    �������̣�
        long long sum = 0;
        while (n != 0) {
            sum += n / 5;
            n /= 5;
        }
        return sum;

    demo����ʾ����
        Solution2 sol;
        long long number = 1001171717;
        long long res;

        res = sol.trailingZeros(number);

        cout << res;
*/

class Solution2 {
public:
    /*
     * @param n: A long integer
     * @return: An integer, denote the number of trailing zeros in n!
     */
    long long trailingZeros(long long n) {
        // write your code here, try to do it without arithmetic operators.
        long long result = 0;
        long long num;

        for (long long i = 1; i <= n; i++) {
            num = i;
            while (num % 5 == 0) {
                result++;
                num = num / 5;
            }
        }
        return result;
    }
};
