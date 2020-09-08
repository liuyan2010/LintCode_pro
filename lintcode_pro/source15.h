#include <stdio.h>
#include <iostream>  
#include <string> 
#include <exception> 
#include <stdarg.h>
#include <vector>

using namespace std;

/*
        ����һ�������б����������п��ܵ����С�
        ������
            ʹ��DFS�㷨ʵ�֣������������
            1. ԭ����nums�����α���ȡ���ŵ�current��ͷλ�ã��Ѿ���ʹ�õ����ݱ��Ϊused=true
            2. �ݹ�ʹ��dfs����
            3. ����ʱ����current�����������==nums.sizeʱ��������洢����

        ԭ����Ϊ��ʱ�����ؿռ��ɣ�
*/

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int> > permute(vector<int> nums) {
        vector<vector<int> > results;

        // �������Ϊ��ֱ�ӷ��ؿ�
        if (nums.size() == 0) {
            results.push_back(vector<int>());
            return results;
        }

        // dfs����
        vector<bool> used(nums.size(), 0);
        vector<int> current;
        dfs(nums, used, current, results);

        return results;
    }

    void dfs(vector<int> nums, vector<bool>& used, vector<int>& current, vector<vector<int>>& results) {
        //�ҵ�һ�����У��ѵ���߽�����
        if (current.size() == nums.size()) {
            results.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            // iλ�����Ԫ���Ѿ����ù�
            if (used[i]) {
                continue;
            }

            //�����ݹ�
            current.push_back(nums[i]);
            used[i] = true;
            dfs(nums, used, current, results);
            used[i] = false;
            current.pop_back();
        }
    }
};