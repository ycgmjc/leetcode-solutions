class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double result = 0;
        int nums1_length = nums1.size();
        int nums2_length = nums2.size();
        int total_length = nums1.size() + nums2.size();
        bool odd_median = total_length % 2;
        int median_idx = ((total_length + 1) / 2) - 1;
        int current_idx = total_length - 1;

        while(current_idx >= median_idx) {
            int reserve;

            // get reserve
            if(nums1_length > 0 && nums2_length > 0) {
                int num1 = nums1[nums1_length - 1];
                int num2 = nums2[nums2_length - 1];
                if(num1 > num2) {
                    reserve = num1;
                    nums1_length -= 1;
                }
                else {
                    reserve = num2;
                    nums2_length -= 1;
                }
            }
            else if(nums1_length == 0 && nums2_length > 0) {
                int num2 = nums2[nums2_length - 1];
                reserve = num2;
                nums2_length -= 1;
            }
            else if(nums1_length > 0 && nums2_length == 0) {
                int num1 = nums1[nums1_length - 1];
                reserve = num1;
                nums1_length -= 1;
            }

            // update result
            if(!odd_median && (current_idx == median_idx + 1)) {
                result += reserve;
            }
            else if(current_idx == median_idx){
                result += reserve;
            }

            current_idx -= 1;
        }

        result /= (2 - odd_median);

        return result;
    }
};
