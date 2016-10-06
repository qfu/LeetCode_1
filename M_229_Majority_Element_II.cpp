#include  <vector>
#include <unordered_map>
#include <iostream>

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
		vector<int> v;
		if (!nums.size()) return v;
		unordered_map<int,int> mymap;
		
		int freq = nums.size()/3;
		for (int x: nums) mymap[x]++;


		for(auto it = mymap.begin(); it != mymap.end();++it)
			if (it->second > freq) v.push_back(it->first);
		return v;

    }
};


int main(){

}