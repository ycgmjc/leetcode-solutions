class Solution {
public:
    int return_distance(string moves, int current_distance) {
        int distance = current_distance;
        int traversed = 0;
        for(char c : moves) {
            if(c == 'R') { distance += 1; traversed += 1; }
            else if(c == 'L') { distance -= 1; traversed += 1; }
            else { break; }
        }
        if(traversed < moves.length()) {
            int to_right = return_distance(moves.substr(traversed + 1), distance + 1);
            int to_left = return_distance(moves.substr(traversed + 1), distance - 1);
            int abs_to_right = (to_right >= 0) ? to_right : -1 * to_right;
            int abs_to_left = (to_left >= 0) ? to_left : -1 * to_left;
            if(abs_to_right >= abs_to_left) { distance = to_right; }
            else { distance = to_left; }
        }

        return distance;
    }

    int furthestDistanceFromOrigin(string moves) {
        bool all_line = true;
        for(char c : moves) {
            if(c != '_') { all_line = false; break; }
        }
        if(all_line) { return moves.length(); }

        int output = return_distance(moves, 0);
        output = (output > 0) ? output : -1 * output;
        return output;
    }
};
