#include <iostream>
#include <bitset>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;
class Solution {
public:
	int singleCout(int num){
	    int cout = 0;
    	bitset<64> b(num);
    	string s= b.to_string();
    	const char * c = s.c_str();
    	printf("%s\n", s.c_str());
    	for(; *c; c++){
    		if(*c == '1')
    			cout++;
    	}
    	return cout;	
	}

    vector<int> countBits(int num) {
    	vector<int> v;
    	for(int i = 0; i <= num; i++){
    		v.push_back(singleCout(i));
    	}
    	return v;

    }
};

int main(int argc, char ** argv){
	Solution solver;
	for (const int & a : solver.countBits(5))
		cout << a << endl;	
}