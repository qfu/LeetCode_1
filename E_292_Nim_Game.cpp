#include <iostream>
class Solution {
public:

    bool canWinNim(int n) {
    	return n % 4 != 0;
    }
};

int main (int argc, char *argv[]) { 
	Solution solver;
	std::cout << solver.canWinNim(8) << std::endl;
}
