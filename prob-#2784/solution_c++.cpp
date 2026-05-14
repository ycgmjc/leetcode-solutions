class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        vector<int> checked(n, 0);
        for (int num : nums) {
            if (num >= n) { return false; }
            if (num == n - 1 && checked[num] > 1) { return false; }
            if (num < n - 1 && checked[num] > 0) { return false; }
            checked[num] = checked[num] + 1;
        }
        return true;
    }
};
