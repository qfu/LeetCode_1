
class Solution {
public:
    int square(int n){
        int y = 0;
        while(n){
            int digit = n % 10;
            y += pow(digit,2); 
            n /= 10;
        }
        return y;
    }

    bool isHappy(int n) {
        if (n == 1) return true;
        set<int> loop;
        int value = square(n);
        while(value){
            cout << value << endl;
            if (value ==1) return true; 
            if(loop.find(value) != loop.end()) return false;
            else loop.insert(value);
            value = square(value);
        }
        return false;
    
    }
};


int main(){
	
}