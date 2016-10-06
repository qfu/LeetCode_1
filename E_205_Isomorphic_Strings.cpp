class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
    	unordered_map<char,char> mymap;
    	unordered_map<char,char> strmap;
    	bool check = true;

    	for(int i =0 ; i < s.size(); ++i){
    		if(mymap.find(s[i]) != mymap.end() || strmap.find(t[i]) != strmap.end()){
    			check  &= mymap[s[i]] == t[i];
    			check  &= strmap[t[i]] == s[i];
    		}
    		else{
    			mymap[s[i]] = t[i];
    			strmap[t[i]] = s[i];
    		}
    	}

        return check;
    }
};

int main(){
    
}