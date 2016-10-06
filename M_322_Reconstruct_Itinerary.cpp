#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;


class Solution {
private:
	void dfs(unordered_map<string,multiset<string>>& adj, string s,vector<string>& result){
		if(!adj.size()) return;

		auto it = adj[s].begin();
		for(;it != adj[s].end();){
        	//result.push_back(*it);
        	adj[s].erase(it);
        	dfs(adj,*it,result);
        	it = adj[s].begin();
		}
		result.push_back(s);
		adj.erase(s);	
		return;
	}


public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
     	//All nodes have to be visited
    	int size = tickets.size();
    	if(!size) return vector<string>();

    	unordered_map<string,multiset<string>> adj;
    	for(auto & p : tickets){
    		adj[p.first].insert(p.second);
    	}

    	string start = "JFK";
    	vector<string> result;
    	//result.push_back(start);
    	dfs(adj,start,result);

    	return vector<string>(result.rbegin(), result.rend());

    }
};

int main(int argc, char const *argv[]){
	/* code */
	std::vector<pair<string,string>> v = {{"MUC","LHR"},{"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"}};

	std::vector<pair<string,string>> v2 = {{"JFK","LHR"},{"LHR","JFK"}};

	Solution s;
	vector<string> test = s.findItinerary(v2);

	for(string s: test) cout << s << " ";

	return 0;
}