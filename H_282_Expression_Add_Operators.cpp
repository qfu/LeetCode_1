#include <vector>
#include <string>
#include <iostream>
using namespace std;



class Solution {
private:
	void backtrack(string num, int target, long cur, long prev,vector<string>& result, int size, string path, int index){
		//no need to consider target == cur because there is no way it will stop in the middle
		//of the call
		if(index == size){
			if(target == cur) result.push_back(path);
			return;
		}

		for(int i = index; i < size; ++i){
			if(num[index]=='0' && i>index) break;
			string str = num.substr(index,i-index +1);
			long val = stol(str);

			if(index == 0){
				backtrack(num,target,val,val,result,size,path+str,i+1);
			}else{	
				// can't not use target-val to keep track must have another cur

				//addition
				backtrack(num,target,cur+val,val ,result,size,path+'+'+str,i+1);
				// No need to pop back because no paht is not overwritten

				//multiplication
				backtrack(num,target,cur - prev + prev*val,prev*val,result,size,path+'*'+str,i+1);
		
				//subtraction
				backtrack(num,target,cur-val,-val,result,size,path+'-'+str,i+1);
			}
		}
	}

public:
    vector<string> addOperators(string num, int target) {
    	int size = num.size();
    	if(!size) return vector<string>();
    	std::vector<string> result;
    	string path;

    	backtrack(num,target,0,0,result,num.size(),path,0);

    	for(string s: result ) cout << s << " ";

    	return result;
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	Solution s;
	s.addOperators("105",5);

	return 0;
}
