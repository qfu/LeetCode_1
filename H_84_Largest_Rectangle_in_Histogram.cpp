#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <climits>

using namespace std;
class Solution {

private:
	//Run Time O(n)
	int maximumInRange(vector<int>& heights, int start, int end, int mid){

		int left = mid, right = mid + 1;
		int area = 0,h = min(heights[left],heights[right]);
		while(left >= start && right <= end){
			h = min(h,min(heights[left],heights[right]));
			area = max(area,h*(right-left+1));
			if(left == start){
				right++;
			}else if (right == end){
				left--;
			}else{
				//make sure that left height is greater than right expand height
				if(heights[left-1] > heights[right+1])
					left--;
				else right++;
			}
		}
		return area;
	}


	//Divide and Conquer Run time O(logN)
	int largestRangeArea(vector<int>& heights, int start, int end){
		//base case
		if(start == end) return heights[start];

		int mid = start + (end - start)/2;


 	 	int left = largestRangeArea(heights,start,mid);
 	 	int right = largestRangeArea(heights,mid+1,end);
 	 	int cross = maximumInRange(heights,start,end,mid);

 	 	return max(cross,max(left,right));
	}


public:
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        if(!size) return 0;
        return largestRangeArea(heights,0, (size-1));
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	Solution s;
	std::vector<int> v = {2,1,5,6,2,3};
	cout << s.largestRectangleArea(v);
	return 0;
}