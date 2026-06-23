class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        bool intersect = true;
        if(ax2 <= bx1 || ax1 >= bx2 || ay2 <= by1 || ay1 >= by2) { intersect = false; }

        vector<int> x_coord = {ax1, ax2, bx1, bx2};
        vector<int> y_coord = {ay1, ay2, by1, by2};
        sort(x_coord.begin(), x_coord.end());
        sort(y_coord.begin(), y_coord.end());

        int a_area = (ax2 - ax1) * (ay2 - ay1);
        int b_area = (bx2 - bx1) * (by2 - by1);

        int intersection = 0;
        if(intersect) {
            intersection = (x_coord[2] - x_coord[1]) * (y_coord[2] - y_coord[1]);
        }
        

        return a_area + b_area - intersection;
    }
};
