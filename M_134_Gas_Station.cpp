#include <iostream>
#include <functional>
#include <vector>
#include <utility>
#include <set>
using namespace std;

class Solution {
private:
	int startJ(int index, const vector<int>& gas, const vector<int>& cost){
		int size = gas.size();
		int _r = index;
		int remain = 0;
		for (int i = index ; i <= index + size - 1; ++i){
			int _i = i % size;
			remain = (gas[_i] + remain) - cost[_i];
            if(remain < 0) return 0;
		}
        cout << "index is " << index << "remain is " << remain << endl;
		if(remain >= 0) return 1;

		return 0;

	}


public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

    	//as template parameter


        //this optmizaiton is unnecessary 
        //this set operation
    	auto cmp = [](pair<int,int> a,pair<int,int> b)-> bool{ return a.second >= b.second;};
        set<pair<int,int>,decltype(cmp)> s(cmp);
        int size = gas.size();
        //Gas is empty
       	if (!size) return -1;

        for(int i = 0 ; i < size;++i){
        	if(gas[i] >= cost[i]){
        		s.insert(make_pair(i,gas[i] - cost[i]));
        	}
        }

        if(!s.size()) return -1;
        
        //start from the biggest cost 
        for(auto it = s.begin(); it != s.end(); ++it){
        	int result =  startJ(it->first,gas,cost);
        	if(result) return it->first;
		}	
        return -1;
    }
};



int main(){
 
	std::vector<int> v1 = {3,4,5,1,2};
	std::vector<int> v2 = {1,2,3,4,5};
	Solution s;
	cout << s.canCompleteCircuit(v2,v1);
}