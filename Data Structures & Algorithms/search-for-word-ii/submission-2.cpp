

class Node {
public:
    Node* links[26];
    bool endWord;
    
    Node() {
        for(int i = 0; i < 26; i++) {
            links[i] = nullptr;
        }
        endWord = false;
    }
    
    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }
    
    void setEnd() {
        endWord = true;
    }
    
    Node* get(char ch) {
        return links[ch - 'a'];
    }
    
    void put(char ch, Node* newnode) {
        links[ch - 'a'] = newnode;
    }
};

class Trie {
private: 
    Node* root;
    
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(char ch : word) {
            if(!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    
    Node* getRoot() {
        return root;
    }
};

class Solution {
    unordered_set<string> res; // Use a set to prevent duplicate entries
    int ROWS, COLS;
    vector<vector<bool>> visit; // Declare visit matrix

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for(const string& word : words) {
            trie.insert(word);
        }
        
        ROWS = board.size();
        COLS = board[0].size();
        visit.assign(ROWS, vector<bool>(COLS, false));

        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                dfs(board, r, c, trie.getRoot(), "");
            }
        }
        
        return vector<string>(res.begin(), res.end());
    }

private:
   private:
void dfs(vector<vector<char>>& board, int r, int c, Node* node, string word) {
    // 1. BOUNDS CHECK AND VISITED CHECK MUST BE FIRST
    if (r < 0 || c < 0 || r >= ROWS || c >= COLS || visit[r][c]) {
        return;
    }

    char ch = board[r][c];

    // 2. Trie lookup check comes after bounds are verified
    if (!node->containsKey(ch)) {
        return;
    }

    visit[r][c] = true;
    node = node->get(ch);
    word += ch;
    
    if (node->endWord) {
        res.insert(word);
    }

    // Explore 4 directions
    dfs(board, r + 1, c, node, word);
    dfs(board, r - 1, c, node, word);
    dfs(board, r, c + 1, node, word);
    dfs(board, r, c - 1, node, word);

    visit[r][c] = false; // Backtrack
}
};