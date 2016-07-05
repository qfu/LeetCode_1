
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output: 7 -> 0 -> 8
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class ListNode {
public:
	int val;
	ListNode * next;
	ListNode(int x,ListNode* y): val(x),next(y){}
}; 

class Solution {
public:
	//Poor design 

    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	//encounter overflow
    	
    	/*
    	ListNode* n1 = l1;
    	ListNode* n2 = l2;
    	std::vector<ListNode*> v;
    	int cout1 = 1;
    	int sum1 = 0;
    	int cout2 = 1;
    	int sum2 = 0;
    	//Kind of similar to do while loop
        for(;;){
        	sum1 += n1->val*cout1;
        	cout1*=10;
        	if (n1-> next)
				n1 = n1 -> next;
			else 
				break;
        }

		do{
			sum2 += n2->val*cout2;
        	cout2*=10;
	        n2 = n2 -> next;
	    }while(n2);
	    int returnValue = sum1 + sum2;
	    string s = to_string(returnValue);
	    for(int i = s.size()-1; i >= 0;i--){
	    	//cout << (int)(s[i]-'0') << endl;
	    	if(i == s.size() -1 ){
	    		v.push_back(new ListNode((int)(s[i]-'0'),NULL));
	    		continue;
	    	}
	    	ListNode* head =  v.back();
	    	v.pop_back();
	    	v.push_back(new ListNode((int)(s[i]-'0'),head));
	    }
	    ListNode* returnNode = v.back();
	    return returnNode;
	    */
	    ListNode* c1 = l1;
        ListNode* c2 = l2;
        ListNode* sentinel = new ListNode(0);
        ListNode* d = sentinel;
        int sum = 0;
        while (c1 || c2 ) {
            sum /= 10;
            if (c1) {
                sum += c1 ->val;
                c1 = c1->next;
            }
            if (c2) {
                sum += c2 ->val;
                c2 = c2 ->next;
            }
            //This make sure it's always single digit 
            d->next = new ListNode(sum % 10);
            d = d->next;
        }
        // if there is still carry-on but exceeds the digit of either c1 or c2
        //create an new node 
        if (sum / 10 == 1)
            d -> next = new ListNode(1);
        return sentinel ->next;
    }
};

int main(int argc, char ** argv){
	ListNode n1(6,NULL);
	ListNode n2(0,&n1);
	ListNode n3(2,&n2);

	ListNode n4(9,NULL);
	ListNode n5(1,&n4);
	ListNode n6(2,&n5);

	ListNode* check = Solution::addTwoNumbers(&n3,&n6);

	do{	
		cout << check -> val<< endl;
		check = check->next;
	}while(check);


}