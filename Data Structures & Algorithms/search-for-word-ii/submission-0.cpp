class Solution {
public:

    class TrieNode {
    public:
        TrieNode* children[26];
        string word;

        TrieNode() {
            word = "";

            for(int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

    void insert(TrieNode* root, string word) {

        TrieNode* curr = root;

        for(char ch : word) {

            int index = ch - 'a';

            if(curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
            }

            curr = curr->children[index];
        }

        curr->word = word;
    }

    void dfs(vector<vector<char>>& board,
             int r,
             int c,
             TrieNode* curr,
             vector<string>& ans) {

        if(r < 0 || r >= board.size() ||
           c < 0 || c >= board[0].size()) {
            return;
        }

        if(board[r][c] == '#') {
            return;
        }

        char ch = board[r][c];

        int index = ch - 'a';

        if(curr->children[index] == nullptr) {
            return;
        }

        curr = curr->children[index];

        if(curr->word != "") {
            ans.push_back(curr->word);

            // Prevent duplicate
            curr->word = "";
        }

        board[r][c] = '#';

        dfs(board, r + 1, c, curr, ans);
        dfs(board, r - 1, c, curr, ans);
        dfs(board, r, c + 1, curr, ans);
        dfs(board, r, c - 1, curr, ans);

        board[r][c] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        TrieNode* root = new TrieNode();

        // Build Trie
        for(string word : words) {
            insert(root, word);
        }

        vector<string> ans;

        // Start DFS from every cell
        for(int i = 0; i < board.size(); i++) {

            for(int j = 0; j < board[0].size(); j++) {

                dfs(board, i, j, root, ans);
            }
        }

        return ans;
    }
};