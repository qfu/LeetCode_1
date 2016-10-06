#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = nums.size();
        int i=0;
        
        for(int num:nums){
            result ^= num;
            result ^= i;
            i++;
        }
        
        return result;
    }
};
int main(int argc, char const *argv[])
{
	int a = 3;
	int b = 3;
	int c = 4;

	cout << (a ^ b);
	cout << (a ^ c);
	cout << (a ^ b ^ c^ c ^ b);

	return 0;
}