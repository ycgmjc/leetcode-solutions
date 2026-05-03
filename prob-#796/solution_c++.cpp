class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) { return false; }

        vector<int> offset;
        for(int i = 0; i < goal.size(); i++) {
            char c = goal[i];
            if(c == s[0]) { offset.push_back(i); }
        }

        if(offset.size() == 0) { return false; }

        for(int num : offset) {
            int match = 0;
            for(int i = 0; i < s.size(); i++) {
                if(s[i] != goal[(i + num) % s.size()]) { break; }
                match += 1;
            }
            if(match == s.size()) { return true; }
        }
        
        return false;
    }
};
