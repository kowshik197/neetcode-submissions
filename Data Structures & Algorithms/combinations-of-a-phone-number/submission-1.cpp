class Solution {
   public:
    vector<string> mp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> result;

    void visit(int index, string digits, string path) {
        if (index == digits.size()) {
            result.push_back(path);
            return;
        }

        string letters = mp[digits[index] - '0'];

        for (char ch : letters) {
            path.push_back(ch);

            visit(index + 1, digits, path);

            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        string path = "";
        visit(0, digits, path);
        return result;   
    }
};
