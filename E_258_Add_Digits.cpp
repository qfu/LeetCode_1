#include <iostream>
using namespace std;
class Solution {
public:
    int addDigits(int num) {
        if (num == 0 ) return 0;
        if (num / 10 == 0) return num;
        int sum  = 0;
    	while (num){
    		sum += (num % 10);
    		num /= 10;
    		cout << num << endl;
    	} 
        //while (num /= 10) sum += num;
        return addDigits(sum);
        //return sum;
    }
};
int main (int argc , char ** argv){
	Solution solver;
	std::cout << solver.addDigits(1145);
}