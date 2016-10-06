class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.size() && !magazine.size()) return false;
        
        unordered_map<char,int> map;
        
        for(int i =0; i < magazine.size();++i) map[magazine[i]]++;
        
        for(char a: ransomNote){
            if(!map[a]) return false;
            else map[a]--;
        }
        return true;
    
    }
};