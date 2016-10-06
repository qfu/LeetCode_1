#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	vector<string> v;

	void backtrack(string s, int begin){
		if(begin == s.size()-1){
			v.push_back(s);
			return;
		}
		for(int i = begin; i < s.size(); ++i){
			swap(s[i],s[begin]);
			//use recursion to increase the depth
			//use the for loop and calling stack to make the swap
			backtrack(s,begin+1);
			swap(s[i],s[begin]);
		}
		return;

	}







    string getPermutation(int n, int k) {
        //n is the number that form a string, k is the kth element
    	string s="";
    	for(int i = 1; i <= n; ++i){
    		s += to_string(i);
    	}
    	backtrack(s,0);
		sort(v.begin(),v.end());
		/*
		for(auto & x :v){
			cout << x << endl;
		}*/

    	return v[k-1];

    }
};



int main(int argc, char ** argv){

	Solution s;
	
	string s1 = "1234";
	string a = s.getPermutation(1,1);
	
	cout << a;
	return 0;

}