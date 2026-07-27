class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string str : strs) {
            string key = str;
            sort(key.begin(), key.end());   // Create the key
            mp[key].push_back(str);         // Group original string
        }

        vector<vector<string>> result;

        for (auto &it : mp) {
            result.push_back(it.second);
        }

        return result;
    }
};






// class Solution {
// public:

// bool isAnagram(string s, string t) {
//      vector<int>freq(26,0);
//        if(s.size()!=t.size())return false;
//        for(char ch:s){
//         freq[ch-'a']++;
//        }

//        for(char ch:t){
//         freq[ch-'a']--;
//        }
        
//         for(int x:freq){
//             if(x!=0)return false;
//         }
//         return true;
// }
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//      int l=0,r=1;
//     // unordered_set<str> s;
//      vector<vector<string>> result;
//      vector<string> temp;
//      bool lpushed=false;
//       while(r<strs.size() && l<r){
         
//          if(isAnagram(strs[l],strs[r])){
//             temp.push_back(strs[r]);
//             //s.insert(str[r]);
 
//             if(!lpushed){
//                temp.push_back(strs[l]);
//                lpushed=true;
//             }

//          }

//          if(r+1==strs.size()){
//             r=l+2;
//             l=l+1;
//             lpushed=false;
//             result.push_back(temp);
//             temp.clear();

//          }
        
//       }

//       return result;

//     }
// };
