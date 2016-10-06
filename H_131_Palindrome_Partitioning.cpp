#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:

public:
	bool isPalindrome(string s){
		string t = s;
		s.reverse();
		return t == s;
	}
    vector<vector<string>> partition(string s) {
        
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	Solution s;
	return 0;
}