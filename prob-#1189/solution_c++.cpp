class Solution {
public:
    void remove_balloon(unordered_map<char, int>& balloon) {
        balloon['b'] -= 1;
        balloon['a'] -= 1;
        balloon['l'] -= 2;
        balloon['o'] -= 2;
        balloon['n'] -= 1;
    }

    bool can_balloon(unordered_map<char, int>& balloon) {
        if(balloon['b'] == 0) { return false; }
        if(balloon['a'] == 0) { return false; }
        if(balloon['l'] < 2) { return false; }
        if(balloon['o'] < 2) { return false; }
        if(balloon['n'] == 0) { return false; }
        return true;
    }

    int maxNumberOfBalloons(string text) {
        int result = 0;
        unordered_map<char, int> balloon = {{'b', 0}, {'a', 0}, {'l', 0}, {'o', 0}, {'n', 0}};
        for(char c : text) {
            balloon[c] += 1;
            if(can_balloon(balloon)) {
                result += 1;
                remove_balloon(balloon);
            }
        }
        return result;
    }
};
