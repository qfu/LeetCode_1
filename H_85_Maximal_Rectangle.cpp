#include <vector>
#include <iostream>
#include <utility>
#include <set>
#include <functional>
#include <algorithm>

using namespace std;

class Solution {
public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    int n = matrix.size();
    if(!n) return 0;

    int m = matrix[0].size();


    //Define DP matrix
    std::vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(4,0)));

    //Initialize the set
    set<int,greater<int>> s;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
          if(matrix[i][j] == '1'){
            dp[i][j][0] = 1;
            dp[i][j][1] = 1;
          }
      }
    }



    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        //boundary case
        if(i == 0){
          if (matrix[i][j] == '1' && j - 1 >= 0 && matrix[i][j-1] == '1'){
              dp[i][j][0] = dp[i][j-1][0] + 1;
          }
        }

        if(j == 0){
          if (matrix[i][j] == '1' && i - 1 >= 0 && matrix[i-1][j] == '1'){
            dp[i][j][1] = dp[i-1][j][1] + 1;
          }
        }

        if( i > 0 && j > 0){
          if (matrix[i][j] == '1' && matrix[i-1][j] == '1'){
            dp[i][j][1] = dp[i-1][j][1] + 1;

          }
          if (matrix[i][j] == '1' && matrix[i][j-1] == '1'){
            dp[i][j][0] = dp[i][j-1][0] + 1;
          }
          if (matrix[i][j] == '1' && matrix[i][j-1] == '1' && matrix[i-1][j] == '1' && matrix[i-1][j-1] == '1'){
            if(dp[i-1][j-1][2] && dp[i-1][j-1][3]){
              dp[i][j][2] = min(dp[i-1][j-1][2] + 1,min(dp[i][j-1][0] + 1,dp[i-1][j][0]));
              dp[i][j][3] = min(dp[i-1][j-1][3] + 1,min(dp[i-1][j][1] + 1,dp[i][j-1][1]));
              s.insert(min(dp[i-1][j-1][2] + 1,min(dp[i][j-1][0] + 1,dp[i-1][j][0]))* min(dp[i-1][j-1][3] + 1,min(dp[i-1][j][1] + 1,dp[i][j-1][1])));
            }
            else{
              dp[i][j][2] = min(dp[i][j-1][0] + 1,dp[i-1][j][0]);
              dp[i][j][3] = min(dp[i-1][j][1] + 1,dp[i][j-1][1]);
              s.insert(min(dp[i][j-1][0] + 1,dp[i-1][j][0])* min(dp[i-1][j][1] + 1,dp[i][j-1][1]));
            }

          }
        }
        s.insert(max(dp[i][j][0],dp[i][j][1]));

      }
    }
    //Test the 3-D matrix allocation
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
            cout << dp[i][j][0];
            cout << dp[i][j][1];
            cout << " ";
      }
      cout << endl;
    }

/*
    for(int v : s) cout << v;
    */
    return *s.begin();


  }
};


int main(int argc, char** argv){
  //std::vector<char> v1 = {'0','1'};
  //std::vector<char> v2 = {'0','1'};
  std::vector<char> v1 = {'0','1','1','0','1'};
  std::vector<char> v2 = {'1','1','0','1','0'};
  std::vector<char> v3 = {'0','1','1','1','0'};
  std::vector<char> v4 = {'1','1','1','1','0'};
  std::vector<char> v5 = {'1','1','1','1','1'};
  std::vector<char> v6 = {'0','0','0','0','0'};

  std::vector<vector<char>> v = {v1,v2,v3,v4,v5,v6};
  Solution s;
  cout << s.maximalRectangle(v);

}
