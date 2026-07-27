// class Solution {
//    public:
//     int lengthOfLongestSubstring(string s) {
//         int l, r = 0;
//         int curr_best = 0;
//         unordered_set<char> st;
//         while (r < s.size()) {
//             if (st.find(s[r]) == st.end()) {
//                 st.insert(s[r]);
//                 curr_best = max(curr_best, r - l + 1);
//                 r++;
//             }

//             else {
//                 while (st.find(s[r]) != st.end()) {
//                     st.erase(s[l]);
//                     l++;
//                 }
//             }
//         }
//         return curr_best;
//     }
// };
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;
        int curr_best = 0;
        unordered_set<char> st;

        while (r < s.size()) {

            if (st.find(s[r]) == st.end()) {
                st.insert(s[r]);
                curr_best = max(curr_best, r - l + 1);
                r++;
            }
            else {
                while (st.find(s[r]) != st.end()) {
                    st.erase(s[l]);
                    l++;
                }
            }
        }

        return curr_best;
    }
};
