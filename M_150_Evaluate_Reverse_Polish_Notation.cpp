#include <vector>
#include <stack>
#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
    	int size = tokens.size();
    	if(!size) return 0;

    	stack<int> s;
		for(int i = 0; i < size; ++i){
			if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
				int var1 = s.top();
				s.pop();
				int var2 = s.top();
				s.pop();

				int result;
				if(tokens[i] == "+") result = var2 + var1;
				if(tokens[i] == "-") result = var2 - var1;
				if(tokens[i] == "*") result = var2 * var1;
				if(tokens[i] == "/") result = var2 / var1;
				s.push(result);
			}
			else s.push(stoi(tokens[i]));
		}        
		return s.top();
    }
};

int main(int argc, char const *argv[])
{
	

  //["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  //["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
	Solution s;
	std::vector<string> v = {"4", "13", "5", "/", "+"};
	cout << s.evalRPN(v);
	return 0;
}