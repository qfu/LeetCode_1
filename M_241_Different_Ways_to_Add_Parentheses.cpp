#include <vector>
#include <string>
#include <iostream>

using namespace std;
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
     	int size = input.size();
     	if(!size) return vector<int>();
     	vector<int> v;

     	for(int i = 0; i < size; ++i){
     		if(input[i] == '+' || input[i] == '-' || input[i] == '*'){
     			vector<int> left = diffWaysToCompute(0,i);
     			vector<int> right = diffWaysToCompute(i+1);

     			for(auto & x : left){
     				for(auto & y : right){
     					if(input[i] == '*')
     						v.push_back(x*y);
     					else if (input[i] == '+')
							v.push_back(x+y);
     					else
     						v.push_back(x-y);
     				}
     			}
     		}

     	}
     	//base case
     	if(!v.size()){
     		v.push_back(stoi(input));
     	}
     	
     	return v;
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}