#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

class Solution {
public:

    vector<string> findRepeatedDnaSequences(string s) {
        list<string> list;
        std::vector<string> v;
    	std::set<string> set;
    	if(s.size() <= 10) return v;

    	for(int i = 0; i< s.size()-10;++i){
    		list.push_back(s.substr(i,10));
    		list.unique();
    	}
    	cout << list.size() << endl;
    	
    	for (auto & item : list){
		    size_t found = s.find(item);
		  	if (found!=std::string::npos)
				found=s.find(item,found+1);
		  	if (found!=std::string::npos)
		  		set.insert(item);
    	}
    	for (auto & ele : set){
    	    v.push_back(ele);
    	}
    	return v;
    }
        
   	
};


int main(int argc, char ** argv){
	string str ("There are two needles in this haystack with needles.");
	string str2 ("needle");

 	std::size_t found = str.find(str2);
  	if (found!=std::string::npos)
    	std::cout << "first 'needle' found at: " << found << '\n';

  	found=str.find(str2,found+1);
  	if (found!=std::string::npos)
    	std::cout << "second 'needle' found at: " << found << '\n';

	found=str.find(str2,found+1);
  	if (found!=std::string::npos)
    	std::cout << "Third 'needle' found at: " << found << '\n';
    else 
    	cout << "Not found" << endl;
	return 0;
}