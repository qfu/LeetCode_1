#include <iostream>
#include <vector>
#include <utility>
#include <list>


using namespace std;

class Solution {
public:
	//using new operator
	list<int> *array;

	bool returnValue;

	bool cycleDetection(int i, bool * visited,bool * tracker){
		if(!visited[i]){
			visited[i] = true;
			tracker[i] = true;
			cout << i << endl;
			for(auto it = array[i].begin(); it != array[i].end();++it){
				if(tracker[*it] || cycleDetection(*it,visited,tracker)){
					cout << *it << " visited node "<< endl;
					return true;
				}
			}
			return tracker[i] = false;

		}
		return false;
	}


    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    	//Initilize my graph
    	array = new list<int>[numCourses];
    	bool * visited = new bool[numCourses];
    	bool * tracker = new bool[numCourses];
    	returnValue = true;

    	//insert edges
    	for(auto & p : prerequisites){
    		array[p.second].push_back(p.first);
    	}

    	//intialize the visited 
    	for(int i = 0; i < numCourses; ++i){
    		visited[i] = false;
    		tracker[i] = false;
    	}


       //topological sorting	
       for (int i = 0; i < numCourses; i++)
       	//if cycle exits then exit 
            if (!visited[i] && cycleDetection(i,visited, tracker)){
            	cout << "what return false " << i << endl;
            	return false;
            }
                //return false;
        return true;


    }
};





int main(int argc, char ** argv){

	Solution s;
	std::vector<pair<int,int>> v;
	v.push_back(make_pair(1,0));
	v.push_back(make_pair(0,1));
	cout << s.canFinish(2,v);
}