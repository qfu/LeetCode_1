#include <vector>
#include <iostream>
#include <utility>

using namespace std;

ostream & operator<<(ostream & o, vector<int> v){
	for(int i : v) o << i<<" ";
	return o << endl;
}



class Solution {
public:


	void backtrack(vector<vector<int>>& matrix,vector<vector<bool>>& table, vector<int>& result, int i, int j, int n, int m){
			
		result.push_back(matrix[i][j]);
		table[i][j] = true;
		while(result.size() != (n*m)){
			if(j + 1 < m && !table[i][j+1])
				backtrack(matrix,table,result,i,j+1,n,m);
			else if(i + 1 < n && !table[i+1][j])
				backtrack(matrix,table,result,i+1,j,n,m);
			else if(j - 1 >= 0 && !table[i][j-1])
				backtrack(matrix,table,result,i,j-1,n,m);
			else if(i - 1 >= 0 && !table[i-1][j])
				backtrack(matrix,table,result,i-1,j,n,m);
		}
		return;

	}


    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int n = matrix.size();
        if (n == 0) return result;
        int m = matrix[0].size();


        vector<vector<bool>> table(n,vector<bool>(m,false));

        backtrack(matrix,table,result,0,0,n,m);


        return result;

    }



    vector<int> spiralOrder2(vector<vector<int>>& matrix) {
        vector<int> result;
        int n = matrix.size();
        if (n == 0) return result;
        int m = matrix[0].size();


        pair<int,int> right = {0,m};
        pair<int,int> down = {1,n};
        pair<int,int> left = {m-1,0};
        pair<int,int> up = {n-1,1};

       //	for (int j = 0; j < n * m;){
       while(1){
       	    //cout <<	"x" << right.first;
       		//cout << "y" << right.second;
       		for (int a = right.first; a < right.second; ++a){
       			cout << matrix[up.second-1][a] << " ";
       			result.push_back(matrix[up.second-1][a]);
       			//++j;
       		}
       		right.first++;
       		right.second--;

       		if (result.size() == n * m) break;

       		cout << endl;

       		for (int b = down.first; b < down.second; ++b){
       			cout << matrix[b][right.second] << " ";
       			result.push_back(matrix[b][right.second]);
       			//++j;
       		}
       		down.first++;
       		down.second--;

       		cout << endl;

       		if (result.size() == n * m) break;

       		for (int c = left.first-1; c >= left.second; --c){
       			cout << matrix[down.second][c]<< " ";
       			result.push_back(matrix[down.second][c]);
       			//++j;
       		}
			left.first--;
       		left.second++;

       		cout << endl;
       		if (result.size() == n * m) break;


       		for (int d = up.first -1; d >= up.second; --d){
       			cout << matrix[d][left.second-1] << " ";
       			result.push_back(matrix[d][left.second-1]);
       			//++j;	
       		}
			up.first--;
       		up.second++;

       		cout << endl;
       		if (result.size() == n * m) break;

       	}
       	return result;
    }




};



int main(int argc, char** argv){
	std::vector<int> v1 = {1,2,3,4,-1};
	std::vector<int> v2 = {5,6,7,8,-2};
	std::vector<int> v3 = {9,10,11,12,-3};
	std::vector<int> v4 = {13,14,15,16,-4};
	std::vector<int> v5 = {17,18,19,20,-5};
	Solution s;
	std::vector<vector<int>> test = {v1,v2,v3,v4,v5};

	s.spiralOrder2(test);


	return 0;
}