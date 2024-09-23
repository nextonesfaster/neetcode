// https://neetcode.io/problems/implement-prefix-tree

#include <array>
#include <string>

class PrefixTree {
  class TrieNode {
  public:
    std::array<TrieNode *, 26> chars = {nullptr};
    bool is_word = false;

    TrieNode() {}
    TrieNode(bool is_word) : is_word(is_word) {}
  };

  TrieNode *root;

public:
  PrefixTree() { root = new TrieNode(); }

  void insert(std::string word) {
    TrieNode *curr = root;
    for (int i = 0; i < word.length(); i++) {
      if (curr->chars[word[i] - 'a']) {
        curr = curr->chars[word[i] - 'a'];
        if (i == word.length() - 1)
          curr->is_word = true;
      } else {
        TrieNode *node = new TrieNode(i == word.length() - 1);
        curr->chars[word[i] - 'a'] = node;
        curr = node;
      }
    }
  }

  bool search(std::string word) {
    TrieNode *curr = root;
    for (int i = 0; i < word.length(); i++) {
      if (!curr->chars[word[i] - 'a'] ||
          (i == word.length() - 1 && !curr->chars[word[i] - 'a']->is_word))
        return false;
      curr = curr->chars[word[i] - 'a'];
    }

    return true;
  }

  bool startsWith(std::string prefix) {
    TrieNode *curr = root;
    for (int i = 0; i < prefix.length(); i++) {
      if (!curr->chars[prefix[i] - 'a'])
        return false;
      curr = curr->chars[prefix[i] - 'a'];
    }

    return true;
  }
};
