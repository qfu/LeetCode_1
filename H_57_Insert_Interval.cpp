/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

#include <vector>
#include <iostream>
using namespace std;


struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
 };




class Solution {
public:
  	int findInterval(vector<Interval>& intervals, int val){
		for(int i = 0 ; i < intervals.size(); ++i){
			if (val >= intervals[i].start && val <= intervals[i].end) return i;
		}
		return -1;
	}



    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        //Edge case 
        if (!intervals.size()){
         intervals.push_back(newInterval);
         return intervals;
     	}

     	if(findInterval(intervals,newInterval.start) == findInterval(intervals,newInterval.end) && findInterval(intervals,newInterval.start) != -1)
     		return intervals;

     	Interval newInsert;
     	if(findInterval(intervals,newInterval.start) == -1 &&findInterval(intervals,newInterval.end) == -1 ){
     	    cout << "in1" <<endl;
     		newInsert = newInterval;
     		intervals.push_back(newInsert);
     	}else if (findInterval(intervals,newInterval.start) == -1 &&findInterval(intervals,newInterval.end) != -1){
     	    cout << "in2" <<endl;
     		newInsert.start = newInterval.start;
     		newInsert.end = intervals[findInterval(intervals,newInterval.end)].end;
     		intervals.push_back(newInsert);

     	}else if (findInterval(intervals,newInterval.start) != -1 &&findInterval(intervals,newInterval.end) == -1){
     	    cout << "in3" <<endl;
     		newInsert.start = intervals[findInterval(intervals,newInterval.start)].start;
     		newInsert.end = newInterval.end;
     		intervals.push_back(newInsert);
     	}else{
     	    newInsert.start = intervals[findInterval(intervals,newInterval.start)].start;
     		newInsert.end = intervals[findInterval(intervals,newInterval.end)].end;
     		intervals.push_back(newInsert);
     	}
     	    
     	

    
		for(int i = 0 ; i < intervals.size(); ++i){
		        if (newInsert.start == intervals[i].start && newInsert.end == intervals[i].end) continue;
     			if (newInsert.start <= intervals[i].start && newInsert.end >= intervals[i].end){
     				intervals.erase(intervals.begin()+i);
     				i--;
     			}
     	}
     	auto comp = [](Interval a,Interval b) -> bool{ return a.start < b.start;};
     	std::sort (intervals.begin(), intervals.end(), comp);
     	return intervals;

    }
};

int main(){

}