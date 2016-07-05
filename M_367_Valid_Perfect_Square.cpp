class Solution {
public:
    bool isPerfectSquare(int num) {
        int odd = 1;
        while(num > 0){
            num -= odd;
            odd += 2;
        }
        if (num == 0)
            return true;
        else
            return false;
    }
};

int main(int argc, char** argv){
	Solution s;
	s.isPerfectSquare(16);
	return 0;
}