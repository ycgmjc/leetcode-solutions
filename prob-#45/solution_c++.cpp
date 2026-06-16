class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int result = 0;

        int index = n - 1;
        while(index > 0) {
            for(int i = 0; i < index; i++) {
                if(i + nums[i] >= index) {
                    index = i;
                    result += 1;
                    break;
                }
            }
        }
        return result;
    }
};
