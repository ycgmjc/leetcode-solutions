class NumArray {
    vector<int> arr;
    int n = 0;
public:
    NumArray(vector<int>& nums) {
        arr = nums;
        n = nums.size();
    }
    
    int sumRange(int left, int right) {
        if(n == 0) { return -1; }
        
        int sum = 0;
        for(int i = left; i <= right; i++) {
            sum += arr[i];
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
 