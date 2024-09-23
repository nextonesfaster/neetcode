// https://neetcode.io/problems/lru-cache

#include <unordered_map>

struct Node {
  int key;
  int val;
  Node *next;
  Node *prev;
  Node(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}
};

class LRUCache {
  int capacity;
  std::unordered_map<int, Node *> cache;
  Node *left;
  Node *right;

  void remove(Node *node) {
    Node *prev = node->prev;
    prev->next = node->next;
    node->next->prev = prev;
  }

  void insert(Node *node) {
    Node *prev = right->prev;
    prev->next = node;
    node->prev = prev;
    node->next = right;
    right->prev = node;
  }

public:
  LRUCache(int cap) : capacity(cap) {
    cache.clear();
    cache.reserve(capacity);
    left = new Node(-1, -1);
    right = new Node(-1, -1);
    left->next = right;
    right->prev = left;
  }

  int get(int key) {
    if (!cache.count(key))
      return -1;

    Node *node = cache[key];
    remove(node);
    insert(node);
    return node->val;
  }

  void put(int key, int value) {
    if (cache.count(key))
      remove(cache[key]);

    cache[key] = new Node(key, value);
    insert(cache[key]);

    if (cache.size() > capacity) {
      Node *lru = left->next;
      remove(lru);
      cache.erase(lru->key);
      delete lru;
    }
  }
};
