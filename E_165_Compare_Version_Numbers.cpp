#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
    	size_t l = version1.find_first_of('.');
    	size_t r = version2.find_first_of('.');
    	string left = version1,right = version2;
    	if(l != string::npos)left = version1.substr(0,l);
    	if(r != string::npos)right = version1.substr(0,r);

    	//Remove the leading 0s
    	cout << left;
    	cout << right;
cout <<endl;

    	int ll = stoi(left);
    	int rr = stoi(right);
    	   	cout << ll;
    	cout << rr;
    	if(ll != rr) return (ll > rr)? 1 : -1;

    	if(l != string::npos)left = version1.substr(l+1);
    	else left.clear();

    	if(r != string::npos)right = version1.substr(r+1);
    	else right.clear();

    	if(!left.size() && right.size()) return -1;
    	else if(!right.size()&& left.size()) return 1;

    	ll = stoi(left);
    	rr = stoi(right);
    	if(ll != rr) return (ll > rr)? 1 : -1;

    	return 0;

    }
};

int main(){
    Solution s;
    cout << s.compareVersion("1","01");
    return 0;
}