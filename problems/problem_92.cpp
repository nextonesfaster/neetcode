// https://neetcode.io/problems/word-ladder

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

class Solution
{
public:
    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string> &wordList)
    {
        if (endWord.empty() || std::find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;

        std::unordered_map<std::string, std::vector<std::string *>> adj;
        wordList.push_back(beginWord);
        for (auto &word : wordList)
        {
            for (int i = 0; i < word.size(); i++)
            {
                std::string pattern = word.substr(0, i) + "*" + word.substr(i + 1);
                adj[pattern].push_back(&word);
            }
        }

        std::unordered_set<std::string *> visited;
        visited.insert(&beginWord);

        std::queue<std::string *> queue;
        queue.push(&beginWord);

        int len = 1;
        while (!queue.empty())
        {
            int sz = queue.size();
            for (int i = 0; i < sz; i++)
            {
                auto word = queue.front();
                queue.pop();

                if (*word == endWord)
                    return len;

                for (int j = 0; j < (*word).size(); j++)
                {
                    std::string pattern = (*word).substr(0, j) + "*" + (*word).substr(j + 1);
                    for (const auto &adj_word : adj[pattern])
                    {
                        if (!visited.count(adj_word))
                        {
                            visited.insert(adj_word);
                            queue.push(adj_word);
                        }
                    }
                }
            }

            len++;
        }

        return 0;
    }
};
