class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;

        while (n > 0) {
            count += (n & 1);
            n = n >> 1;


            // //ex:11 ==> 1101
            // //It1==> 1011 &
            //          0001 ==>1
            // then right shift
            // // It2==>0101 &
            //          0001 ==> 1
            //          // nowcount=2
                        
                                }

        return count;
    }
};