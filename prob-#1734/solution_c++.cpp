class Solution {
public:
    int xor_to_n(int n) {
        int result = 1;
        for(int i = 2; i <= n; i++) {
            result = result ^ i;
        }
        return result;
    }

    vector<int> decode(vector<int>& encoded) {
        int m = encoded.size();
        int n = m + 1;
        vector<int> output(n);
        
        int xor_sum = xor_to_n(n);

        int encoded_xor_sum = 0;
        for(int i = 1; i < m; i += 2) {
            encoded_xor_sum ^= encoded[i];
        }

        output[0] = xor_sum ^ encoded_xor_sum;

        for(int i = 1; i < n; i++) {
            output[i] = output[i - 1] ^ encoded[i - 1];
        }

        return output;
    }
};
