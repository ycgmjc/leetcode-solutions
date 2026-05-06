class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        if(boxGrid.size() == 0 || boxGrid[0].size() == 0) {
            return boxGrid;
        }

        vector<vector<char>> output;
        for(int i = 0; i < boxGrid.size(); i++) {
            for(int j = boxGrid[0].size() - 2; j >= 0; j--) {
                int current_idx = j;
                while(current_idx < boxGrid[0].size() - 1 && 
                boxGrid[i][current_idx] == '#' && boxGrid[i][current_idx + 1] == '.') {
                    boxGrid[i][current_idx + 1] = '#';
                    boxGrid[i][current_idx] = '.';
                    current_idx += 1;
                }
            }
        }


        for(int i = 0; i < boxGrid[0].size(); i++) {
            vector<char> temp;
            for(int j = boxGrid.size() - 1; j >= 0; j--) {
                temp.push_back(boxGrid[j][i]);
            }
            output.push_back(temp);
        }
        return output;
    }
};
