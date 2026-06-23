class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int left_limit = 0;
        int right_limit = (m * n) - 1;

        while (left_limit <= right_limit) {
            int mid = left_limit + (right_limit - left_limit) / 2; 
            
            int mid_val = matrix[mid / n][mid % n]; 

            if (mid_val == target) { return true; } 
            else if (mid_val < target) { left_limit = mid + 1; } 
            else { right_limit = mid - 1; }
        }
        return false; 
    }
};