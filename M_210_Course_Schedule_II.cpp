#include <vector>
#include <utility>
#include <iostream>
#include <list>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
private:
	bool dfs(bool visited[],bool recur[],unordered_map<int, list<int>>& adj, int node,stack<int>& s,unordered_map<int, int>& notOrder){
		if(!visited[node]){	
			visited[node] = true;
			recur[node] = true;

			for(int n : adj[node]){
				if(!visited[n] && dfs(visited,recur,adj,n,s,notOrder))
					return true;
				else if(recur[n])
					return true;
			}
			s.push(node);
			notOrder[node]--;
		}
		recur[node] = false;
		return false;
	}

	bool cycle(bool visited[],bool recur[],unordered_map<int, list<int>>& adj, int node){
		if(!visited[node]){	
			visited[node] = true;
			recur[node] = true;

			for(int n : adj[node]){
				if(!visited[n] && cycle(visited,recur,adj,n))
					return true;
				else if(recur[n])
					return true;
			}
		}
		recur[node] = false;
		return false;
	}


public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
     	
     	vector<int> v;
    	if(!prerequisites.size()){
    		while(numCourses--) v.push_back(numCourses);
    		return v;
    	}

     	unordered_map<int, int> notOrder;
     	unordered_map<int, list<int>> adj;
     	unordered_map<int, list<int>> indegree;

     	bool visited[numCourses];
     	bool recur[numCourses];
     	stack<int> s;
     	memset(visited,0,sizeof(visited));
     	memset(recur,0,sizeof(recur));
     	for(int i = 0; i < numCourses;++i){
     		notOrder[i]++;
     	}

     	for(auto & pre: prerequisites){
     		adj[pre.second].push_back(pre.first);
     		indegree[pre.first].push_back(pre.second);
     	}

     	for(auto it = adj.begin(); it != adj.end(); ++it){
     		if(!visited[it->first]){
     			if (cycle(visited,recur,adj,it->first)){
     			 	cout << " in";
     			 	return v;
     			 }
     		}
     	}

     	memset(visited,0,sizeof(visited));
     	memset(recur,0,sizeof(recur));

     	//Topological sorting find the vertex where indegree is 0 
     	for(auto it = adj.begin(); it != adj.end(); ++it){
     		if(indegree[it->first].size() == 0){
     			if (dfs(visited,recur,adj,it->first,s,notOrder)) return v;
     		}
     	}

     	while(!s.empty()){
     		v.push_back(s.top());
     		s.pop();
     	}

     	for(auto it = notOrder.begin(); it != notOrder.end(); ++it){
     		if(it->second) v.push_back(it->first);
     	}

     	for(int i : v) cout << i << " ";

     	return v;
    }
};

class Solution2{
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
        vector<int> toposort;
        vector<bool> onpath(numCourses, false), visited(numCourses, false);
        for (int i = 0; i < numCourses; i++)
            if (!visited[i] && dfs(graph, i, onpath, visited, toposort))
                return {};
        reverse(toposort.begin(), toposort.end());
        return toposort;
    }
private:
    vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        for (auto pre : prerequisites)
            graph[pre.second].insert(pre.first);
        return graph;
    }
    bool dfs(vector<unordered_set<int>>& graph, int node, vector<bool>& onpath, vector<bool>& visited, vector<int>& toposort) { 
        if (visited[node]) return false;
        onpath[node] = visited[node] = true; 
        for (int neigh : graph[node])
            if (onpath[neigh] || dfs(graph, neigh, onpath, visited, toposort))
                return true;
        toposort.push_back(node);
        return onpath[node] = false;
    }
};
int main(int argc, char const *argv[]){

	Solution s;
	vector<pair<int,int>> v = {{1,0},{0,1}};

	s.findOrder(2,v);


	return 0;
}