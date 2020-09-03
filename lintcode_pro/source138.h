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
        ����һ���������飬�ҵ���Ϊ0�������顣�������������ʼλ�úͽ���λ��

        ������ʹ��hash������ά��ǰ׺����ʵ�֡��Ż�ʱ�临�Ӷȣ����Ч��
        1. ����һ�����ͱ���sum��¼��ǰ��ǰ׺�ͣ�����һ��hash��hash[sum]=i��ʾsum���ֵ�ǵ�i��λ�õ�ǰ׺��
        2. ��ʼ����sum = 0�� hash[0] = -1;(�ö����������-1��λ��ֵΪ0)
        3. ѭ����������������飬���ڵ�ǰλ��i���������²�����
            sum�ۼӣ� ��hash����Ѱ��sum���ҵ��򷵻�����ֵ������������hash[sum] = i����������
        
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
