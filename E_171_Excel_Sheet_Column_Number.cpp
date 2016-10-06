#include <iostream>
#include <unordered_map>
#include <string>

#define INDEX(c) ((int)c - (int)'A')
using namespace std;


class Solution {
public:
    int titleToNumber(string s) {
        unordered_map<int, int> map;
        int j = 1;
        for(int i = INDEX('A'); i <= INDEX('Z'); ++i){
        	map[i] = j++;
        }

     	int size = s.size();
     	int sum = 0;
     	int z = 1;
     	for(int i = size -1 ; i >=0;--i, z*=26){
     		sum += map[INDEX(s[i])]*z;
     	} 
     	return sum;
    }
};



int main(int argc, char ** argv){
	Solution s;
	cout << s.titleToNumber("BA");

}