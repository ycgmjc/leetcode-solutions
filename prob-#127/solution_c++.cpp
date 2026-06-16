class Solution {
public:
    bool can_transform(string word1, string word2) {
        int diff = 0;
        for(int i = 0; i < word1.length(); i++) {
            if(word1[i] != word2[i]) { 
                diff += 1; 
                if(diff > 1) { return false; } 
            }
        }
        return diff == 1; 
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        vector<bool> visited(n, false);
        stack<int> to_visit;
        
        for(int i = 0; i < n; i++) {
            string word = wordList[i];
            if(can_transform(word, beginWord)) { 
                if(word == endWord) { return 2; } 
                to_visit.push(i); 
                visited[i] = true; 
            }
        }

        int result = 2; 
        while(!to_visit.empty()) {
            stack<int> next_to_visit;
            result += 1; 
            
            while(!to_visit.empty()) {
                int index = to_visit.top();
                string word = wordList[index];
                to_visit.pop();

                for(int i = 0; i < n; i++) {
                    if(!visited[i] && can_transform(wordList[i], word)) {
                        visited[i] = true;
                        if(wordList[i] == endWord) { return result; }
                        next_to_visit.push(i);
                    } 
                }
            }
            to_visit = next_to_visit;
        }
        return 0;
    }
};
