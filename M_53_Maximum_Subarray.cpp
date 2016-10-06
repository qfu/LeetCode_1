#include <set>
#include <vector>
#include <iostream>
#include <numeric>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        set<int> s;
        for(int i = 0; i < nums.size();++i){
            for(int j = i+1;j <= nums.size() && j >= i; ++j){
            	//cout << "i" << i << "j" << j << endl;
            	//cout <<accumulate(nums.begin()+i,nums.begin()+j,0);
                s.insert(accumulate(nums.begin()+i,nums.begin()+j,0));
            }
        }
        return *(--s.end());
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        for(int i = 1; i < nums.size();++i){
            if(nums[i] + nums[i-1] > nums[i]) nums[i] = nums[i] + nums[i-1];     
        }
        sort(nums.begin(),nums.end());
        return *(--nums.end());
    }
};
int main(){
	Solution s;
	//std::vector<int> v = {−2,1,−3,4,−1,2,1,−5,4};
	std::vector<int> v;
	v.push_back(-2);
	v.push_back(1);
	v.push_back(-3);
	v.push_back(4);
	v.push_back(-1);
	v.push_back(2);
	v.push_back(1);
	v.push_back(-5);
	v.push_back(4);

	cout << s.maxSubArray(v);
}