#include <string>
#include <iostream>
#include <stack>
using namespace std;

class Solution {



public:
    int calculate(string s) {
        int size = s.size();
        if(!size) return 0;
		int start = 0;
		return calculate2(s,start,size);
    }

    int calculate2(string s,int &index, int size) {
        //Define this as the first level
        //int index = 0;
        int accumulator = 0, tmp = 0, sign = 1;

        while(index < size){
        	if(isdigit(s[index])){
        		tmp = 10 * tmp + s[index]-'0';
        		//index++;
        	}else if(s[index] =='+' || s[index] =='-' ){
        		accumulator += (sign == 1)? tmp:-tmp;
        		sign = (s[index] == '+')? 1 : -1;
        		//index++;
        		tmp = 0;
        	}else if(s[index] == '(' ){
        		tmp = calculate2(s,++index,size);
        		//index++;
        		//tmp = 0;
        		//cout << tmp;

        	}else if(s[index] == ')'){
        		accumulator += (sign == 1)? tmp:-tmp;
        		return accumulator;
        	}
        	//else 
        	//cout << tmp<<endl;
        	index++;
        }
       	accumulator += (sign == 1)? tmp:-tmp;
        return accumulator;
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	Solution s;
	string test = " 1 + 1 ";
	cout << s.calculate(test);

	return 0;
}