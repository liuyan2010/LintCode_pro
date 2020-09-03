#include <stdio.h>
#include <iostream>  
#include <string> 
#include <exception> 
#include <stdarg.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack> 

using namespace std;

/*
        ����һ��ֻ����'(' ��')'���ַ������ҳ������������������ȷƥ��ĺϷ��Ӵ�
        Dp��̬�滮ʵ�֣�
           1. dp[i]��ʾ��i��ͷ����Ϸ��Ӵ����ȣ���ʼ�� dp[length] = 0;
           2. dp[i]���Ϊ����������dp[i]Ϊ0
              dp[i]���Ϊ��( �����ҵ� i+dp[i+1]+1 �Ƿ�Ϊ���������������dp[i] = 0;�����
                dp[i] = dp[i+1] + 2 +dp[j+1]
           
           �ҵ�����dp[]��������
*/

class Solution {
public:
    /**
     * @param s: a string
     * @return: return a integer
     */
    int longestValidParentheses(string& s) {
        // write your code here
        if (s.size() <= 1)
            return 0;
        int res = 0;
        //dp[i]��ʾ��i��ͷ����Ϸ��Ӵ����ȣ���ʼ��Ϊ0
        vector<int> dp(s.size(), 0);

        for (int i = s.size() - 2; i >= 0; i--)
        {
            if (s[i] == '(')				//���s[i] = '('������Ҫ�ҵ������ź���ƥ�䣬����������i + 1��ͷ�ĺϷ��Ӵ�������Ҫ��j = i + dp[i + 1] + 1�Ƿ�Ϊ������
            {
                int j = i + dp[i+1] + 1;
                if (s[j] == ')' && j < s.size())	//���ûԽ����Ϊ������
                {
                    dp[i] = dp[i+1] + 2;
                    if (j+1 < s.size())  //��Ҫ��j + 1��ͷ���Ӵ��ӽ���
                        dp[i] += dp[j+1];
                }
                res = max(res, dp[i]);
            }
        }
        return res;
    }
};
