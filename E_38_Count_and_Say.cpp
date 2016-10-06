#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;




class Solution {
public:
	string intToStr(int n){
		string str = "";
		while(n % 10){
			str += (n%10 + '0');
			n /= 10;
		}
		reverse(str.begin(),str.end());
		return str;
	}

    string countAndSay(int n) {
      string start = "1";
	  for(int i = 0; i < n-1; ++i){
	  	start = convertString(start);
	  } 
	  return start;
    }

    string convertString(string str){
    	unordered_map<char,int> map;
    	string s = "";
    	vector<pair<char,char>> v;
    	for(int i = 0; i < str.size();++i){
    		if( i + 1 < str.size() && str[i] != str[i+1]){
    			map[str[i]]++;
    			v.push_back(make_pair(str[i], map[str[i]] + '0'));
    			map.erase(str[i]);

    		}else if(i +1 == str.size()){
    			map[str[i]]++;
    			v.push_back(make_pair(str[i], map[str[i]] + '0'));
    			map.erase(str[i]);
    		}
    		else map[str[i]]++;

    	}
    	//after unque remember to resize
    	//str.resize(distance(str.begin(),unique(str.begin(),str.end())));

    	for(auto & x : v){
    		s += x.second;
    		s += x.first;
    	}
    	return s;
    }


};

int main(){
	Solution s;
	cout <<s.countAndSay(5);

}