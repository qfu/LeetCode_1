#include <iostream>
#include <queue>
using namespace std;


class Solution {
public:
    int reverse(int x) {
    	int count = 1;
    	int y = 0;
    	while(x){
    		y = y*10 + x%10;
    		//y += (x % 10)*count;
    		if (x > 10)count *=10;
    		x /= 10;
    	}
    	return y;
        }
};

int main(){

	Solution s;
	cout << s.reverse(12345);
}