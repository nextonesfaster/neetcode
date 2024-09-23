// https://neetcode.io/problems/design-word-search-data-structure

#include <array>
#include <string>

class WordDictionary {
  std::array<WordDictionary *, 26> chars = {nullptr};
  bool terminal = false;

  int char_to_index(char c) { return c - 'a'; }

  bool dfs(WordDictionary *root, std::string &word, int start) {
    WordDictionary *curr = root;
    for (int i = start; i < word.size(); i++) {
      if (word[i] == '.') {
        for (auto &char_node : curr->chars)
          if (char_node && dfs(char_node, word, i + 1))
            return true;
        return false;
      } else {
        // normal iterative search
        int idx = char_to_index(word[i]);
        if (!curr->chars[idx])
          return false;
        curr = curr->chars[idx];
      }
    }

    return curr->terminal;
  }

public:
  WordDictionary() {}

  void addWord(std::string word) {
    WordDictionary *curr = this;
    for (auto &ch : word) {
      int idx = char_to_index(ch);
      if (!curr->chars[idx])
        curr->chars[idx] = new WordDictionary();
      curr = curr->chars[idx];
    }
    curr->terminal = true;
  }

  bool search(std::string word) { return dfs(this, word, 0); }
};
