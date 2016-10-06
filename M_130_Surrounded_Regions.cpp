#include <vector>
#include <iostream>
#include <queue>
#include <utility>

using namespace std;





/* 
int find(int parent[], int i)
{
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

// A utility function to do union of two subsets
void Union(int parent[], int x, int y)
{
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}*/







class Solution {
private:
	vector<pair<int,int>> BFS(vector<vector<char>>& board, int i, int j,int m, int n,vector<vector<bool>>& table){
		queue<pair<int,int>> q;
		vector<pair<int,int>> vec;
  		q.push(make_pair(i,j));
		int x,y;

		while(!q.empty()){
			pair<int,int> start = q.back(); 
			vec.push_back(start);
			q.pop();
			x = start.first;
			y = start.second;
			table[x][y] = false;
			if (x - 1 >= 0 && board[x-1][y] =='O' && table[x-1][y]) q.push(make_pair(x-1,y));
			if (x + 1 < m && board[x+1][y] =='O' && table[x+1][y]) q.push(make_pair(x+1,y));
			if (y - 1 >= 0 && board[x][y-1] =='O' && table[x][y-1]) q.push(make_pair(x,y-1));
			if (y + 1 < n && board[x][y+1] == 'O' && table[x][y+1]) q.push(make_pair(x,y+1));
		}
		return vec;
	}

	void surrond(const vector<pair<int,int>> & v, int m, int n,vector<vector<char>>& board){
		for(auto & x : v){
			if (x.first == 0 || x.second == 0 || x.first == m -1 || x.second == n -1 )
				return;  
		}
		for(auto & x : v){
			board[x.first][x.second] = 'X';
		}
		return;

	}


public:
    void solve(vector<vector<char>>& board) {
    	if(!board.size()) return;


    	int n = board.size();
    	int m = board[0].size();
    	vector<vector<bool>> table(n,vector<bool>(m,true));
   

    	vector<pair<int,int>> result;
    	for(int i = 0;i < n; ++i){
    		for(int j = 0; j < m; ++j){
    			if (board[i][j] == 'O'){
    				result = BFS(board,i,j,m,n,table); 
    				surrond(result,m,n,board);
    			}
    		}
    	}
		return;        
    }
};



int main(){
	std::vector<char> v1 = {'X','X','X','X'};
	std::vector<char> v2 = {'X','O','O','X'};
	std::vector<char> v3 = {'X','X','O','X'};
	std::vector<char> v4 = {'X','O','X','X'};

	vector<vector<char>> board = {v1,v2,v3,v4};

	Solution s;
	s.solve(board);


	for(auto & vec: board){
		for(auto & ele : vec){
			cout << ele << " ";
		}
		cout << endl;
	}


}