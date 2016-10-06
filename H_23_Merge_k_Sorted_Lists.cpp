/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x,ListNode* n) : val(x), next(n) {}
};



class Solution {
public:
	ListNode* mergeTwolist(ListNode* l1, ListNode* l2){
		if (l1 == nullptr) return l2;
		if (l2 == nullptr) return l1;

		//return the smaller value
		if (l1 -> val < l2 -> val){
			l1 -> next = mergeTwolist(l1 -> next,l2);
			//return to upper level 
			return l1;
		}else{
			l2 -> next = mergeTwolist(l1,l2 -> next);
			return l2;
		}

	}

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (!lists.size()) return NULL;
        if (lists.size() <= 2) return mergeTwolist(lists[0],lists[1]);

        ListNode* start = mergeTwolist(lists[0],lists[1]);

        for(int i = 2; i < lists.size();++i){
        	start = mergeTwolist(start,lists[i]);
        }
        return start;
    }
};

int main(int argc, char ** argv){
	int myints[] = {32,71,12,45,26,80,53,33};
  	std::vector<int> myvector (myints, myints+8); 
    std::sort (myvector.begin(), myvector.end(), [](int i, int j ){return i>j;}); // 12 32 45 71(26 33 53 80)
    //cout << for_each(myvector.begin(), myvector.end(),[](int i){ cout << i;});
	return 0;
}