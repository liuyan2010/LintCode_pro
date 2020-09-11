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
*       ����һ��δ������������飬�ҵ�����λ��
*       ������ʹ�����ȶ���priority_queueʵ��
            1�� ��λ����λ��
            2�� ���������������ݣ���������ʼ�Ƚϣ���ӳ��Ӳ���
            3�� �������֮�󣬽���ͷԪ��ȡ������
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
