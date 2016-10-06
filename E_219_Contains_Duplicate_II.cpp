
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
       unordered_set<int> s;
       
       if (k <= 0) return false;
       if (k >= nums.size()) k = nums.size() - 1;
       
       for (int i = 0; i < nums.size(); i++)
       {
       		// at most k , when outside K, remove those possible duplicate
           if (i > k) s.erase(nums[i - k - 1]);
           //within k
           if (s.find(nums[i]) != s.end()) return true;
           s.insert(nums[i]);
       }
       
       return false;
    }
};

int main(int argc, char ** argv){

}