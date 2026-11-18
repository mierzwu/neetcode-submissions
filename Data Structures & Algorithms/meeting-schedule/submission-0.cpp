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
        vector<pair<int,int>>calendar;
        pair<int,int>meeting;
        for(int i=0; i<intervals.size();i++){
            meeting = {intervals[i].start,intervals[i].end};
            calendar.push_back(meeting);
        }
        sort(calendar.begin(), calendar.end());
        for(int i=1; i<calendar.size();i++){
            if(calendar[i].first<calendar[i-1].second) return false;
        }
        return true;
    }
};
