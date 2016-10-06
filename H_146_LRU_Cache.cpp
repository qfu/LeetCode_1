#include <unordered_map>
#include <iostream>

using namespace std;


class Node{
public:
	Node* prev;
	Node* next;
	int key;
	int value;
	Node(int val,int k):value(val),key(k){

	}
	//assume default constructor
};



class DoubleLinkedList{
public:
	Node* head;
	Node* tail;
	Node* sentinel;
	int size;
	int cap;
	DoubleLinkedList(int capacity){
		size = 0;
		sentinel = new Node(-1,-1);
		sentinel -> prev = sentinel;
		sentinel -> next = sentinel;
		head = sentinel;
		tail = sentinel;
		cap = capacity;
	}
	bool isFull(){
		return size == cap;
	}

	// if already in the list, bring it to the front
	// if not in the list, remove the tail and bring it to the front
	void insert(Node* n){
		if(isFull()){
			sentinel -> prev = tail -> prev;
			tail -> prev -> next = sentinel;
			tail = sentinel -> prev;
			size -= 1;
		}
		n-> next = sentinel -> next;
		sentinel -> next -> prev = n;
			
		sentinel -> next = n;
		n-> prev = sentinel;

		head = n;
		tail = sentinel -> prev;
		size += 1;
	}

	void remove(Node* n){
		n -> next -> prev = n -> prev;
		n -> prev -> next = n -> next;
		size -= 1;
	}


};



class LRUCache{
private:
	unordered_map<int,Node*> hashMap;
	DoubleLinkedList* queue;
	//int cap;

public:
    LRUCache(int capacity) {
        
    	queue = new DoubleLinkedList(capacity);
    }
    
    int get(int key) {
    	//everytime do get change the head
        if(!hashMap[key]) return -1;
        else{
        	Node* node = hashMap[key];
    		queue->remove(node);
    		queue->insert(node);
    		return node -> value;
        }

    }
    
    void set(int key, int value) {
    	// if not present in the cache set 
    	// if present change the value 

    	//create a new node 
    	if(hashMap[key]){
    		// if the key is already 
    		Node* node = hashMap[key];
    		queue->remove(node);
    		node -> value = value;
    		queue->insert(node);
    		hashMap[node->key] = node;

    	}else{
    		if(queue -> isFull()){
    			queue -> remove(queue -> tail);
    			hashMap[queue->tail->key] = nullptr;
    		}
    		Node* newNode = new Node(value,key);
    		hashMap[key] = newNode;
    		queue->insert(newNode);
    	}
        
    }
};


int main(int argc, char** argv){
	LRUCache cache(4);

	cache.set(1,10);
	cache.set(2,20);
	cache.set(3,30);
	cache.set(4,40);
	cache.set(5,50);


	cout << cache.get(5);
	cout << cache.get(3);

	cache.set(6,60);
	cout << cache.get(2);


}