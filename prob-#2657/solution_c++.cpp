class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> output(n);
        for(int idx = 0; idx < n; idx++) {
            if(idx == 0) { output[idx] = 0; }
            else { output[idx] = output[idx - 1]; }
            if(A[idx] == B[idx]) { output[idx] = output[idx] + 1; continue; }
            for(int j = 0; j < idx; j++) {
                if(A[idx] == B[j]) { output[idx] = output[idx] + 1; break; }
            }
            for(int j = 0; j < idx; j++) {
                if(B[idx] == A[j]) { output[idx] = output[idx] + 1; break; }
            }
        }

        return output;
    }
};
