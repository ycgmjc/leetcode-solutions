class Solution {
public:
    bool isUgly(int n) {
        if(n == 1) { return true; }
        if(n == 0) { return false; }
        while(n % 2 == 0) { return isUgly(n / 2); }
        while(n % 3 == 0) { return isUgly(n / 3); }
        while(n % 5 == 0) { return isUgly(n / 5); }
        return false;
    }
};
