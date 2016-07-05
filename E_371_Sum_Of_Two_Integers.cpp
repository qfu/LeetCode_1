#include <iostream>
class Solution {
public:
    int getSum(int a, int b) {
        while( b != 0){
            //figure out the carry bit
            int carry  = a & b;
            //Perform addition
            a = a ^ b;
            //Update the carry
            b = carry << 1;
        }
        return a;
    }
};

int main(int argc, char** argv){
	Solution solver;
	std::cout << solver.getSum(4,5);
}