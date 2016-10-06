#include <string>
#include <vector>
#include <iostream>
#include <set>


using namespace std;

class Solution {
private:
	void backtrack(vector<string>& v, string s1, int index, int size){

		//base case it something that is out off the bound
		if(index >= size || index < 0) return;

		v.push_back(s1);
		for(int i = index ; i < size; ++i){
			if(s1[i] == '(' && i -1 >=0 && s1[i-1] == ')'){
				swap(s1[i],s1[i-1]);
				backtrack(v,s1,i-1,size);
				swap(s1[i],s1[i-1]);
			}

		}
		return;

	}


public:
    vector<string> generateParenthesis(int n) {
		if(!n) return vector<string>();
		string pair = "()";

		string s1 = "";
		while(n--){
			s1 += pair;
		}
		vector<string> v;
		backtrack(v,s1,0,s1.size());
		//vector<string> v(s.begin(),s.end());
		for_each(v.begin(),v.end(),[](string s){ cout << s <<" ";});
		return v;
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	Solution s;
	s.generateParenthesis(7);
	return 0;
}