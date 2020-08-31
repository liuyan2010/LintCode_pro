#include <stdio.h>
#include <iostream>  
#include <string> 
#include <exception> 
#include <stdarg.h> 

using namespace std;


/*
    给定一个字符串（以字符数组的形式给出）和一个偏移量，根据偏移量原地旋转字符串(从左向右旋转)

    输入:  str="abcdefg", offset = 3
    输出:  str = "efgabcd"
    样例解释:  注意是原地旋转，即str旋转后为"efgabcd"

    输入: str="abcdefg", offset = 10
    输出: str = "efgabcd"
    样例解释: 注意是原地旋转，即str旋转后为"efgabcd"

    demo测试示例：
        Solution8 sol;
        string str = "hello world";
        sol.rotateString(str, 5);
        cout << str << endl;

*/

class Solution8 {
public:
    /**
     * @param str: An array of char
     * @param offset: An integer
     * @return: nothing
     */
    void rotateString(string& str, int offset) {
        // write your code here
        int length = str.size();

        if (length == 0)
            return;

        offset = offset % length;

        str = str.substr(length - offset, offset) +
            str.substr(0, length - offset);

    }
};
