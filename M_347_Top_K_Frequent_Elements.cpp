#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    	if (!nums.size()) return vector<int>();

    	std::map<int,int> mymap;
    	std::vector<int> returnV;
    	std::vector<map<int,int>> vm;
    	for(int i = 0; i < nums.size(); ++i){
    		//map content is initilized as 0
    		mymap[nums[i]]++;
    	}


  		auto my_comp = [](const pair<int,int> & left, const pair<int,int> & right) -> bool {return left.second < right.second;};

    	priority_queue<pair<int,int>,vector<pair<int,int>>, decltype(my_comp)> mypq(my_comp);

    	for(auto it = mymap.begin(); it != mymap.end(); ++it){
    		mypq.push(make_pair(it->first,it->second));
    	}	
    	while(!mypq.empty() && k--){
    		returnV.push_back(mypq.top().first);
    		mypq.pop();
    	}
    	return returnV;
        
    }
};


int main(int argc, char ** argv){
	// the type of a lambda function is unique and unnamed
  
  vector<int> v = {1,1,1,2,2,3,2,2,3,3,3,3,3};

  Solution s;
  vector<int> result = s.topKFrequent(v,2);
  for (int a: result){
  	cout << a;
  }

  return 0;

}