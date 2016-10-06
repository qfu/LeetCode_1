#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> v;
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

int main(int argc, char ** argv){
    Solution solver;
    std::vector<int> v1 = {1,1,2,2,3};

    std::vector<int> v2 = {2,3,4};
    for (auto x: solver.intersection(v1,v2)) cout << x;
    return 0;
}