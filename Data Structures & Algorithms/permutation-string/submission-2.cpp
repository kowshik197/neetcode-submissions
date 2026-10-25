class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s1.size() > s2.size()) return false;

        unordered_map<char,int> need;
        unordered_map<char,int> window;

        for(char ch:s1)
            need[ch]++;

        int k=s1.size();

        int l=0,r=0;

        while(r<s2.size()){

            // Grow
            window[s2[r]]++;
            r++;

            // Window size = k
            if(r-l==k){

                if(window==need)
                    return true;

                // Shrink
                window[s2[l]]--;

                if(window[s2[l]]==0)
                    window.erase(s2[l]);

                l++;
            }
        }

        return false;
    }
};