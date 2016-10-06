#include <iostream>
#include <vector>
#include <climits>

using namespace std;

ostream& operator<<(ostream & o,vector<int> v){
    for(int i : v) o << i;
    o << endl;
    return o;
}

class Solution {
public:
	int minValue(vector<int>& vec, int * start){

		int value = *start;

		int temp = vec[value];
		if(value - 1 >= 0){ 
			if(vec[value-1] < temp){
				temp = vec[value-1];
				(*start) = value -1;
			}
		}

		if(value + 1 < vec.size()){
			if(vec[value+1] < temp){
				temp = vec[value+1];
				(*start) = value +1;
			}
		}
		return temp;

	}



	vector<int> dpMin(vector<vector<int>>& tri, vector<vector<int>>& result,int size){
		result.push_back(tri[0]);

		//need the two dimentinoal vector
		for(int i = 1; i < size;++i){
			result.push_back(tri[i]);
			for(int j = 0; j < tri[i].size();++j){
				if(j < tri[i-1].size() && j -1 >= 0 ){
					result[i][j] = tri[i][j] + result[i-1][j];
					result[i][j] = min(result[i][j],tri[i][j] + result[i-1][j-1]);
				}
				else if(j < result[i-1].size()) result[i][j] = tri[i][j] + result[i-1][j];
				else if(j -1 >= 0) result[i][j] = tri[i][j] + result[i-1][j-1];
			}
		}
		//sort(result.begin(),result.end());

		return result[size-1];
	}


    int minimumTotal(vector<vector<int>>& triangle) {
        int size = triangle.size();
        int sum = 0;
        vector<vector<int>> result;
        vector<int> end;
        //int start = 0;
        end = dpMin(triangle,result,size);
  		sort(end.begin(),end.end());
  		return *end.begin();
        //return sum;
    }
};


int main(){


	vector<int> v1={2};
	vector<int> v2={3,4};
	vector<int> v3={6,5,7};
	vector<int> v4={4,1,8,3};

	vector<vector<int>> test1 = {v1,v2,v3,v4};

	Solution s;
	cout << s.minimumTotal(test1);

}