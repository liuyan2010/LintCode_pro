#include <stdio.h>
#include <iostream>  
#include <string> 
#include <exception> 
#include <stdarg.h>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

/*
    ����һ��Դ�ַ���sourceString��һ��Ŀ���ַ�������targetStrings���ж�Ŀ���ַ��������е�ÿһ���ַ����Ƿ���Դ�ַ������Ӵ�

    demodemo����ʾ����
        Solution255 sol;
        vector<bool> result;

        string source = "abc";
        vector<string> targetStr;
        targetStr.push_back("ab");
        targetStr.push_back("cd");

        result = sol.whetherStringsAreSubstrings(source, targetStr);
*/

class Solution255 {
public:
    /**
     * @param sourceString: a string
     * @param targetStrings: a string array
     * @return: Returns a bool array indicating whether each string in targetStrings is a substring of the sourceString
     */
    vector<bool> whetherStringsAreSubstrings(string& sourceString, vector<string>& targetStrings) {
        // write your code here
        vector<bool> result;

        int length = targetStrings.size();

        for (int i = 0; i < length; i++) {

            int n = sourceString.find(targetStrings[i]);

            cout << "string =" << targetStrings[i] << " n=" << n << endl;

            if ((n != string::npos)) {
                result.push_back(true);
            }
            else {
                result.push_back(false);
            }
        }

        return result;
    }
};
