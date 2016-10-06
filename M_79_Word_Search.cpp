#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(!word.size() || !board.size()) return false;

        bool f = false;
        int n = board.size();
        int m = board[0].size();

        //not every space efficient;
        vector<vector<bool>> table(n,vector<bool>(m,false));
        vector<vector<bool>> false_table(n,vector<bool>(m,false));
        char start = word[0];	
        vector<pair<int,int>> vec;
        for(int i = 0; i < n; ++i){	
        	for(int j = 0; j < m;++j){
        		if(board[i][j] == start) vec.push_back(make_pair(i,j));
        	}
        }
        
        for(auto & it : vec){
	        f |= backtrack(board,word,it.first,it.second,n,m,0,table);
	        table = false_table;
        }
       
        return f;
    }

    bool backtrack(vector<vector<char>>& board, string word, int i, int j,int n, int m,int pos,vector<vector<bool>>& table){
    	if(pos == word.size()) return true;
    	//base case	
    	if(i < 0 || i >= n || j < 0 || j >= m || board[i][j] != word[pos]|| table[i][j]){
    		if (i >= 0 && i < n && j >= 0 && j >= m && !table[i][j]) table[i][j] = false;
    		return false;
    	}
		 
		table[i][j] = true;
    	//four directions 

    	if (backtrack(board,word,i - 1,j,n,m,pos+1,table) || backtrack(board,word,i + 1,j,n,m,pos+1,table) || backtrack(board,word,i,j + 1,n,m,pos+1,table) || backtrack(board,word,i,j - 1,n,m,pos+1,table))
    		return true;

    	return false;
    }


};




int main(int argc, char ** argv){
	std::vector<char> v1 = {'C','A','A'};
	std::vector<char> v2 = {'A','A','A'};
	std::vector<char> v3 = {'B','C','D'};


 	std::vector<vector<char>> test = {v1,v2,v3};


 	Solution s;

 	string w1 = "AAB";
 	string w2 = "SEE";
 	string w3 = "ABCB";

 	cout <<  s.exist(test,w1);
 	//cout <<  s.exist(test,w2);
 	//cout <<  s.exist(test,w3);


}