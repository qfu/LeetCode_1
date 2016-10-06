#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
    	string result = "";
    	int size1 = num1.size();
    	int size2 = num2.size();
    	reverse(num1.begin(),num1.end());
    	reverse(num2.begin(),num2.end());

    	int sum = 0;
    	for(int i = 0; i <size1;++i){
    		for(int j = 0; j < size2; ++j){
    			sum += (num1[i] - '0') * (num2[j] - '0')* pow(10,j) * pow(10,i);
    		}
    	}

    	while(sum){
    		result += ((sum % 10) + '0');
    		sum /= 10;
    	}
    	reverse(result.begin(),result.end());

    	return result;
    }
	string multiply(string num1, string num2) {
	    string sum(num1.size() + num2.size(), '0');
	    
	    for (int i = num1.size() - 1; 0 <= i; --i) {
	        int carry = 0;
	        for (int j = num2.size() - 1; 0 <= j; --j) {
	            int tmp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
	            sum[i + j + 1] = tmp % 10 + '0';
	            carry = tmp / 10;
	        }
	        sum[i] += carry;
	    }
	    
	    size_t startpos = sum.find_first_not_of("0");
	    if (string::npos != startpos) {
	        return sum.substr(startpos);
	    }
	    return "0";
	}
};

int main(int argc, char ** argv){
	Solution s;
	string s1 = "123";
	string s2 = "456";
	cout << s.multiply(s1,s2);


}