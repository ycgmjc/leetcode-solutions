class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> output;
        int word_length = queries[0].length();

        for(string q : queries) {
            for(string d : dictionary) {
                int edits = 0;
                bool success = true;
                for(int i = 0; i < word_length; i++) {
                    if(q[i] != d[i]) { edits += 1; }
                    if(edits > 2) { success = false; break; }
                }

                if(success) { output.push_back(q); break; }
            }
        }

        return output;
    }
};
