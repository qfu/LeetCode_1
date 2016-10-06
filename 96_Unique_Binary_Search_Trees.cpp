#include <iostream>
using namespace std;
class Solution {
public:

	int v[1024];

	void dynamicP(int bound){
		int sum = 0;
	
		for(int i = 1; i <= bound;++i){
			if( i -1 <= 1 && bound - i <= 1 ){
				sum += 1;
			}else if(i -1 <= 1 && bound - i > 1){
				sum += v[bound-i];

			}else if(i -1 > 1 && bound - i <= 1){
				sum += v[i-1];
			}else if(i -1 > 1 && bound - i > 1){
				//this should be multiply not addition
				sum += v[i-1];
				sum += v[bound-i];
			} 
		}
		cout <<"i is " << bound <<"sum is "<< sum;
 		v[bound] = sum;
	}


    int numTrees(int n) {
    	int size = n;
    	for(int i =1 ; i <= n; ++i){
    		dynamicP(i);
    	}
    	return v[n];
    }
};

class Optimized {
public:
    int numTrees(int n) {
    	int G[n+1];
        G[0] = 1;
        G[1] = 1;
        
    	for(int i = 2 ; i <= n; ++i){
    		//Put initilize 
    	    G[i] =0;
    		for(int j = 1; j <= i;++j){
                 G[i] += (G[j-1] * G[i-j]);
    		}
    	}
    	return G[n];
    }
};

int main(){
	Solution s;
	s.numTrees(3);

}