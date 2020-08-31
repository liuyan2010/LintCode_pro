#include <stdio.h>
#include <iostream>  
#include <string> 
#include <exception> 
#include <stdarg.h>
#include <vector>
#include <algorithm>

using namespace std;

/*
    ≈≈–Ú µœ÷£∫  øÏÀŸ≈≈–Úsort£¨√∞≈›≈≈–Ú
    demo≤‚ ‘ æ¿˝£∫
        Solution463 sol;

        vector<int> A;
        A.push_back(100);
        A.push_back(2);
        A.push_back(101);
        A.push_back(20);

        sol.sortIntegers01(A);

        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
*/

class Solution463 {
public:
    /**
     * @param A: an integer array
     * @return: nothing
     */

    //sortøÏÀŸ≈≈–Ú
    void sortIntegers(vector<int>& A) {
        // write your code here
        sort(A.begin(), A.end());
    }

    //√∞≈›≈≈–Ú
    void sortIntegers01(vector<int>& A) {
        // write your code here
        int num;
        for (int i = 0; i < A.size() - 1; i++) {
            for (int j = i+1; j < A.size(); j++) {
                if (A[i] > A[j]) {
                    num = A[i];
                    A[i] = A[j];
                    A[j] = num;
                }
            }
        }
    }
};
