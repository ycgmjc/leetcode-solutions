class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int depth = matrix.size() / 2;
        int n = matrix.size();

        for(int i = 0; i < depth; i++) {
            vector<int> striped;
            
            // top row (left -> right)
            for(int j = i; j < n - i - 1; j++) {
                striped.push_back(matrix[i][j]);
            }
            // right column (top -> bottom)
            for(int j = i; j < n - i - 1; j++) {
                striped.push_back(matrix[j][n - i - 1]);
            }
            // bottom row (right -> left)
            for(int j = n - i - 1; j > i; j--) {
                striped.push_back(matrix[n - i - 1][j]);
            }
            // left column (bottom -> top)
            for(int j = n - i - 1; j > i; j--) {
                striped.push_back(matrix[j][i]);
            }

            int idx = 0;
            // wrap the ring in a 90 degrees rotated location
            // top elements to right column
            for(int j = i; j < n - i - 1; j++) {
                matrix[j][n - i - 1] = striped[idx++];
            }
            // right elements to bottom row
            for(int j = n - i - 1; j > i; j--) {
                matrix[n - i - 1][j] = striped[idx++];
            }
            // bottom elements to left column
            for(int j = n - i - 1; j > i; j--) {
                matrix[j][i] = striped[idx++];
            }
            // left elements to top row
            for(int j = i; j < n - i - 1; j++) {
                matrix[i][j] = striped[idx++];
            }
        }
    }
};
