#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int calculate(string s) {
     	int size = s.size();
     	if(!size) return 0;

     	auto it = remove(s.begin(),s.end(),' ');
     	s.resize(distance(s.begin(),it));


     	vector<string> vec;
     	
     	int i = 0;

     	while(s.find_first_of('*') != string::npos || s.find_first_of('/') != string::npos || s.find_first_of('+') != string::npos || s.find_first_of('-') != string::npos){
     		if(s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-' ){
     			vec.push_back(s.substr(0,i));
     			vec.push_back(s.substr(i,1));
     			s.erase(0,i+1);
     			i = 0;
     		}
     		i++;
     	}
     	vec.push_back(s);

     	

     	for(int i = 0; i < vec.size(); ++i){
     		if(vec[i] == "*"){
     			int temp = stoi(vec[i-1]) * stoi(vec[i+1]);
     			vec.erase(vec.begin()+i-1,vec.begin()+i+2);
     			vec.insert(vec.begin()+i-1,to_string(temp));
     			i -= 1;
     		}
     		else if(vec[i] == "/"){
     			int temp = stoi(vec[i-1]) / stoi(vec[i+1]);
     			vec.erase(vec.begin()+i-1,vec.begin()+i+2);
     			vec.insert(vec.begin()+i-1,to_string(temp));
     			i -= 1;
     		}
     	}
     	//for(string q: vec) cout << q << " ";

     	int temp = 0;
     	for(int i = 0; i < vec.size(); ++i){
     		if(vec[i] == "+"){
     			temp = stoi(vec[i-1]) + stoi(vec[i+1]);
     			vec.erase(vec.begin()+i-1,vec.begin()+i+2);
     			vec.insert(vec.begin()+i-1,to_string(temp));
				i -= 1;     			
     		}else if(vec[i] == "-"){
     			temp = stoi(vec[i-1]) - stoi(vec[i+1]);
     			vec.erase(vec.begin()+i-1,vec.begin()+i+2);
     			vec.insert(vec.begin()+i-1,to_string(temp));
     			i -= 1;
     		}
     	}
     	return (temp==0)?stoi(vec[0]):temp;
    }


    int calculate2(string s) {
	    stack<int> myStack;
	    //if there is no sign the defalut to +
	    char sign = '+';
	    int res = 0, tmp = 0;
	    for (unsigned int i = 0; i < s.size(); i++) {
	        if (isdigit(s[i])){
	        	//using isdigit to parse the string
	            tmp = 10*tmp + s[i]-'0';
	        }

	        // the current pointer to the sign
	        if ((!isdigit(s[i]) && !isspace(s[i])) || i == s.size()-1) {
	            if (sign == '-'){
	                myStack.push(-tmp);
	                cout << myStack.top() << " ";
	            }
	            else if (sign == '+'){
	                myStack.push(tmp);
	               	cout << myStack.top() << " ";
	            }
	            else {
	                int num;
	                if (sign == '*' )
	                    num = myStack.top()*tmp;
	                else
	                    num = myStack.top()/tmp;
	                myStack.pop();
	                myStack.push(num);
	               	cout << myStack.top()<< " ";
	            } 
	            //perserve the sign for the next one
	            sign = s[i];
	            tmp = 0;
	        }
	    }
	    while (!myStack.empty()) {
	        res += myStack.top();
	        myStack.pop();
	    }
    	return res;
	}
};

int main(int argc, char const *argv[])
{
	/* code */
	Solution s;
	string wtf = "  -11 - 22 + 33";
	cout << s.calculate2(wtf);
	return 0;
}