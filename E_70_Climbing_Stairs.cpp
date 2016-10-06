class Solution {
public:
    int climbStairs(int n) {
        if( n <= 2) return n;
        int array[n+1];
        memset(array,0,sizeof(array));
        
        for(int i = 1; i <= n;++i){
            if(i <= 2) array[i] = i;
            else array[i] = array[i-1]+array[i-2];
        }
        return array[n];
    }   
};


int main(){
    
}