#include <vector>
#include <unordered_set>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;


class Solution {
private:
	void backtrack(vector<string>& vec, string s, string temp, const unordered_set<string>& wordDict,int index, int size, unordered_map<string,string>& cache ){
		if(index >= size){
			temp.erase(temp.size()-1);
			vec.push_back(temp);
			return;
		}

		for(int i = index; i < size; ++i){
			string ss = s.substr(index,i-index+1);
			//cout << ss <<endl;
			if(cache.find(ss) != cache.end()){
				temp += cache[ss];
				temp += " ";
				temp.erase(temp.size()-1);
				if(temp[0] == ' ') temp.erase(0,1);

			    if(i == (size -1)){
			    	temp.erase(temp.size()-1);
			     	vec.push_back(temp);
					return;
				}else{
					// this is the problem
					//it cannot mimic the return back
					index = i + 1;
					continue;
				}
			}

			if(wordDict.find(ss) != wordDict.end()){
				//the substring is in the dictionary
				string back = temp;
				int t_s = temp.size();
				temp += ss;
				temp += " ";
				backtrack(vec,s,temp,wordDict,i+1,size,cache);
				cache[ss] = temp.substr(t_s);
				temp = back;
			}
		}
	}


public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
    	int _s = s.size();
    	int _d = wordDict.size();
    	if(!_s || !_d) return vector<string>();

    	vector<string> vect;
    	unordered_map<string,string> cache;
    	string ss = "";
    	backtrack(vect,s,ss,wordDict,0,_s,cache);

    	for(string str: vect) cout << str << endl;

    	return vect;
        
    }
};

class Solution2 {
    unordered_map<string, vector<string>> m;

    vector<string> combine(string word, vector<string> prev){
        for(int i=0;i<prev.size();++i){
            prev[i]+=" "+word;
        }
        return prev;
    }

public:
    vector<string> wordBreak(string s, unordered_set<string>& dict) {
        if(m.count(s)) return m[s]; //take from memory
        vector<string> result;
        if(dict.count(s)){ //a whole string is a word
            result.push_back(s);
        }
        for(int i=1;i<s.size();++i){
            string word=s.substr(i);
            if(dict.count(word)){
                string rem=s.substr(0,i);
                vector<string> prev=combine(word,wordBreak(rem,dict));
                result.insert(result.end(),prev.begin(), prev.end());
            }
        }
        m[s]=result; //memorize
        return result;
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	Solution sol;
	unordered_set<string> dict = {"aaaa", "aaa"};
	string s  = "aaaaaaa";

	sol.wordBreak(s,dict);



	return 0;
}