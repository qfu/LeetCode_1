#include <string>
#include <unordered_set>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;


class Solution2{
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        wordDict.insert(endWord);
        queue<string> toVisit;
        addNextWords(beginWord, wordDict, toVisit);
        int dist = 2;
        while (!toVisit.empty()) {
            int num = toVisit.size();
            for (int i = 0; i < num; i++) {
                string word = toVisit.front();
                toVisit.pop();
                if (word == endWord) return dist;
                addNextWords(word, wordDict, toVisit);
            }
            dist++;
        }
        return 0;
    }
private:
    void addNextWords(string word, unordered_set<string>& wordDict, queue<string>& toVisit) {
        wordDict.erase(word);
        cout << "-------"<< word << "---------" << endl;
        for (int p = 0; p < (int)word.length(); p++) {
            char letter = word[p];
            for (int k = 0; k < 26; k++) { 
                word[p] = 'a' + k;
                if (wordDict.find(word) != wordDict.end()) {
                	cout << word << endl;
                    toVisit.push(word);
                    wordDict.erase(word);
                }
            }
            word[p] = letter;
        } 
    } 
};


class Solution {
public:


	void backtrack(unordered_set<string>& wordList, string beginWord, string endWord,set<string>& v, int index,string str,int size){
		//base case

		if(beginWord == endWord){
			return;
		}
		for(int i = index; i < size; ++i){
			for(char c = 'a'; c < 'z'; ++c){
				//make sure change start from the begin
				str = beginWord;
				str[i] = c;
	
				if (wordList.find(str) != wordList.end()){
					cout << str<<endl;
					wordList.erase(str);
					//if(v.find(str) != v.end()) continue;
				 	v.insert(str);
					return backtrack(wordList,str,endWord,v, (index+1)%size,str,size);
				}
			}
		}
	}




    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
	   set<string> v;
	   string str = "";

	   //wordList.erase(beginWord);
	   //wordList.erase(endWord);
       backtrack(wordList,beginWord,endWord,v,0,str,beginWord.size());
       //unique(v.begin(),v.end());
       for_each(v.begin(),v.end(),[](string s){ cout << s;});
       return v.size();
    }
};



int main(){
	Solution2 s;
	
	unordered_set<string> wordList = {"hot","dot","dog","lot","log"};
	string start = "hit" ;
	string end =  "cog";
	/*
	unordered_set<string> wordList = {"a","b","c"};
	string start = "a";
	string end  =  "c";*/
	cout << s.ladderLength(start,end,wordList);
	return 0;
}