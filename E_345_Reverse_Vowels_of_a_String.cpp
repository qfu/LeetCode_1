#include <vector>
#include <string>
#include <iostream>
using namespace std;


class Solution {
public:
    string reverseVowels(string& s) {
      vector<int> index;
    	int size = s.size();
		for(int i =0; i < size;++i){
			if(s[i] == 'a' || s[i] == 'e'||s[i] == 'i'||s[i] == 'o'||s[i] == 'u' || s[i] == 'A' || s[i] == 'E'||s[i] == 'I'||s[i] == 'O'||s[i] == 'U'){
				index.push_back(i);
			}
		}        
        int value = index.size();

		for(int j = 0; j < index.size()/2;++j){
			swap(s[index[j]],s[index[value-1-j]]);
		}
		return s;
    }
};

int main(){

	Solution s;

	string x = "hello";
	cout << s.reverseVowels(x);

	return 0;
}