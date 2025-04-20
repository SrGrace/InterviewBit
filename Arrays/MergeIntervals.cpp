/*

https://www.interviewbit.com/problems/merge-intervals/



Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Given intervals [1,3],[6,9] insert and merge [2,5] would result in [1,5],[6,9].

Example 2:

Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] would result in [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

Make sure the returned intervals are also sorted.

*/




/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
 
bool cmp(const Interval &a, const Interval &b){
        return (a.start < b.start);
}

vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<Interval> res;
    
    intervals.push_back(newInterval);
    
    if (intervals.size() == 0)
    {
        return res;
    }
    
    std::sort(intervals.begin(), intervals.end(),cmp);
    
    res.push_back(intervals[0]);
    
    for (int i=1; i<intervals.size(); i++)
    {
        if (res.back().end >= intervals[i].start)
        {
            res.back().end = max(res.back().end, intervals[i].end);
        }
        
        else
        {
            res.push_back(intervals[i]);
        }   
    }   
    
    return res; // O(nlogn), O(n)
    
}

