#include <iostream>
#include <vector>


class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int size = citations.size();
        int h = 0;
        for(int i =0; i< size;){
            if(size - i >= citations[i]){
              h = citations[i];
              i++;
            }
            else{
                h++;
                if(size - i < h){
                    h--;
                    i++;
                }   
            } 
        }

        return h;
    }
};

int main(){

}