#include <stdio.h>
#include <iostream>  
#include <string> 
#include <exception> 
#include <stdarg.h> 

using namespace std;

/*
    设计一个算法，计算出n阶乘中尾部零的个数

    主要是寻找5的个数，下面的程序当输入比较大的数据时，时间复杂度太大
    九章例程：
        long long sum = 0;
        while (n != 0) {
            sum += n / 5;
            n /= 5;
        }
        return sum;

    demo测试示例：
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
