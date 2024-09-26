// https://neetcode.io/problems/foreign-dictionary

#include <array>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

enum Status
{
    NEVER,
    ONCE,
    TWICE,
};

class Solution
{
    std::unordered_map<char, std::vector<char>> graph;
    std::array<Status, 26> visited = {NEVER};
    std::string res;

public:
    std::string foreignDictionary(std::vector<std::string> &words)
    {
        for (const auto &word : words)
            for (const auto &ch : word)
                graph[ch];

        for (int i = 0; i < words.size() - 1; i++)
        {
            const std::string &word1 = words[i];
            const std::string &word2 = words[i + 1];

            int min_len = std::min(word1.size(), word2.size());

            if (word1.size() > word2.size() && word1.substr(0, min_len) == word2.substr(0, min_len))
                return "";

            for (int j = 0; j < min_len; j++)
            {
                if (word1[j] != word2[j])
                {
                    graph[word1[j]].push_back(word2[j]);
                    break;
                }
            }
        }

        for (const auto &[c, _] : graph)
        {
            std::cout << "c: " << c << std::endl;
            if (dfs(c))
                return "";
        }

        std::reverse(res.begin(), res.end());
        return res;
    }

private:
    bool dfs(char ch)
    {
        int index = get_index(ch);
        Status status = visited[index];

        if (status == TWICE)
            return true;
        else if (status == ONCE)
            return false;

        visited[index] = TWICE;

        if (graph.count(ch))
            for (auto &nei : graph[ch])
                if (dfs(nei))
                    return true;

        visited[index] = ONCE;
        res.push_back(ch);
        return false;
    }

    int get_index(char c) { return c - 'a'; }
};

int main()
{
    std::vector<std::string> words = {"abc", "bcd", "cde"};

    Solution sol;
    std::string res = sol.foreignDictionary(words);
    std::cout << res << std::endl;
}
