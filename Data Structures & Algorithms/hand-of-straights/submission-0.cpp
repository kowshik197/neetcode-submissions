class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        int n = hand.size();

        if(n % groupSize != 0)
            return false;

        unordered_map<int, int> freq;

        for(int x : hand) {
            freq[x]++;
        }

        sort(hand.begin(), hand.end());

        for(int x : hand) {

            // Already completely used
            if(freq[x] == 0)
                continue;

            // Start a group from x
            for(int i = 0; i < groupSize; i++) {

                int card = x + i;

                if(freq[card] == 0)
                    return false;

                freq[card]--;
            }
        }

        return true;
    }
};