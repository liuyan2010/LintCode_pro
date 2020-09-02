#include <stdio.h>
#include <iostream>  
#include <string> 
#include <exception> 
#include <stdarg.h>
#include <vector>
#include <algorithm>

using namespace std;

/*
    �����޳�Ԫ�غ�ĳ˻�

    ����һ����������A������B[i] = A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]�� ����B��ʱ���벻Ҫʹ�ó�����
    ������
        1. �Ӻ���ǰ����һ�Σ�f[i] ��ʾi֮��ĳ˻�
        2. ��ǰ���������p[i]��ʾi֮ǰ�ĳ˻��� B[i] = f[i] * p[i]

        demo����ʾ����
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

        //���⿼��ֻ��һ��Ԫ�ص����
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
