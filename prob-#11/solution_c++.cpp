class Solution {
public:
    int maxArea(vector<int>& height) {
        int best = 0;
        for(int i = 0; i < height.size(); i++ ) {
            int _height = height[i];
            int left = i;
            int right = height.size() - i - 1;
            int left_idx = 0;
            int right_idx = height.size() - 1;

            while((left > 0) || (right > 0)) {
                bool is_left = left > right;
                int idx = (is_left) ? left_idx : right_idx;

                int idx_height = height[idx];

                if(idx_height >= _height) {
                    int offset = (is_left) ? i - idx : idx - i;
                    int area = _height * offset;
                    if(area > best) { best = area; }
                    break;
                }

                if(is_left) { left -= 1; left_idx += 1; }
                else { right -= 1; right_idx -= 1; }
            }
            
        }
        return best;
    }
};
