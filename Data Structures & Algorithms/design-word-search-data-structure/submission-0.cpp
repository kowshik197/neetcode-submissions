class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;

        for(int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};


class WordDictionary {
public:

    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {

        TrieNode* curr = root;

        for(char ch : word) {

            int index = ch - 'a';

            if(curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
            }

            curr = curr->children[index];
        }

        curr->isEnd = true;
    }
    
    bool dfs(TrieNode* curr, string& word, int index) {

        // Reached end of word
        if(index == word.size()) {
            return curr->isEnd;
        }

        char ch = word[index];

        // Normal character
        if(ch != '.') {

            int i = ch - 'a';

            if(curr->children[i] == nullptr) {
                return false;
            }

            return dfs(curr->children[i], word, index + 1);
        }

        // '.' means ANY character
        for(int i = 0; i < 26; i++) {

            if(curr->children[i] != nullptr) {

                if(dfs(curr->children[i], word, index + 1)) {
                    return true;
                }
            }
        }

        return false;
    }
    
    bool search(string word) {
        return dfs(root, word, 0);
    }
};