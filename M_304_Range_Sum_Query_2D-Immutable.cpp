#include <vector>
#include <iostream>
using namespace std;

class NumMatrix {
private:
	vector<vector<int>> mat;
public:
    NumMatrix(vector<vector<int>> &matrix) {
    	int n = matrix.size();
    	int m = matrix[0].size();

    	mat.resize(n,vector<int>(m,0));
    	//Doesn't work on C array
    	//mat = new int[n][m]; memset(mat,0,sizeof(mat));
        for(int i = 0 ; i < n; ++i){
        	for(int j = 0; j < m; ++j){
        		if(i == 0 && j ==0) mat[i][j] = matrix[i][j];
        		else if(i == 0 && j !=0) mat[i][j] = mat[i][j-1] + matrix[i][j];
        		else if(i != 0 && j ==0) mat[i][j] = mat[i-1][j] + matrix[i][j];
        		else{
        			mat[i][j] = mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1] + matrix[i][j]; 
        		}
        	}
        }

    }

    int sumRegion(int row1, int col1, int row2, int col2) {
    	if(row1 - 1 >= 0 && col1 - 1 >= 0)
    		return mat[row2][col2] - mat[row1-1][col2] - mat[row2][col1-1] + mat[row1-1][col1-1];
    	else if(row1 - 1 < 0 && col1 - 1 >= 0)
    		return mat[row2][col2] - mat[row2][col1-1];
    	else if(row1 - 1 >= 0 && col1 - 1 < 0)
    		return mat[row2][col2] - mat[row1-1][col2];
    	else
    		return mat[row2][col2];
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);

int main(int argc, char const *argv[])
{
	/* code */
	vector<vector<int>> matrix = {{3,0,1,4,2},{5,6,3,2,1},{1,2,0,1,5},{4,1,0,1,7},{1,0,3,0,5}};
	NumMatrix numMatrix(matrix);
	//sumRegion(2, 1, 4, 3) -> 8
	//sumRegion(1, 1, 2, 2) -> 11
	//sumRegion(1, 2, 2, 4) -> 12
	cout << numMatrix.sumRegion(2, 1, 4, 3);
	cout << numMatrix.sumRegion(1, 2, 2, 4);
	return 0;
}