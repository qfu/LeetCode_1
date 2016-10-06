#include <string>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    string decodeString(string s, int &index) {
    	int size = s.size();
    	
    	string result;
    	int tmp = 0;

    	while(index < size){
    		//cout << index << endl;
    		if(isdigit(s[index])){
    			tmp = tmp*10 + s[index] - '0';
    		}
    		else if(s[index] == '['){
    			string nextLevel  = decodeString(s,++index);
    			while(tmp--) result += nextLevel;
    			tmp = 0;
    		}
    		else if(s[index] == ']'){
    			return result;
    		}else{
    			result += s[index];
    		}
    		index++;
    	}
    	return result;
    }
};

int main(int argc, char const *argv[]){
/*
	s = "3[a]2[bc]", return "aaabcbc".
	s = "3[a2[c]]", return "accaccacc".
	s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
*/
	Solution s;
	string test1 = "2[abc]3[cd]ef";
	int index = 0;
	cout << s.decodeString(test1,index);


	return 0;
}