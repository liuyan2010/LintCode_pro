#include <stdio.h>
#include <iostream>  
#include <string> 
#include <exception> 
#include <stdarg.h>
#include <vector>
#include <algorithm>

using namespace std;

/*
     ����һ���������飬�ҵ�һ���������͵������飬���������͡�

     result:���ս��  <ÿ����sum���Ƚ�>
     sum����ǰ�ۼӵ����ֵ����С��0ʱ�����й��㡣
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
