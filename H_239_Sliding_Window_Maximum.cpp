#include <vector>
#include <iostream>
#include <set>
#include <deque>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int size = nums.size();
        if(!size) return vector<int>();
        deque<int> queue;
        vector<int> result;
        int qindex = 0;
        for(int i = 0;i < size; ++i){
        	if(!queue.empty() && queue.front() == i - k) queue.pop_front();
        	while(!queue.empty() && nums[queue.back()] < nums[i]) queue.pop_back();
        	queue.push_back(i);
        	if(i >= k - 1) result.push_back(nums[queue.front()]);
        }	
        return result;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	std::vector<int> v = {1,3,-1,-3,5,3,6,7};
	vector<int> result = s.maxSlidingWindow(v,3);

	for(int x : result){
		cout << x <<  " ";
	}

	return 0;
}