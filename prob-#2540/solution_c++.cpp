class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int idx1 = 0;
        int idx2 = 0;

        while(nums1[idx1] != nums2[idx2]) {
            if(nums1[idx1] < nums2[idx2]) { idx1 += 1; }
            else { idx2 += 1; }

            if(idx1 == nums1.size() || idx2 == nums2.size()) { return -1; }
        }

        return nums1[idx1];
    }
};
