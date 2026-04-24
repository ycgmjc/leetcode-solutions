class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int output = 0;
        int R = 0;
        int L = 0;
        
        for(char c : moves) {
            if(c == 'R') { R += 1; }
            else if(c == 'L') { L += 1; }
            else if(c == '_') { output += 1; }
        }

        output += abs(R - L);

        return output;
    }
};
