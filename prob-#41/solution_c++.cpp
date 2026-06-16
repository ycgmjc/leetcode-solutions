class Solution {
    int HASH_SIZE = 10000;
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<int> hash(HASH_SIZE, INT_MAX);
        int limit = 0;
        int result = -1;

        while(true) {
            limit += HASH_SIZE;
            
            fill(hash.begin(), hash.end(), INT_MAX);

            for(int num : nums) {
                if(num <= limit - HASH_SIZE) { continue; }
                if(num > limit) { continue; }
                if(hash[num % HASH_SIZE] > num ) { hash[num % HASH_SIZE] = num; }
            }
            
            for(int i = 1; i <= HASH_SIZE; i++) {
                int idx = i % HASH_SIZE;
                if(hash[idx] > limit && idx == 0) {
                    result = limit;
                    break;
                }
                else if(hash[idx] > limit) {
                    result = limit - HASH_SIZE + idx;
                    break; 
                }
            }
            if(result != -1) { break; }
        }
        return result;
    }
};
