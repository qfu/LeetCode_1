#include <iostream>
#include <string>
#include <vector>
using namespace std;



class Solution {
public:
    bool isScramble(string s1, string s2) {
    	if(s1 == s2) return true;

    	int len = s1.size();

    	//using int to serve as map
        int table[26] = {0};
    	for(int i = 0; i < len;++i){
    		table[s1[i]-'a']++;
    		table[s2[i]-'a']--;
    	}

    	for(int j = 0; j < 26; ++j){
    		if(table[j]) return false;
    	}


    	for (int i = 1; i < len; ++i){
    		if(isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i),s2.substr(i)))
    			return true;
            if( isScramble(s1.substr(0,i), s2.substr(len-i)) && isScramble(s1.substr(i), s2.substr(0,len-i)))
    			return true;

    	}
    	return false;

    }
};




int main(){

}