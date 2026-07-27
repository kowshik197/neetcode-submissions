class Solution {
public:

    string encode(vector<string>& strs) {
      string temp="";
      for(string str:strs){

           int size=str.size();
           temp += to_string(size) + "#" + str;

      }
      return temp;
    }

    vector<string> decode(string s) {
         
        vector<string> ans;
        int i=0;
         while (i < s.size()) {
            int j = i;
            while (s[j] != '#') j++;

            int len = stoi(s.substr(i, j - i));
            string word = s.substr(j + 1, len);

            ans.push_back(word);
            i = j + 1 + len;
        }
return ans;
    }
};
