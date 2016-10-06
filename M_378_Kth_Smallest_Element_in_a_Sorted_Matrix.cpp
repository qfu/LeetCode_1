#include <algorithm>
#include <vector>

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if (!matrix.size()) return -1;
        vector<int> buf;
        for(auto & row : matrix){
        	buf.insert(buf.end(),row.begin(),row.end()); 
        }
        sort(buf.begin(),buf.end());
        return buf[k-1];
    }
};

int main(){

}