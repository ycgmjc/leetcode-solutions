class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.length();
        for(int i = 0; i < haystack.length(); i++) {
            if(haystack[i] != needle[0]) continue;
            
            int matching = 1;
            for(int j = i + 1; j < i + n; j++) {
                if(haystack[j] != needle[matching]) {
                    break;
                }
                matching += 1;
            }
            if(matching == n) {
                return i;
            }
        }
        return -1;
    }
};
