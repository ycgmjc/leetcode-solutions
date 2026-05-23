class Solution {
public:
    bool check(vector<int>& nums) {
        bool decreased = false;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[(i + n - 1) % n] > nums[i]) {
                if(decreased == true) { return false; }
                decreased = true; 
            }
        }
        return true;
    }
};
