#include <vector>
#include <iostream>
#include <utility>
#include <map>
#include <set>
#include <numeric>
#include <functional>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        multimap<int,int> m;
        for(const auto & building: buildings){
        	//insert only accept pair
        	m.insert({building[0],building[2]});
        	m.insert({building[0],-building[1]});
        }

        multiset<int,greater<int>> set;
        map<int,int> result;

        for(auto & point : m){
        	if(point.second > 0){
        		set.insert(point.second);
        	}else{
        		set.erase(set.find(-point.second));
        	}
        	result[point.first] = *set.begin();
        }


		vector<pair<int, int>> returnV;
		for(auto & res : result){
			returnV.push_back({res.first,res.second});
		}

		auto functor = [](pair<int,int> a, pair<int,int> b){ return a.second == b.second;};

		auto it = unique(returnV.begin(), returnV.end(),functor);
		returnV.resize(std::distance(returnV.begin(),it));
		return returnV;

    }
};

int main(int argc, char const *argv[])
{
	
	return 0;
}