#include <iostream>
#include <string>

using namespace std;


#define INDEX(c) ((int)c - (int)'a')
class TrieNode
{
public:
	TrieNode* children[26];
	bool is_leaf;
	char c;
	TrieNode(bool f = false, char s = ' '){
		is_leaf = f;
		c = s;
		//void * memset ( void * ptr, int value, size_t num );
		//ALL Initial to NULL
		memset(children, 0, sizeof(children));
	}
};



class WordDictionary {
private:
	TrieNode* root;
public:

	WordDictionary(){
		root = new TrieNode();
	}

    // Adds a word into the data structure.
    void addWord(string word) {
    	TrieNode* start = root;

    	for(char c : word){
    		if(!start -> children[INDEX(c)]) start -> children[INDEX(c)] = new TrieNode(false,c);
    		start = start -> children[INDEX(c)];
    	}
    	start -> is_leaf = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    //Definitely need to implement a backtrack search


   bool backtrackSearch(TrieNode* node, string word){
   		//if(!node) return false;
   		for(int i = 0; i < 26;++i){
				TrieNode* n = node -> children[i];
				 if(n && search(n,word)) return true;
   		}
		return false;
		}

    bool search(TrieNode* node,string word) {
    	TrieNode* start = node;
    	for(int i = 0; i < word.size(); ++i){
    		if(word[i] == '.'){
					//require lookahead
    			return backtrackSearch(start,word.substr(i+1));
    		}
    		else if(start -> children[INDEX(word[i])]) start = start -> children[INDEX(word[i])];
			else return false;
    	}
    	return start->is_leaf;
    }

    bool search(string word) {
    	return search(root,word);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");


int main(){

	WordDictionary wordDictionary;
	wordDictionary.addWord("word");
	wordDictionary.addWord("wordxyz");
	cout << wordDictionary.search("wor");
	cout << wordDictionary.search("word");
	cout << wordDictionary.search(".or..yz");
}
