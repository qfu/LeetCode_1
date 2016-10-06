#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;


class Solution {
public:
    void reverseWords(string &s) {
        if(!s.size()) return;
        
        //remove duplicates 0s 
        auto predicate = [](char i, char j)->bool{ return i ==' ' && j == ' ';};
        auto it = std::unique (s.begin(), s.end(),predicate);            
        s.resize( std::distance(s.begin(),it));

        
        int size = s.size();
        if(s[0]==' ') s.erase(0,1);
        //adding space for concatenation
        if(s[size-1] != ' ') s += ' ';

        stack<string> stack;
        string returnS;
        string str = s;
        std::size_t found = str.find_first_of(' ');

        while(found!= string::npos){
            stack.push(str.substr(0,found));
            str = str.substr(found+1);
            found = str.find_first_of(' ');
        }
        int staS = stack.size();
        cout << staS;

        while(staS){
            returnS += stack.top();
            //remove trailing 0
            if(staS!=1)returnS += ' ';
            stack.pop();
            staS--;
        }
        //remove leading 0
        if(returnS[0]==' ') returnS.erase(0,1);
        s = returnS;
        return;
    }
};


int main(int argc, char ** argv){

    Solution s;

    string test = " 1   2 ";
 
    s.reverseWords(test);

    cout << "result"<< endl;
    cout << test << endl;

    return 0;
}