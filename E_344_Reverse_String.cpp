#include <iostream>
class Solution {
    public:
        string reverseString(string s) {
            string returnString;

            for (int i = s.size()-1; i >= 0; i--){
                returnString+=s[i];
            }
            return returnString;
        }
};
