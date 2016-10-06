#include <iostream>
#include <vector>
#include <algorithm>
#include <priority_queue>

using namespace std;


class Solution {
public:

	void sortMatrix(vector<vector<int>>& matrix, vector<int>& v) {
	    auto comp = [&matrix](pair<int, int> p1, pair<int, int> p2){
	        return matrix[p1.first][p1.second] > matrix[p2.first][p2.second];
	    };
	    priority_queue<pair<int, int>, vector<pair<int,int>>, decltype(comp)> que(comp);
	    que.push(make_pair(0, 0));
	    while(!que.empty()){
	         auto temp = que.top();
	         v.push_back(matrix[temp.first][temp.second]);
	         que.pop();
	         if(temp.first+1 < matrix.size()){
	             que.push(make_pair(temp.first+1, temp.second));
	         }
	         if(temp.first == 0 && temp.second+1 < matrix[0].size()){
	             que.push(make_pair(temp.first, temp.second+1));
	         }
	    }
	    return;
	}
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        vector<int> vec;
        /*
    	for_each(matrix.begin(),matrix.end(),[&](vector<int> a){ vec.insert(vec.end(),a.begin(),a.end()); });
    	int end =  vec.size()-1;
    	sort(vec.begin(),vec.end());
    	*/
    	sortMatrix(matrix,vec);
    	return binarySearch(vec,0, end,target);

    }

    bool binarySearch(vector<int>& vec, int start, int end, int target){

    	int mid = (start + end)/2;

    	if(start <= end){
	    	if(vec[mid] == target) return true;
	    	else if(vec[mid] < target) return binarySearch(vec,mid+1,end,target);
	    	else return binarySearch(vec,start,mid-1,target);
		}
		return false;
    }
};

int main(){
	Solution s;

	std::vector<int> v = {1,2,5,6,7,9,11,24,36,58,111,234,333,456,7765,9943};

	cout << s.binarySearch(v,0,v.size()-1,1);
}