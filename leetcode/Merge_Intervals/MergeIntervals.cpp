/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    bool is_joint(const Interval& a, const Interval& b){
        if(a.end < b.start) return false;
        if(a.start > b.end) return false;
        return true;
    }
    
    static bool cmp(const Interval& a, const Interval& b){
        return a.start < b.start;
    }
    
    vector<Interval> merge(vector<Interval>& intervals) {
        int n = intervals.size();
        if(n <= 1) return intervals;
        vector<Interval> ans;
        sort(intervals.begin(), intervals.end(), Solution::cmp);
        ans.push_back(intervals[0]);
        for(int i = 1; i < n; ++i){
            if(is_joint(intervals[i], ans.back())){
                ans[ans.size()-1].start = min(intervals[i].start, ans.back().start);
                ans[ans.size()-1].end = max(intervals[i].end, ans.back().end);
            }else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
