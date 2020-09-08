#include <stdio.h>
#include <iostream>  
#include <string> 
#include <exception> 
#include <stdarg.h>
#include <vector>

using namespace std;

/*
        给定一个数字列表，返回其所有可能的排列。
        分析：
            使用DFS算法实现，深度优先搜索
            1. 原数组nums，依次遍历取数放到current开头位置，已经被使用的数据标记为used=true
            2. 递归使用dfs搜索
            3. 搜索时，当current被放入的数据==nums.size时，将结果存储即可

        原数组为空时，返回空即可！
*/

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int> > permute(vector<int> nums) {
        vector<vector<int> > results;

        // 如果数组为空直接返回空
        if (nums.size() == 0) {
            results.push_back(vector<int>());
            return results;
        }

        // dfs操作
        vector<bool> used(nums.size(), 0);
        vector<int> current;
        dfs(nums, used, current, results);

        return results;
    }

    void dfs(vector<int> nums, vector<bool>& used, vector<int>& current, vector<vector<int>>& results) {
        //找到一组排列，已到达边界条件
        if (current.size() == nums.size()) {
            results.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            // i位置这个元素已经被用过
            if (used[i]) {
                continue;
            }

            //继续递归
            current.push_back(nums[i]);
            used[i] = true;
            dfs(nums, used, current, results);
            used[i] = false;
            current.pop_back();
        }
    }
};