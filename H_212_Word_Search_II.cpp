#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

#define INDEX(c) ((int)c -(int)'a')

class TrieNode{
public:
	TrieNode* children[26];
	bool isleaf;
	TrieNode(bool b=false){
		memset(children,0,sizeof(children));
		isleaf = b;
	}	
};

class Trie{
private: 
	TrieNode* root;
public:
	Trie(){
		root = new TrieNode();
	}

	void insert(string word){
		TrieNode* start = root;
		for(char c: word){
			if(!start->children[INDEX(c)]) 
				start->children[INDEX(c)] = new TrieNode();
			start = start->children[INDEX(c)];
		}
		start->isleaf = true;
	}

	bool search(string word){
		TrieNode* start = root;
		for(char c : word)
			if(start) start = start->children[INDEX(c)];
		return start != NULL && start->isleaf;
	}

	bool prefix(string prefix){
		TrieNode* start = root;
		for(char c: prefix){
			if(start) start = start->children[INDEX(c)];
		}
		return start != NULL;
	}	
	TrieNode* getRoot(){
		return root;
	}
};


class Solution {

private:

	bool backtrack(vector<vector<char>>& board, int i, int j, int index, int n,int m,TrieNode* root,set<string>& result, string word){

		if(i < 0 || j < 0 || i >= n || j >= m || board[i][j] == '-') return false;

		// Using Trie to search instead of individual words  which will cause O(n^3)
		if(root->children[INDEX(board[i][j])]){
			word += board[i][j];
			root = root->children[INDEX(board[i][j])];
			if(root -> isleaf) result.insert(word);
			char back = board[i][j];
			//after search is done everything is set back
			board[i][j] = '-';
			//never return true
			if(backtrack(board,i-1,j,index+1,n,m,root,result,word) || backtrack(board,i+1,j,index+1,n,m,root,result,word) || backtrack(board,i,j-1,index+1,n,m,root,result,word) || backtrack(board,i,j+1,index+1,n,m,root,result,word))
				return true;
			//always restore the board
			board[i][j] = back;
		}
		return false;
	}

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
       	Trie* t = new Trie(); 
 		set<string> result;
 		if(!words.size()) return vector<string>();
       	for(string s:words) t->insert(s);

       	TrieNode* root = t->getRoot();
   		
   		int n = board.size();
		int m = board[0].size();

		string word;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				backtrack(board,i,j,0,n,m,root,result,word); 
			}
		}
       	return vector<string>(result.begin(),result.end());
    }
};

int main(int argc, char **argv){
	vector<string> words = {"oath","pea","eat","rain"};
	
	vector<vector<char>> board = {
  		{'o','a','a','n'},
  		{'e','t','a','e'},
  		{'i','h','k','r'},
  		{'i','f','l','v'},
	};

	Solution s;
	s.findWords(board,words);

}