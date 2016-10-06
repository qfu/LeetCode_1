#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
class Solution {
public:
    string largestNumber(vector<int>& nums) {
    	string str;
        int size = nums.size();
        if(!size) return str;
        int i;
        for(i = 0; i < size; ++i){
            if(nums[i] != 0)break;
        }
        if(i == size) return "0";
    
        auto cmp = [](string a,string b) -> bool{
			int n = a.size();
			int m = b.size();
			if(n==m) return a > b;
			else{
			    int i = 0;
				bool value = true;
				int smaller = min(n,m);
				while(smaller != i){
					value &= (a[i] == b[i]);
					i++;
				}
				if(value) return (a[n-1] > b[m-1]) ? true:false;
				else return a > b;
			}
        };
		vector<string> strVec;

        for(int i = 0; i < size; ++i){
			strVec.push_back(to_string(nums[i]));
        }
        sort(strVec.begin(),strVec.end(),cmp);
        for(string s:strVec) str += s;

        return str;

    }
};

int main(int argc, char const *argv[])
{
	/* code */
	std::vector<int> v = {3, 30, 34, 5, 9};

	/*
	auto cmp = [](string a,string b) -> bool{
		int n = a.size();
		int m = b.size();
		if(n==m) return a > b;
		else if (n > m){
			//cout << a << "," << b << " ";
			int i = 0;
			bool value = true;
			while(m != i){
				value &= (a[i] == b[i]);
				i++;
			}
			while(n != i) value &=(a[i++] == '0');

			return value?false: a > b;
		}else{
			int i = 0;
			bool value = true;
			while(n != i){
				value &= (a[i] == b[i]);
				i++;
			}
			while(m != i) value &=(a[i++] == '0');
			return value?false: a > b;
		}
	};*/

	//sort(v.begin(),v.end(),cmp);
	//for(string i : v) cout << i << " ";
	Solution s;
	cout << s.largestNumber(v);




	return 0;
}