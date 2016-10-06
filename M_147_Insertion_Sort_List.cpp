/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 #include <cstdio>
 #include <iostream>
 using namespace std;
class ListNode {
public:
      int val;
      ListNode *next;
      ListNode(int x,ListNode* n) : val(x),next(n) {}
 };
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
    	if (!head) return nullptr;
    	ListNode* pre = new ListNode(-1,head);
    	ListNode* cur = head;
    	ListNode* start = pre;
    	ListNode** pivot = &(cur ->next);

    	while(*pivot){
    		while(head != *pivot){
    			//operator precedence
    			int pv = (*pivot) ->val;
    			if(pv > pre -> val && pv < head -> val){
    				ListNode* temp = *pivot;
    				*pivot = (*pivot) -> next;
    				pre -> next = temp;
    				temp -> next = head;
    				break;
    			}else if (pv > head -> val && pv < head -> next -> val){
    				ListNode* temp = *pivot;
    				*pivot = (*pivot) -> next;
    				temp -> next = head -> next;
    				head -> next = temp;
    				break;
    			}else{
    				head = head -> next;
    				pre = pre -> next;
    			}
    		}
    		head = start;
    		pivot = &((*pivot) -> next);
    	}
    	return pre->next;
    }
    void swap(int * a , int * b){
    	int temp = *a;
    	*a = *b;
    	*b = temp; 
    }
    void insertionArray(int * array,int size){
    	for(int i = 1; i < size; ++i){
    		int j = i;
    		while(j > 0 && array[j-1] > array[j]){
    			swap(&array[j-1],&array[j]);
    			j -= 1;
    		}
    	}
    }
};

int main(){
	Solution s;
	int arr[] = {12, 11, 13, 5, 6,4,3,2,1};
	int n = 0;
	s.insertionArray(arr,n=sizeof(arr)/sizeof(int));

	for (int i=0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");


	ListNode n4(6,NULL);
	ListNode n5(5,&n4);
	ListNode n6(13,&n5);
	ListNode n7(11,&n6);
	ListNode n8(12,&n7);

	ListNode * check = s.insertionSortList(&n8);

	while(check){
		cout << check->val<< " ";
		check = check -> next; 
	}

}