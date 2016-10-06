#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        if(!size) return 0;
        pair<int,int> leftH;


        int sum = 0;

        leftH.first = 0;
        leftH.second = height[0]; 

        std::vector<int> v(size,0);

        for(int i = 1; i < size-1; ++i){

        	if(leftH.second > height[i] && height[i] < height[i+1]){
        		int diff = min(leftH.second,height[i+1]);
        		for(int k = leftH.first+1; k <= i; ++k){
        			//cout << "k is " << k << " value is "<<(diff - height[k]) << endl;
        			//sum += (diff - height[k]);
        			v[k] = max(diff - height[k],v[k]);
        		}
        	}

        	if(height[i] > leftH.second){
        		leftH.second = height[i];
        		leftH.first = i;
        	}
        }

        for(int i = 0; i < size; ++i){
        	sum += v[i];
        }
        return sum;
    }
};


class Solution2 {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        int max_water(0);
        int i(0);
        while (i<height.size()) {
            if (s.empty()||height[i]<=height[s.top()]) {
            	cout << "push value is " << i << endl;
                s.push(i++);
            } else {
                int bot=height[s.top()];
                s.pop();
                cout << "bot is " << bot << endl;
                max_water+=s.empty()?0:((min(height[i],height[s.top()])-bot)*(i-s.top()-1));
                cout << "i is " << i << " mater water is " << max_water<<endl;
            }
        }
        return max_water;
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	Solution2 s;

	std::vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};

	cout << s.trap(v);

	return 0;
}