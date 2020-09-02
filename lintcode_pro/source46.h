#include <stdio.h>
#include <iostream>  
#include <string> 
#include <exception> 
#include <stdarg.h>
#include <vector>
#include <algorithm>

using namespace std;

/*
     ����һ���������飬�ҳ���Ԫ�أ����������еĳ��ִ����ϸ��������Ԫ�ظ����Ķ���֮һ

     ˼���� ʹ��count��������ͬ++��ͬ--�� ��Ҫ˼���ǣ���Ϊ��������������һ�룬���Բ��ᱻ����0����
            1. �ȸ������������α������ҵ�count>0ʱ����
            2. �ٴα�����ȷ�������������һ��
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


