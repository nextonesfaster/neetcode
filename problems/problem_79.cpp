// https://neetcode.io/problems/search-for-word-ii

#include <array>
#include <string>
#include <vector>

class TrieNode {
public:
  std::array<TrieNode *, 26> chars = {nullptr};
  bool is_word = false;

  void add_word(std::string &word) {
    TrieNode *cur = this;
    for (auto &c : word) {
      int idx = c - 'a';
      if (!cur->chars[idx])
        cur->chars[idx] = new TrieNode();
      cur = cur->chars[idx];
    }
    cur->is_word = true;
  }
};

class Solution {
  int ROWS, COLS;
  std::vector<std::string> res = {};
  const std::array<int, 5> DIRS = {-1, 0, 1, 0, -1};

public:
  std::vector<std::string> findWords(std::vector<std::vector<char>> &board,
                                     std::vector<std::string> &words) {
    TrieNode *trie = new TrieNode();
    for (auto &word : words)
      trie->add_word(word);

    ROWS = board.size();
    COLS = board[0].size();
    std::string curr_str = "";

    for (int r = 0; r < ROWS; r++) {
      for (int c = 0; c < COLS; c++) {
        dfs(r, c, curr_str, trie, board);
        curr_str.erase();
      }
    }

    return res;
  }

private:
  void dfs(int r, int c, std::string &curr_str, TrieNode *node,
           std::vector<std::vector<char>> &board) {
    if (r < 0 || r >= ROWS || c < 0 || c >= COLS || board[r][c] == '#')
      return;

    TrieNode *next_node = node->chars[board[r][c] - 'a'];
    if (!next_node)
      return;

    char tmp = board[r][c];
    node = next_node;
    curr_str.push_back(tmp);

    if (node->is_word) {
      res.push_back(curr_str);
      node->is_word = false;
    }

    board[r][c] = '#';

    for (int i = 0; i < 4; i++)
      dfs(r + DIRS[i], c + DIRS[i + 1], curr_str, node, board);

    board[r][c] = tmp;
    curr_str.pop_back();
  }
};
