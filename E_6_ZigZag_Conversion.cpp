#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
    	if(numRows == 1) return s;
        
    	int x = numRows + numRows -2;
    	int j = 0;

    	string result = "";
    	int oddEven = 0;

    	for(int i =0; i < numRows;++i){
    		for(int q = i; q < s.size();){
    			result += s[q];
    			if(i == 0 || i == (numRows-1)) q = q + numRows + numRows -2;
    			else if(oddEven%2 == 0) q = q + x;
    			else q = q + j;
    			oddEven += 1;
    		}
    		oddEven = 0;
    		x  = x - 2;
    		j = j + 2;
    	}
    	
    	return result;
    }
};

int main(){
	Solution s;
	string test = "PAYPALISHIRING";
	cout << s.convert(test,3)<<endl;

}