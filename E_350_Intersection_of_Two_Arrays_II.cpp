#include <unordered_map>

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    	unordered_map<int,int> map1;
    	std::vector<int> v;

    	for(int i : nums1) map1[i]++;

  		for(int i : nums2){
  			auto it = map1.find(i);
  			if(it != map1.end() && it -> second){
  				v.push_back(i);
  				it -> second -= 1;
  			}
  		}
  		return v;
    }
};


int main(){

	Solution s;

}