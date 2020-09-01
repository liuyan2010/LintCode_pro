#include <stdio.h>
#include <iostream>  
#include <string> 
#include <exception> 
#include <stdarg.h>
#include <vector>
#include <algorithm>

using namespace std;

/*
    给定一个排序的数组（升序）和一个要查找的整数target，用二分法找到target第一次出现的下标（从0开始）

    二分法技巧： 使用while循环时，判断如下： while (begin + 1 < end) ，最后判断begin和end结果即可。

    demo测试示例：
    Solution14 sol;
    int result;

    vector<int> nums(10);
    nums[0] = 1;
    nums[1] = 4;
    nums[2] = 4;
    nums[3] = 5;
    nums[4] = 7;
    nums[5] = 7;
    nums[6] = 8;
    nums[7] = 9;
    nums[8] = 9;
    nums[9] = 10;

    result = sol.binarySearch(nums, 6);

    cout << "result= " << result << endl;
*/

class Solution14 {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target to find.
     * @return: The first position of target. Position starts from 0.
     */
    int binarySearch(vector<int>& nums, int target) {
        // write your code here

        int begin = 0;
        int end = nums.size() - 1;
        int middle;

        if ((target < nums[begin]) || (target > nums[end]))
            return -1;

        while (begin + 1 < end) {

            middle = (end + begin) / 2;

            if (target > nums[middle])
                begin = middle;
            else
                end = middle;
        }

        if (nums[begin] == target)
            return begin;

        if (nums[end] == target)
            return end;

        return -1;

    }
};
