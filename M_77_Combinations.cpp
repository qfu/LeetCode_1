#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
	unordered_map<int,bool> map;		
	vector<vector<int>> v;
	vector<int> vec;
	//int q;



    vector<vector<int>> combine(int n, int k,int index=0) {

    	if(k == 0){
    		v.push_back(vec);
    		map[index] = false; 
    		return v;
    	}



    	for(int i = 1 ; i <= n; ++i){
    		if(!map[i]){
    			map[i] = true;
    			vec.push_back(i);
    			combine(n,k-1,i);
    			vec.pop_back();
    			//map[i] = false;
    		}
    	}
    	//q += 1;
    	return v;
    }

    vector<vector<int>> combine2(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        combine1(1,n,k,ans,temp); //call fuction to get combination of k numbers which range is 1-n
        return ans;
    }
private:
       void combine1(int begin,int n, int k, vector<vector<int>> &ans, vector<int>& temp){
            if(k==0){ 
                ans.push_back(temp);
                return;
            } 
            //condition : n-i+1 is the range, range must greater than k
            for(int i=begin;i <= n;i++){ // for the ith iteration, get the combination of i and k-1 numbers differ from i.
                temp.push_back(i); 
                combine1(i+1,n,k-1,ans,temp);// get the combination of k-1 numbers which range is(i+1,n) 
                temp.pop_back();
            }
        }


};




int main(){
	Solution s;
	vector<vector<int>> a = s.combine2(4,3);
	for(auto & x :a){
		for_each(x.begin(),x.end(),[](int l){ cout << l;});
		cout << endl;
	}


}