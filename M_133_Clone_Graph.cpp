/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
private:
	unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> map;

public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    	if(!node) return nullptr;

    	//Use DFS to create all the cloneNode and add all the neighbors
    	UndirectedGraphNode * cloneNode = new UndirectedGraphNode(node->label);
    	map[node] = cloneNode;

    	for(UndirectedGraphNode* n : node->neighbors){
    		if(map.find(n) == map.end())
    			cloneGraph(n);
    	}
    	//after return
    	for(UndirectedGraphNode* n : node->neighbors){
    		cloneNode->neighbors.push_back(map[n]);
    	}
    	return cloneNode;
    }
};



int main(int argc, char ** argv){


	return 0;

}