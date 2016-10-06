#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
	unordered_set<int> result;


	int computeBinary(vector<int> & v){
		int sum = 0;
		for(int i =0 ; i < v.size(); ++i){
			sum += (pow(2,i)*v[i]);
		}
		return sum;
	}



	void backtrack(int begin,vector<int>& binary, int size){
		// base case
		if(begin < 0){
			return;
		}

		for(int i = 0; i <= 1 ; ++i){
			binary[begin] = i;
			//binary[i] ~= binary[i] ;
			//cout << computeBinary(binary) << "test" << endl;
			result.insert(computeBinary(binary));
			backtrack(begin-1, binary,size);
		}
		return;
	}



    vector<int> grayCode(int n) {
	    // n is the # bits 
	   	if (n == 0) return vector<int>(1,0);
	    vector<int> binary = vector<int>(n,0);
	   
	    backtrack(n-1,binary,n);
	    	
	    vector<int> returnV;
	    result.insert(0);

		for_each(result.begin(),result.end(),[&](int a){ returnV.push_back(a);});

	    return returnV;
    }
};



int main(int argc, char ** argv){
	vector<int> test;
	Solution s;
	test = s.grayCode(1);

	for_each(test.begin(),test.end(),[](int a){ cout << a;});
}