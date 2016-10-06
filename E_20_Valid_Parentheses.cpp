#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool isValid(string s) {

    	stack<char> pile;
    	unordered_map<char,char> map;
    	map[')'] = '(';
		map['}'] = '{';
		map[']'] = '[';
    	for(char c : s){
    		if(c =='(' || c =='{' || c =='[') pile.push(c);
    		else if(c ==')' || c =='}' || c ==']'){
    			if (pile.size() && pile.top() == map[c]) pile.pop();
    			else return false;
    		}
    	}
    	return !pile.size();
	}
};

int main(int argc, char** argv){

	return 0;
}