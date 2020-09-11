#include <stdio.h>
#include <iostream>  
#include <string> 
#include <exception> 
#include <stdarg.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

/*
*       给定一个未排序的整数数组，找到其中位数
*       分析：使用优先队列priority_queue实现
            1、 中位数的位置
            2、 依次向队列填充数据，当填满后开始比较，入队出队操作
            3、 遍历完成之后，将队头元素取出即可
*/

class Solution80 {
public:
    /**
        * @param nums: A list of integers
        * @return: An integer denotes the middle number of the array
        */
    int median(vector<int>& nums) {
        // write your code here
        int size = nums.size();
        priority_queue<int> queue;
        int pos = (size + 1) / 2;

        for (int i = 0; i < size; i++) {

            if (queue.size() == pos) {
                if (queue.top() > nums[i]) {
                    queue.pop();
                    queue.push(nums[i]);
                }
            }
            else {
                queue.push(nums[i]);
            }
        }

        return queue.top();
    }
};
