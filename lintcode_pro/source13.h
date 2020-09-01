#include <stdio.h>
#include <iostream>  
#include <string> 
#include <exception> 
#include <stdarg.h>
#include <vector>
#include <algorithm>

using namespace std;

/*
    KMP�㷨ʵ�ֿռ临�Ӷ�   ʱ�临�Ӷ�O(m+n)���ռ临�Ӷ�O(n)
    �����ӣ� http://www.ruanyifeng.com/blog/2013/05/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm.html

    demo����ʾ������i��
        Solution13 sol;
        string source = "ABABCDDBCA";
        string target = "DDB";
        int res = sol.strStr(source, target);
*/

class Solution13 {
public:
    /**
     * @param source:
     * @param target:
     * @return: return the index
     */

     //KMP�㷨
    int strStr(string& source, string& target) {
        // Write your code here
        // Write your code here
        int i = 0, j = 0;
        int source_len = source.length(), target_len = target.length();
        vector<int> next(target_len+1);

        cout << source << target << source_len << target_len << endl;
        getNext(target, next);

        for (int i = 0; i <= target_len; i++) {
            cout << " " << next[i];
        }

        while (i < source_len && j < target_len)
        {
            if (j == -1 || source[i] == target[j])
            {
                i++;
                j++;
            }
            else
                j = next[j];
        }
        if (j == target_len)
            return i - j;
        else
            return -1;

        return 0;
    }

    //����next����
    void getNext(string target, vector<int>& next)
    {
        next[0] = -1;
        int i = 0, j = -1, target_len = target.length();
        while (i < target.length())
        {
            if (j == -1 || target[i] == target[j])
                next[++i] = ++j;
            else
                j = next[j];
        }
    }
};
