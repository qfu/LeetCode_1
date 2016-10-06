#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
    	int j =0;
     	for(int i =0; i < haystack.size(); ++i){
     		if(haystack[i] == needle[j]){
     			for(int k = i + 1; k < i+ needle.size();k++){
     				if(haystack[k] == needle[++j]) continue;
     				else{
     					return -1;
     				}
     			}
     			return i;
     		}
     	}
     	return -1;
    }
};



int main(){
	Solution s;
	cout << s.strStr("This is true","true");

}