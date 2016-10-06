#include <unordered_set>
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

#define CONV(c) ((int)c - (int)'a')
using namespace std;


class Solution {
private:
	bool buildTree(unordered_set<string>& forward, unordered_set<string>& backward, unordered_set<string>& dict, unordered_map<string, vector<string>>& tree, bool reversed){
		//no more words in the dict
		// no next level 
		if(forward.empty()) return false;
		if(forward.size() > backward.size())
			return buildTree(backward,forward,dict,tree,!reversed);
		for(auto & word: forward) dict.erase(word);
		for(auto & word: backward) dict.erase(word);
		unordered_set<string> nextLevel;
		bool done  = false;
		//traverse the queue
		for(auto & it : forward){
			string word = it;
			//for each digit
			for(auto & c: word){
				char c0 = c;
				for(c = 'a'; c <= 'z';++c){
					if(c != c0){
						if(backward.count(word)){
							done = true;
							//bulid the tree backward but have to make sure the same tree
							!reversed ? tree[it].push_back(word): tree[word].push_back(it);
						}
						else if(!done && dict.count(word)){
							//next level queue, level order traverse
							nextLevel.insert(word);
							!reversed ? tree[it].push_back(word): tree[word].push_back(it);

						}
					}
				}
			//switching to the next bit   one bit at a time
			c = c0;
			}
		}
		//level order traversal 
		return done || buildTree(nextLevel,backward,dict,tree,reversed);
	}
	//DFS to retrive the path
	void getPath(string & beginWord, string & endWord,unordered_map<string, vector<string>>& tree, vector<string> &path, vector<vector<string> > &paths){
		if(beginWord == endWord) paths.push_back(path);
		else{
			for(auto & it : tree[beginWord]){
				path.push_back(it);
				getPath(it,endWord,tree,path,paths);
				path.pop_back();
			}
		}

	}
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
   		vector<vector<string>> v;

   		vector<string> forward;

   		wordList.insert(endWord);



    }
};

int main(int argc, char ** argv){

	return 0;
}