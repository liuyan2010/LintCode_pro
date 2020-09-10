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
    给定一系列的会议时间间隔，包括起始和结束时间[[s1,e1]，[s2,e2]，…(si < ei)，确定一个人是否可以参加所有会议。

    分析：
        1. 依据会议时间起点start，对数组进行排序。
        2. 如果后一个的start小于前一个的end，则返回false
*/

class Interval {
    public:
        int start, end;
        Interval(int start, int end) {
            this->start = start;
            this->end = end;
        }
};

class Solution920 {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: if a person could attend all meetings
     */
    static bool cmp(const Interval& v1, const Interval& v2) {
        return v1.start < v2.start;//升序排列
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
        // Write your code here
        //按起点排序
        sort(intervals.begin(), intervals.end(), cmp);

        //维护终点的最大值
        int maxend = -1;
        for (int i = 0; i < intervals.size(); i++) {
            
            if (intervals[i].start < maxend) {
                return false;
            }
            maxend = max(maxend, intervals[i].end);
        }
        return true;
    }
};
