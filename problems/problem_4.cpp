// https://neetcode.io/problems/anagram-groups

#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> groups;
    for (auto &str : strs) {
      vector<int> count(26, 0);
      for (auto ch : str)
        count[ch - 'a']++;

      stringstream key;
      for (auto i : count)
        key << i << "#";

      groups[key.str()].push_back(str);
    }

    vector<vector<string>> res;
    for (auto pair : groups)
      res.push_back(pair.second);

    return res;
  }
};

int main() {}
