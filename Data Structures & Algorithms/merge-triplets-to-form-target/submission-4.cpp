class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets,
                       vector<int>& target) {

        bool x = false;
        bool y = false;
        bool z = false;

        for(auto& t : triplets) {

            // This triplet can never be part of the answer
            if(t[0] > target[0] ||
               t[1] > target[1] ||
               t[2] > target[2]) {
                continue;
            }

            if(t[0] == target[0])
                x = true;

            if(t[1] == target[1])
                y = true;

            if(t[2] == target[2])
                z = true;
        }

        return x && y && z;
    }
};