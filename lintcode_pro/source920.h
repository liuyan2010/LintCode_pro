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
    ����һϵ�еĻ���ʱ������������ʼ�ͽ���ʱ��[[s1,e1]��[s2,e2]����(si < ei)��ȷ��һ�����Ƿ���Բμ����л��顣

    ������
        1. ���ݻ���ʱ�����start���������������
        2. �����һ����startС��ǰһ����end���򷵻�false
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
        return v1.start < v2.start;//��������
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
        // Write your code here
        //���������
        sort(intervals.begin(), intervals.end(), cmp);

        //ά���յ�����ֵ
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
