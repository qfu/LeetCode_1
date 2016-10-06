/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */



#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
class RandomListNode{
public:
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x,RandomListNode* n, RandomListNode* r): label(x), next(n),random(r){}

};



class Solution {
public:
	
 	int randomeNodeIndex(RandomListNode* head, RandomListNode* node){
 		if(node == NULL) return -1;
 		int pos = 0;
 		RandomListNode* start = head;
 		RandomListNode* cur = node;
 		while(start && start != node){
 			start = start -> next;
 			pos++;
 		}
 		return pos;
	}

/*
	RandomListNode* findRandomNode(RandomListNode* head,int iteration){
		RandomListNode* copy  = head;
		while(iteration--){
			copy = copy -> next;
		}
		return copy;
	}*/


    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode* h_p = head;
        RandomListNode* c_p = head;
        queue<RandomListNode*> q;
        unordered_map<int,RandomListNode*> deep;
        unordered_map<int,RandomListNode*> shadow;

        if (head == nullptr) return nullptr;
        while(h_p){
			RandomListNode* node = new RandomListNode(h_p -> label,nullptr,nullptr);
			q.push(node);
        	h_p = h_p -> next;
        	//else break;
        }
        //Getting the head of copy list 
        RandomListNode* front = q.front();
        RandomListNode* front_p  = front;
        RandomListNode* front_p2  = front;
        int position = 0;
        deep.insert({position,front});
        q.pop();


        while(q.size()){
        	RandomListNode* current = q.front();
        	q.pop();
        	deep.insert({++position,current});
        	front -> next = current;       	
        	front = current;
        }

  
        
        while(c_p && front_p){
        	int index = randomeNodeIndex(head,c_p->random);
        	auto find = deep.find(index);
        	if (find != deep.end())
        		front_p -> random = find -> second;
        	else 
        		front_p -> random = nullptr;


        	/*This part is obvious redundent */
        	//if (c_p -> next && front_p -> next){
	       	c_p = c_p ->next;
	       	front_p = front_p -> next;
        	//}
        	//else break; 
        }

        return front_p2;


    }
};




int main(int argc ,char ** argv){
	RandomListNode* n1 = new RandomListNode(1,NULL,NULL);
	RandomListNode* n2 = new RandomListNode(2,NULL,NULL);
	RandomListNode* n3 = new RandomListNode(3,NULL,NULL);
	RandomListNode* n4 = new RandomListNode(4,NULL,NULL);
	RandomListNode* n5 = new RandomListNode(5,NULL,NULL);
	RandomListNode* n6 = new RandomListNode(6,NULL,NULL);


	n6 -> next = n5;
	n5 -> next = n4;
	n4 -> next = n3;
	n3 -> next = n2;
	n2 -> next = n1;
	n1 -> next = NULL;


	n6 -> random = n5;
	n5 -> random = n6;
	n4 -> random = n6;
	n3 -> random = n1;
	n2 -> random = n4;
	n1 -> random = n2;


	Solution s;
	RandomListNode* result =  s.copyRandomList(n6);
	RandomListNode* check = n6;

	while(check){
		cout << "Node" <<check -> label << endl;
		cout << "Random" << check -> random -> label << endl;
		if (check -> next)check = check -> next;
		else break;
	}

	cout << "---------------------" << endl;
 
	while(result){
		cout <<"Node"<< result -> label << endl;
		cout <<"Random" << result -> random ->label << endl;
		if (result -> next)result = result -> next;
		else break;
	}


	return 0;
}