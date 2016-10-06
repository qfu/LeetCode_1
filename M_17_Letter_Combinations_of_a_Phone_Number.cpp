#include <iostream>
#include <vector>
#include <string>


using namespace std;


class Solution {
public:

	void combinationString(vector<string>& result, string& str,vector<string>& vec,int begin){
		if(str.size() == result.size()){
			vec.push_back(str);
			return;
		}


		for (int i = 0; i < result[begin].size(); ++i){
			str += result[begin][i];
			combinationString(result,str,vec,begin+1);
			str.pop_back();
		}
		return;
	}


    vector<string> letterCombinations(string digits) {
    	std::vector<string> result;

    	for(int i =0; i < digits.size();++i){
    		  switch(digits[i]){
			   case '2' :
			   		result.push_back("abc");
			      break;
			   case '3' :
			   		result.push_back("def");
			   	  break;
			   case '4' :
			   		result.push_back("ghi");
			      break;
			   case '5' :
			   		result.push_back("jkl");
			      break;
			   case '6' :
			   		result.push_back("mno");
			      break;
			   case '7' :
			   	    result.push_back("pqrs");
			      break;
			   case '8' :
			   	    result.push_back("tuv");
			      break;
			   case '9' :
			   	    result.push_back("wxyz");
			      break;
			   default :
			   	  break;
			   }
    	}


    	string str = "";
    	vector<string> vec;

    	combinationString(result,str,vec,0);
/*		
		for(string s : vec){
			cout << s << endl;
		}*/
		return vec;

    }
};

int main(){

	Solution s;
	string st = "23";
	s.letterCombinations(st);

}