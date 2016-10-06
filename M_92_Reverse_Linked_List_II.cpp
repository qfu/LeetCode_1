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
using namespace std;
class ListNode{
public:
	int val;
	ListNode * next;
	ListNode(int x, ListNode* next): val(x),next(next){}
};

std::ostream & operator << (std::ostream & o,  ListNode * r) {
	while(r){
		o << r -> val;
		if (r -> next) r = r -> next;
		else return o << endl;
	}
    return o<<endl;
}

class Solution {
public:
	ListNode* findNode(ListNode* head, int i ){
		int count = 0;
		ListNode* cur = head;
		while(cur){
			if ((++count)  == i ) return cur;

			if (cur -> next) cur = cur -> next;
			else nullptr;
			//return new ListNode(0,NULL);
		}
		return NULL;
	}
	int listLength(ListNode* cur){
		int count = 0;
		while (cur){
			count += 1;
			if (cur -> next) cur = cur -> next;
			else return count;
		}
		return count;
	}

    ListNode* reverseBetween(ListNode* head, int m, int n) {
    	ListNode * cur = head;

    	int ListLength = listLength(cur);
            cout << "enter 2";

        if (n == m) return head;

        if ((n - m) ==1){
            cout << "enter ";
        	ListNode* M = findNode(cur,m);
            ListNode* N = findNode(cur,n);
            ListNode* preM = findNode(cur,m-1);

            if(m==1) {
                cout << "Debug";
                N -> next = M;
                M -> next = findNode(cur,n+1);
                return N;
            }
            else if (n == ListLength){
                N-> next = M;
                M -> next = NULL;
                return head;
            }
            else{
                cout << "again" ;
                preM -> next = N;
                N -> next = M;
                M -> next = findNode(cur,n+1);
            }
        }

        if ( m ==1 && n == ListLength){

        	ListNode* PostStart = findNode(cur,m+1);
        	ListNode* PreEnd = findNode(cur,ListLength-1);
        	ListNode* M = findNode(cur,m);
        	ListNode* N = findNode(cur,n);

        	N -> next = PostStart;
        	PreEnd-> next = M;
        	M -> next = NULL;
        	return N;
        }
        if (m == 1 &&  1<n && n< ListLength){
        	ListNode* PostStart = findNode(cur,m+1);
        	ListNode* PreEnd = findNode(cur,n-1);
        	ListNode* PostEnd = findNode(cur,n+1);
        	ListNode* M = findNode(cur,m);
        	ListNode* N = findNode(cur,n);


        	N -> next = PostStart;
        	PreEnd -> next = M;
        	M-> next = PostEnd;

        	return N;

        }

        if ( 1<m && m< ListLength &&  1<n  && n < ListLength ){

        	ListNode* PreStart = findNode(cur,m-1);
        	ListNode* PostStart = findNode(cur,m+1);
        	ListNode* PreEnd = findNode(cur,n-1);
        	ListNode* PostEnd = findNode(cur,n+1);
        	ListNode* M = findNode(cur,m);
        	ListNode* N = findNode(cur,n);


        	PreStart -> next = N;
        	N -> next = PostStart;

        	PreEnd -> next = M;
        	M -> next = PostEnd;


        	return head;
        }

        if (1 < m && m < ListLength && n == ListLength){
        	ListNode* PreStart = findNode(cur,m-1);
        	ListNode* PostStart = findNode(cur,m+1);
        	ListNode* PreEnd = findNode(cur,n-1);
        	ListNode* M = findNode(cur,m);
        	ListNode* N = findNode(cur,n);


        	PreStart -> next = N;
        	N -> next = PostStart;

        	PreEnd -> next = M;
        	M -> next = 0;


        	return cur;
        }

       	//Most general case 
       	/*
        ListNode* M = findNode(cur,m);
        ListNode* preM = findNode(cur,m-1);
        ListNode* postM = findNode(cur,m+1);

        ListNode* N = findNode(cur,n);
  		ListNode* preN = findNode(cur,n-1);
   	    ListNode* postN = findNode(cur,n+1);

   	    preM -> next = N;
   	    N-> next  = postM;

   	    preN -> next = M;
   	    M -> next = postN;
   	    */


    }
    ListNode * reverseBetween2(ListNode* head, int m, int n){
        ListNode dummy(-1);
        dummy.next = head;

        ListNode* prev = & dummy;
        for (int i =0 ; i< m -1; ++i){
            prev = prev -> next;
        }
        //Landing position of M

        ListNode * const head2 = prev;

        //Cur is M+1
        ListNode* cur = prev -> next;

        for (int i =m ; i < n ; ++i){
            prev -> next = cur -> next;
            cur -> next = head2 -> next;
            head2 -> next = cur;
            cur = prev -> next;
        }
        return dummy.next;

    }
};


int main (int argc, char ** argv){
//1->2->3->4->5->NULL
    vector<int> v = {1,2,3,4,5};
	ListNode n1(5,NULL);
	ListNode n2(4,&n1);
	ListNode n3(3,&n2);
	ListNode n4(2,&n3);
	ListNode n5(1,&n4);

	Solution solver;

	cout << solver.reverseBetween(&n5,1,2);
	

}
