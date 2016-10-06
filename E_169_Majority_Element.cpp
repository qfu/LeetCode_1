class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> mymap;
        for(int i =0; i< nums.size(); ++i)
            mymap[nums[i]]++;
        
        for(auto it = mymap.begin(); it != mymap.end();++it)
            if( (it -> second)*2 > nums.size()) return it ->first;
        return 0;
    }
};

