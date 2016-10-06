#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool binarySearch(vector<int>& vec, int target, int start, int end){
		if(start <= end){
			int mid = (start + end) / 2;

			if(vec[mid] == target) return true;

			if (vec[mid] > target) return binarySearch(vec,target,start, mid-1);
			else return binarySearch(vec,target,mid+1,end); 
		}
		return false;
	}	


    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    	int n = matrix.size();
    	if(!n) return false;
    	int m = matrix[0].size();
		if(!m) return false;
		cout << n;
    	for(int i = 0; i < n; ++i){
    		if(matrix[i][0] == target) return true;
    		if(matrix[i][0] > target && i -1 >= 0) return binarySearch(matrix[i-1],target,0,m-1);
    	}
    	return binarySearch(matrix[n-1],target,0,m-1);
        
    }
};



int main(){

  std::vector<int> v1 = {1,3};
  //std::vector<int> v2 = {10, 11, 16, 20};
  //std::vector<int> v3 =  {23, 30, 34, 50};
  std::vector<vector<int>> test = {v1};
  Solution s;
  cout << s.binarySearch(v1,3,0,1);

}