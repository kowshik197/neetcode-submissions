class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        
        // Iterate through all 32 bits (index 0 to 31)
        for (int i = 0; i < 32; i++) {
            // (1 << i) creates a bitmask with a 1 at the i-th position
            // Bitwise-AND checks if the i-th bit in n is set
            if (n & (1 << i)) {
                count++;
            }
        }
        
        return count;
    }
};