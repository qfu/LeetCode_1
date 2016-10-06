#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = m; i< (m+n);++i) nums1[i] = nums2[i-m];
        sort(nums1.begin(),nums1.end());
        
    }
};

int main(int argc, char ** argv){
	std::vector<int> v = {1,2,3};
	v.insert(v.begin(),8);
	for_each(v.begin(),v.end(),[](int a){
		cout << a;
	});
}