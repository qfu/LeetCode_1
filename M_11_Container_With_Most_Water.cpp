#include <vector>
#include <iostream>
#include <set>
#include <functional>
#include <algorithm>    // std::find_end

using namespace std;





class Solution {
public:
	int findFirstIndex(vector<int>& height,int value){ 
		for(int i =0 ; i < height.size(); ++i)
			if(height[i] == value) return i;

	}
	int findLastIndex(vector<int>& height,int value){
		for(int i = height.size()-1 ; i >= 0; --i)
			if(height[i] == value) return i;
	}


    int maxArea(vector<int>& height) {
	    set<int,greater<int>> s;
	    set<int,greater<int>> area;
		for(int i : height) s.insert(i);

		for(auto it = s.begin() ; it != s.end();++it){
			int first = findFirstIndex(height,*it);
			int last = findLastIndex(height,*it);
			//cout << *it << endl;
			//cout << first << endl;
			//cout << last << endl;
			
			if(first != last){
				int width = last - first;
				area.insert((*it) * width);
			}
		}

		//find_first_of();
		//find_end() 
		return *area.begin();
    }
    int maxArea2(vector<int>& height){
    	int water = 0;
    	int i = 0, j = height.size()-1;
    	while(i < j){
    		int h = min(height[i],height[j]);
    		water = max(water,(j-i)*h);
    		//find the next higest combination 
    		while(height[i] <= h && i < j) i++;
    		while(height[j] <= h && i < j) j--;
    	}
    	return water;
    }


};










int main(int argc, char ** argv){
	std::vector<int> v = {32,2,23,5,23,4,32,2};
	Solution s;
	cout << s.maxArea(v);

}	