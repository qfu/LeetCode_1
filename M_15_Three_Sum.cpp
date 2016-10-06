#include <vector>
#include <map>
#include <set>
#include <iostream>
using namespace std;


ostream & operator<<(ostream& o, vector<int> v){
    for(int a :v) o <<a;
    return o << endl; 
}

class Solution {
public:
    vector<vector<int>> twoSum(vector<int> nums, int target) {
        vector<vector<int>> v;
        map<int,int> temp;
            
        for(int i = 0; i < nums.size();){
            if(temp.find(nums[i]) != temp.end() && i != temp[nums[i]] ){
                int index = temp[nums[i]];
                vector<int> pair;
                pair.push_back(nums[i]);
                pair.push_back(nums[index]);
                nums.erase(nums.begin() + i);
                nums.erase(nums.begin() + index);
                v.push_back(pair);
                i = 0;
            }
            else{
                temp.insert({target - nums[i],i});
                ++i;
            }
        }

        return v;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> v;
        set<vector<int>> s;
        vector<vector<int>> result;
        vector<int> copy = nums;
        if (!nums.size()) return v;
        
        for(int i =0; i < copy.size(); ++i){
            copy.erase(copy.begin()+i);
            int target = 0 - nums[i];
            result = twoSum(copy,target);
            for_each(result.begin(),result.end(),[&](vector<int> & a){
                a.push_back(nums[i]);
                sort(a.begin(),a.end());
            });
            s.insert(result.begin(),result.end());
            copy = nums;
        }

        for(auto it = s.begin(); it != s.end();++it) v.push_back(*it);

        return v;
        
    }
};

int main(int argc, char**argv){

    std::vector<int> v = {4,1,7,2,6,3,5};
    std::vector<int> v2 = {-2,0,2,2,2,2,2};
    Solution s;
    std::vector<vector<int>> test = s.twoSum(v,8);
    std::vector<vector<int>> test2 = s.threeSum(v2);
    for_each(test.begin(),test.end(),[](vector<int> a){ for(int i =0; i < a.size();cout<<a[i],++i);});
    cout << endl;
        for_each(test2.begin(),test2.end(),[](vector<int> a){cout <<a; });


    return 0;
}