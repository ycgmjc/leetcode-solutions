class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> output;
        int idx1 = 0;
        int idx2 = 0;
        while(idx1 < m && idx2 < n) {
            int num;
            if(nums1[idx1] > nums2[idx2]) {
                num = nums2[idx2];
                idx2 += 1;
            }
            else {
                num = nums1[idx1];
                idx1 += 1;
            }
            output.push_back(num);
        }
        while(idx2 < n) {
            output.push_back(nums2[idx2]);
            idx2 += 1;
        }
        while(idx1 < m) {
            output.push_back(nums1[idx1]);
            idx1 += 1;
        }
        nums1 = output;
    }
};
