#include <string>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        
        if(preorder[0] == '#' && preorder.size() == 1) return true;

    	stack<string> stack;
    	preorder += ",";
        size_t find = preorder.find_first_of(',');
        bool result;

        while(find != string::npos){
        	string c = preorder.substr(0,find);
        	cout << c <<endl;

        	stack.push(c);

            preorder = preorder.substr(find+1);
            find = preorder.find_first_of(',');

        	while(stack.size() && stack.top() =="#"){
        		stack.pop();
                if(stack.size() == 2 && find == string::npos){
                    string temp = stack.top();
                    stack.pop();
                    result = (stack.top() != "#");
                    stack.push(temp);
                }
        		
                if(stack.size() >= 2 && stack.top() =="#"){
        			stack.pop();
        			stack.pop();
        			stack.push("#");
        		}else{
        			stack.push("#");
        			break;
        		}
        	}

        }

        return stack.top()=="#" && result && stack.size() == 1;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	string test = "9,#,#,1";
	cout << s.isValidSerialization(test);
	/* code */
	return 0;
}