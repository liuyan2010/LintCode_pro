#include <stdio.h>
#include <iostream>  
#include <string> 
#include <exception> 
#include <stdarg.h>
#include <vector>
#include <algorithm>

using namespace std;

/*
     给定一个整型数组，找出主元素，它在数组中的出现次数严格大于数组元素个数的二分之一

     思考： 使用count计数，相同++不同--。 主要思想是：因为众数超过总数的一半，所以不会被减到0以下
            1. 先给数组排序，依次遍历后找到count>0时的数
            2. 再次遍历，确认这个数超过了一半
*/

class Solution46 {
public:
    /*
     * @param nums: a list of integers
     * @return: find a  majority number
     */
    int majorityNumber(vector<int>& nums) {
        // write your code here
        int count = 0;
        int data;

        sort(nums.begin(), nums.end());

        data = nums[0];

        for (int i = 0; i < nums.size(); i++) {

            if (data == nums[i]) {
                count++;
            }
            else {
                count--;
            }

            if (count == 0) {
                data = nums[i];
                count++;
            }
        }
        count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (data == nums[i])
                count++;
        }

        if (count > nums.size() / 2)
            return data;

        return -1;
    }
};


