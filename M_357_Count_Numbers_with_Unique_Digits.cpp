#include <iostream>
#include <cmath>
#include <set>
using namespace std;

class Solution {
public:
	bool isUnique(int n){
        set<int> s;
        int r = 0;
		if(n <= 10) return true; 
		
		while(n){
			s.insert(n % 10);
			r+=1;
			n /= 10;
		}
		return s.size()==r;
	}


    int countNumbersWithUniqueDigits(int n) {
    	int num = 0;
        for(int i = 0; i < pow(10,n);++i){
        	num = isUnique(i)?num+1:num;
        }
        return num;	
    }
};






int main(){
	Solution s;
	//cout << s.isUnique(1111);
	//cout << s.isUnique(1234);
	cout << s.countNumbersWithUniqueDigits(2`);

}