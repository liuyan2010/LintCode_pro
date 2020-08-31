#include <stdio.h>
#include <iostream>  
#include <string> 
#include <exception> 
#include <stdarg.h> 

using namespace std;


/*
    ����һ���ַ��������ַ��������ʽ��������һ��ƫ����������ƫ����ԭ����ת�ַ���(����������ת)

    ����:  str="abcdefg", offset = 3
    ���:  str = "efgabcd"
    ��������:  ע����ԭ����ת����str��ת��Ϊ"efgabcd"

    ����: str="abcdefg", offset = 10
    ���: str = "efgabcd"
    ��������: ע����ԭ����ת����str��ת��Ϊ"efgabcd"

    demo����ʾ����
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
