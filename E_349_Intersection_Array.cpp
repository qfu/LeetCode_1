#include <iostream>
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        if(!nums1.size() || !nums2.size()) return v;

        unordered_set<int> first(nums1.begin(), nums1.end());
        unordered_set<int> second(nums2.begin(),nums2.end());
        for (const int & x: first){
            auto result = second.find (x);
            if ( result == second.end()) continue;
            else v.push_back(x);
        }

        return v;
    }
};