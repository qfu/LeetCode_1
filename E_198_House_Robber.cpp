#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;
class Solution {
public:
     int rob(vector<int> &num) {
            int n = num.size();
            if (n==0) return 0;
            vector<int> result(n+1,0);
            result[1] = num[0];
            for (int i=2;i<=n;i++){
                [0,4,9,9,11,7,6]
                result[i] = max(result[i-1],result[i-2]+num[i-1]);
            }
            return result[n];
            
        }
};


int main(){

}