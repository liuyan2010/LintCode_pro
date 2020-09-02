#include <stdio.h>
#include <iostream>  
#include <string> 
#include <exception> 
#include <stdarg.h>
#include <vector>
#include <algorithm>

using namespace std;


/*
        Dp(动态规划) ： 给定一个只含非负整数的m*n网格，找到一条从左上角到右下角的可以使数字和最小的路径

        思想： grid[i][j]代表节点值， f[i][j]代表从 (0,0)到(i,j)的最短路径
               f[0][0] = grid[0][0];
               f[i][0] = f[i - 1][0] + grid[i][0];
               f[0][i] = f[0][i - 1] + grid[0][i];

               f[i][j] = min(f[i - 1][j], f[i][j - 1]) + grid[i][j];  
               当i=m-1, j=n-1时，即为结果
*/

class Solution110 {
public:
    /**
     * @param grid: a list of lists of integers
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int>>& grid) {
        // write your code here

        if ((grid.size() == 0) || (grid[0].size() == 0))
            return 0;

        int m = grid.size();
        int n = grid[0].size();

        int f[1000][1000];

        f[0][0] = grid[0][0];

        for (int i = 1; i < m; i++) {
            f[i][0] = f[i - 1][0] + grid[i][0];
        }

        for (int i = 1; i < n; i++) {
            f[0][i] = f[0][i - 1] + grid[0][i];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                f[i][j] = min(f[i - 1][j], f[i][j - 1]) + grid[i][j];
            }
        }

        return f[m - 1][n - 1];
    }
};