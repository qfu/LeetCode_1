#include <vector>
#include <queue>
#include <utility>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    	int m = nums1.size();
    	int n = nums2.size();

    	if(!m || !n) return vector<pair<int,int>>();

    	auto cmp = [](pair<int,int> a,pair<int,int> b){ return ((a.first + a.second) > (b.first + b.second)); };
    	priority_queue<pair<int,int>,vector<pair<int,int>>, decltype(cmp)> pq(cmp);


    	for(int i = 0; i < m; ++i){
    		for(int j = 0; j < n; ++j){
    			pq.push(make_pair(nums1[i],nums2[j]));
    		}
    	}

    	vector<pair<int,int>> vec;

    	while(k--&& !pq.empty()){
    		vec.push_back(pq.top());
    		pq.pop();
    	}
    	return vec;

    }
};

int main(int argc, char const *argv[])
{
	/* code */
	std::vector<int> v1 = {1,1,2};
	std::vector<int> v2 = {1,2,3};
	Solution s;
	auto x = s.kSmallestPairs(v1,v2,3);

	for(auto y : x){
		cout << y.first << " " <<y.second<< " ";
	}

	return 0;
}