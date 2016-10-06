#include <iostream>

using namespace std;
class Solution {
public:
	int count = 0;
	int factorial(int n){
		if(n == 0) return 1; 
		int value = n * factorial(n-1);
		if (value % 10 == 0){
			count++;
			value /=10;
		}else if(value > 10){
			value = value % 10;
		}
		return value;
	}

    int trailingZeroes(int n) {
    	int f = factorial(n);
   		return count;
    }

    int trailingZeroes2(int n ){
    	int s = 0;
        int value = 1;
        for(int i = 1; i <= n; ++i){
            value *= i;
		    while (value % 10 == 0){
			    s++;
			    value /=10;
		    }
		    if(value > 10){
			    value = value % 10;
		    }
        }
   		return s;
    }
};

int main(){
	Solution s;
	cout << s.trailingZeroes2(5)<<endl;
}
