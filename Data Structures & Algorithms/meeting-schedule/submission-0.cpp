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

        sort(intervals.begin(), intervals.end(),
            [](Interval& a, Interval& b) {
                return a.start < b.start;
            });

        vector<Interval> ans;

        for (auto &curr : intervals) {

            if (ans.empty() || ans.back().end <= curr.start) {
                ans.push_back(curr);
            } else {
                return false;
            }
        }

        return true;
    }
};