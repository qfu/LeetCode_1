#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
     	int size = nums.size();
     	if(!size) return vector<string>();

     	vector<string> result;

     	string temp = to_string(nums[0]);
     	string start = temp;

     	for (int i = 1; i <= size; ++i){
     		if(i == size){
     			if(temp == to_string(nums[i-1])) result.push_back(temp);
     			else{
     				temp +="->";
     				temp += to_string(nums[i-1]);
     				result.push_back(temp);
     			}
     			break;
     		}
     		if(nums[i] != nums[i-1]+1){
     			if(temp == to_string(nums[i-1])) result.push_back(temp);
     			else{
     				temp +="->";
     				temp += to_string(nums[i-1]);
     				result.push_back(temp);
     			}
     			temp = to_string(nums[i]);
     		}
     	}
     	if(temp == start && size != 1) result.push_back((temp+="->")+= to_string(nums[size-1]));
     	

     	return result;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	std::vector<int> v = {0,8,9};
	
	vector<string> q  = s.summaryRanges(v);

	for(string x: q){
		cout << x<< " ";
	}
	return 0;
}