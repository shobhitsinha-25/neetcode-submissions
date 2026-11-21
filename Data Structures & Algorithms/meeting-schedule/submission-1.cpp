/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.size()==0) return true;
        sort(intervals.begin(), intervals.end(),
             [](Interval& a, Interval& b) {
                 return a.start < b.start;
             });

        int laststart=intervals[0].start;
        int lastend=intervals[0].end;

        for(int i=1;i<intervals.size();i++)
        {
            int currstart=intervals[i].start;
            int currend=intervals[i].end;
            if(currstart<lastend) return false;
            else{
                laststart=currstart;
                lastend=currend;
            }
        }
        return true;
    }
};
