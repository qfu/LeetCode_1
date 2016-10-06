#include <string>
#include <iostream>
#include <sstream>
#include <stack>
using namespace std;


class Solution {
public:
    int lengthLongestPath(string input) {
    	int size = input.size();
    	if(!size) return 0;
    	stack<int> s;
    	s.push(-1);

    	stringstream ss(input);
		string tmp;
		int maxLen = 0;
		while(getline(ss,tmp,'\n')){
			int i = 0;
			for(char c: tmp) i = (c =='\t')?i+1:i;
			while(i+1 < s.size()) s.pop();
			// substract the tab space;
			int len = s.top() + tmp.size() - i + 1;

			s.push(len);

			if(tmp.find_first_of('.') != string::npos) maxLen = max(len,maxLen);

		}	
		return maxLen;
        
    }
};


int main(int argc, char const *argv[])
{
	//The sequence is resemble the DFS backtrack route
	string test = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
	
	Solution s;
	cout << s.lengthLongestPath(test);

	/* code */
	return 0;
}