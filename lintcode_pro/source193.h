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
        给出一个只包含'(' 和')'的字符串，找出其中最长的左右括号正确匹配的合法子串
        Dp动态规划实现：
           1. dp[i]表示以i开头的最长合法子串长度，初始化 dp[length] = 0;
           2. dp[i]如果为‘）’，则dp[i]为0
              dp[i]如果为‘( ’，找到 i+dp[i+1]+1 是否为‘）’，如果否，则dp[i] = 0;如果是
                dp[i] = dp[i+1] + 2 +dp[j+1]
           
           找到最大的dp[]，输出结果
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
        //dp[i]表示以i开头的最长合法子串长度，初始化为0
        vector<int> dp(s.size(), 0);

        for (int i = s.size() - 2; i >= 0; i--)
        {
            if (s[i] == '(')				//如果s[i] = '('，则需要找到右括号和它匹配，可以跳过以i + 1开头的合法子串，则需要看j = i + dp[i + 1] + 1是否为右括号
            {
                int j = i + dp[i+1] + 1;
                if (s[j] == ')' && j < s.size())	//如果没越界且为右括号
                {
                    dp[i] = dp[i+1] + 2;
                    if (j+1 < s.size())  //还要将j + 1开头的子串加进来
                        dp[i] += dp[j+1];
                }
                res = max(res, dp[i]);
            }
        }
        return res;
    }
};
