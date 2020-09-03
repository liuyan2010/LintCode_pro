#include <stdio.h>
#include <iostream>  
#include <string> 
#include <exception> 
#include <stdarg.h>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
        给定一个整数数组，找到和为0的子数组。返回子数组的起始位置和结束位置

        分析：使用hash表，利用维护前缀和来实现。优化时间复杂度，提高效率
        1. 定义一个整型变量sum记录当前的前缀和，定义一个hash表，hash[sum]=i表示sum这个值是第i个位置的前缀和
        2. 初始化：sum = 0， hash[0] = -1;(该定义代表数组-1的位置值为0)
        3. 循环遍历这个整数数组，对于当前位置i，进行如下操作：
            sum累加， 到hash里面寻找sum，找到则返回区间值，结束；否则hash[sum] = i，继续查找
        
*/

class Solution138 {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> subarraySum(vector<int>& nums) {
        // write your code here
        unordered_map<int, int> hash;
        vector<int> result;
        int sum = 0;
        int size = nums.size();

        hash[0] = -1;

        for (int i = 0; i < size; i++) {
            sum += nums[i];
            if (hash.find(sum) != hash.end()) {
                result.push_back(hash[sum] + 1);
                result.push_back(i);
            }
            hash[sum] = i;
        }

        return result;
    }
};
