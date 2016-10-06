#include <vector>
#include <iostream>
using namespace std;


class Solution {
private:
	void mergeSort(vector<int>& nums, vector<int>& index, vector<int>& count,int start, int end){
		if(start < end){
			int mid = start + (end - start)/2;
			//divide and conquer
			mergeSort(nums,index,count,start,mid);
			mergeSort(nums,index,count,mid+1,end);

			merge(nums,index,count,start,end);
		}
	}

	void merge(vector<int>& nums, vector<int>& index, vector<int>& count,int start, int end){
		int mid = start + (end - start)/2;
		int left = start;
		int right = mid + 1;

		int rightMost = 0;
		int newIndexCount = 0;
		vector<int> newIndex(end-start+1,0);


		while(left <= mid && right <= end){
			//lowest level only runs once 

			if(nums[index[left]] > nums[index[right]]){
				newIndex[newIndexCount] = index[right];
				//keep track of left smaller values
				rightMost++;
				right++;
				newIndexCount++;
			}else if(nums[index[left]] < nums[index[right]]){
				newIndex[newIndexCount] = index[left];
				//before encounter a greater value
				//make sense only left is update because right is larger
				//
				count[index[left]] += rightMost;
				left++;
				newIndexCount++;
			}
		}

		//Either left has leftover or right has leftovers 
		while(left <= mid){
			//update the count 
			newIndex[newIndexCount] = index[left];
			count[index[left]] += rightMost;
			left++;
			newIndexCount++;
		}	

		while(right <= end){
			//those are supposed to be greater
			newIndex[newIndexCount++] = index[right++];
		}
		//make sure upper level is sorted
		//index is updated for the upper level to use
		//
		for(int i = start; i <= end; i++){
			index[i] = newIndex[i - start];
		}
	}


public:
    vector<int> countSmaller(vector<int>& nums) {
    	int size = nums.size();
    	if(!size) return vector<int>();

    	vector<int> count(size,0);
    	vector<int> index(size,0);

    	//index store the correct order but make sure
    	//it keep the original sequence
    	for(int i = 0; i < size;++i){
    		index[i] = i;
    	}

    	mergeSort(nums,index,count,0,size-1);
    	for(int i : count){
    		cout << i  << " " << endl;
    	}

    	return count;
    }
};


int main(int argc, char ** argv){

	std::vector<int> v = {5, 2, 6, 1};
	Solution s;
	s.countSmaller(v);



	return 0;
}