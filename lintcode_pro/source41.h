#include <stdio.h>
#include <iostream>  
#include <string> 
#include <exception> 
#include <stdarg.h>
#include <vector>
#include <algorithm>

using namespace std;

/*
     给定一个整数数组，找到一个具有最大和的子数组，返回其最大和。

     result:最终结果  <每次与sum做比较>
     sum：当前累加的最大值，当小于0时，进行归零。
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int>& nums) {
        // write your code here
        int result = INT_MIN;
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {

            sum = sum + nums[i];
            result = max(sum, result);
            sum = max(sum, 0);
        }

        return result;
    }
};
