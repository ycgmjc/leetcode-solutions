class Solution {
public:
    int pivotInteger(int n) {
        int sum = 0;
        int total = n * (n + 1) / 2;
        int num = 1;
        while(sum <= total) {
            sum += num;
            int test = total + num;
            if(test % 2 == 0 && sum == test / 2) { return num; }
            num += 1;
        }
        return -1;
    }
};
