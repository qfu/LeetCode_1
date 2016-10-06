#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
	void backtrack(vector<string>& result, string s, int pos, int size, int times){
		if(times == 0){
			if (stoi(s.substr(pos)) < 255 && to_string(stoi(s.substr(pos))).size() != (size-pos+1 )) result.push_back(s);
			return;
		}

		/*
		if(pos == size){
			result.push_back(s);
			return;
		}*/
		times -= 1;

		for(int i = pos; i < size; ++i){
			if(i - pos >= 2){
				if (stoi(s.substr(pos,i-pos+1)) > 255) break;
			}
			if(to_string(stoi(s.substr(pos,i-pos+1))).size() != (i-pos+1)) break;

			s.insert(i+1,".");
			backtrack(result,s,i+2,size+1,times);
			s.erase(i+1,1);		
		}
	}

public:
    vector<string> restoreIpAddresses(string s) {
        int size = s.size();
        if(size<=0 || size > 12) return vector<string>();

        vector<string> result;
        backtrack(result,s,0,size-1,3);
        for(string s:result){
        	cout << s << endl;
        }
        return result;
    }
};


int main(int argc, char const *argv[])
{
	/* code */
	Solution s;
	string test = "25525511135";
	s.restoreIpAddresses(test);


	return 0;
}