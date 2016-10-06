#include <vector>
#include <iostream>
#include <string>
using namespace std;


class Solution {
public:

	std::vector<vector<string>> v;


    bool isValid(vector<string> &nQueens, int row, int col,int n) {
        //check if the column had a queen before.
       	//for (int i = 0; i != row; ++i)
        //    if (nQueens[i][col] == 'Q')
        //        return false;
        //check if the 45° diagonal had a queen before.
        for (int i = row , j = col; i >= 0 && j >= 0; --i, --j)
            if (nQueens[i][j] == 'Q')
                return false;
        //check if the 135° diagonal had a queen before.
        for (int i = row , j = col; i >= 0 && j < n; --i, ++j)
            if (nQueens[i][j] == 'Q')
                return false;
        for (int i = row , j = col; i < n && j < n; ++i, ++j)
            if (nQueens[i][j] == 'Q')
                return false;
        //check if the 135° diagonal had a queen before.
        for (int i = row , j = col; i < n && j >= 0; ++i, --j)
            if (nQueens[i][j] == 'Q')
                return false;
        return true;
    }

	void backtrack(vector<string> & board,bool* check,int column, int l, int size){
		//base case 
		if(column == size){
			v.push_back(board);
			return;
		}


		for(int row = 0; row < size; ++row){
			if(check[row] && isValid(board,row,column,size)){
				board[row][column] = 'Q';
				//Set false for the next level
				/*
				if(column != 0){
					if (l > 0) check[l - 1] = true;
					if (l < size-1)check[l +1] = true;
				}*/
				//make sure not on the same level
				check[row] = false;
				/*
				if (row > 0) check[row - 1] = false;
				if (row < size-1)check[row+1] = false;
				*/
				backtrack(board,check,column+1,row,size);
				board[row][column] = '.';
				//return back
				check[row] = true;
				
	
			}
		}
		return;
}



    vector<vector<string>> solveNQueens(int n) {
       	vector<string> board = vector<string>(n);
       	for(int i = 0; i < n; ++i){
       		//initilize the string 
       		string & x = board[i] = "";
       		for(int j = 0; j < n; ++j){
       			x += ".";
       		}
       	}
  
  
       	bool* check = new bool[n];
       	for(int i = 0; i < n; ++i) check[i] = true;

       	backtrack(board,check,0,0,n);
       	return v;
    }
};


int main(){

	Solution s;
	vector<vector<string>> v = s.solveNQueens(4);


	for(auto & board :v){
		for(auto & row : board ){
			cout << row << endl;
		}
		cout << endl;
	}

	return 0;
}