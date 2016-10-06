#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
	double findKSmallest(vector<int>& nums1, vector<int>& nums2, int a, int b, int k){
		if(a >= nums1.size())
			return nums2[b + k -1];
		if(b >= nums2.size())
			return nums1[a + k -1];

		// a contribute to less than k/2's element move b's pointer
		int compare_a = (a+ k/2 -1) >= nums1.size() ?  INT_MAX : nums1[a+ k/2 -1];
		int compare_b = (b+ k/2 -1) >= nums2.size() ?  INT_MAX : nums2[b+ k/2 -1];

		if(compare_a > compare_b){
        	findKSmallest(nums1, nums2, 0, b+k/2,k-k/2);

		}else{
		    findKSmallest(nums1, nums2, a + k/2, 0,k-k/2);
		}

	}


public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int sum = m + n;

        if(sum & 1){
        	//this is odd
        	return findKSmallest(nums1, nums2, 0, 0,sum/2+1);
        }else{
        	//this is even
        	return (findKSmallest(nums1, nums2, 0, 0,sum/2) + findKSmallest(nums1, nums2, 0, 0,sum/2+1))/2;
        }

    }
};


int main(){


	return 0;
}