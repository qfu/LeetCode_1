#include <vector>
#include <utility>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <set>
using namespace std;


class Solution {
public:
     vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {

          vector<int> res;

          if(n == 1){
               res.push_back(0);
               return res;
          }

          unordered_map<int, unordered_set<int>> adj;

          for(auto & p : edges){
               adj[p.first].insert(p.second);
               adj[p.second].insert(p.first);
          }

          vector<int> leaves;
          for(auto & ele: adj){
               if(ele.second.size() == 1)
                    leaves.push_back(ele.first);
          }

          while(n > 2){
               n -= leaves.size();
               vector<int> newLeaves;
               for(int i = 0; i < leaves.size(); ++i){
                    int next  = *(adj[leaves[i]].begin());
                    adj[leaves[i]].erase(next);
                    adj[next].erase(leaves[i]);

                    if(adj[next].size() == 1)
                         newLeaves.push_back(next);
               }
               leaves = newLeaves;
          }
          return leaves;

     }
};



int main(int argv, char ** argc){
	Solution s;
	std::vector<pair<int,int>> v ={{1,0},{1,2},{1,3}};
	s.findMinHeightTrees(4,v);

	return 0;
}