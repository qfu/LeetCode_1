#include <string>
#include <iostream>
#include <stack>


using namespace std;


class Solution {
public:
    string simplifyPath(string path) {
    int size = path.size();

    if(path[size-1] != '/') path += '/';    


    stack<string> stack;
    string returnS;

    size_t find = path.find_first_of('/');
    path.erase(find,1);

	while(find != string::npos){
		while(path[0] == '/') path.erase(0,1);

     	find = path.find_first_of('/');

     	if(find == string::npos) break;


      	string str = path.substr(0,find);
      	path.erase(0,find+1);
  
     	if(str == ".") continue;
     	else if(str == ".." && !stack.empty()) stack.pop();
     	else if(str == ".." && stack.empty()) continue;
     	else stack.push(str);
     }
     if(stack.empty()) return "/";
     while(!stack.empty()){
     	returnS.insert(0,stack.top());
     	stack.pop();
     	returnS.insert(0,"/");
     }	
     return returnS;
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	Solution s;
	cout << s.simplifyPath("/home/") << endl;
	return 0;
}