#include <stdio.h>
#include <iostream>  
#include <string> 
#include <exception> 
#include <stdarg.h>
#include <vector>
#include <algorithm>

using namespace std;

/*
    数组剔除元素后的乘积

    给定一个整数数组A。定义B[i] = A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]， 计算B的时候请不要使用除法。
    方法：
        1. 从后往前遍历一次，f[i] 表示i之后的乘积
        2. 从前往后遍历，p[i]表示i之前的乘积。 B[i] = f[i] * p[i]

        demo测试示例：
            Solution50 sol;

            vector<int> nums(5);

            nums[0] = 1;
            nums[1] = 2;
            nums[2] = 3;
            nums[3] = 4;
            nums[4] = 5;

            sol.productExcludeItself(nums);

*/
class Solution50 {
public:
    /*
        * @param nums: Given an integers array A
        * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
        */
    vector<long long> productExcludeItself(vector<int>& nums) {
        // write your code here

        vector<long long> result;

        int length = nums.size() - 1;

        //特殊考虑只有一个元素的情况
        if (length == 0) {
            result.push_back(1);
            return result;
        }

        vector<long long> f(length + 1);

        f[length] = 1;

        for (int i = length - 1; i >= 0; i--) {
            f[i] = f[i + 1] * nums[i + 1];
        }

        vector<long long> p(length + 1);
        p[0] = 1;
        result.push_back(p[0] * f[0]);

        for (int i = 1; i <= length; i++) {
            p[i] = p[i - 1] * nums[i - 1];

            result.push_back(p[i] * f[i]);
        }

        return result;

    }
};
