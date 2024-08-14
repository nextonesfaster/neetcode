// https://neetcode.io/problems/string-encode-and-decode

#include <string>
#include <vector>
#include <assert.h>

using namespace std;

class Solution
{
public:
    string encode(vector<string> &strs)
    {
        string res;
        for (auto str : strs)
            res.append(to_string(str.size()) + "#" + str);
        return res;
    }

    vector<string> decode(string s)
    {
        vector<string> res;
        int i = 0;
        while (i < s.size())
        {
            string intstr;
            while (true)
            {
                if (s[i] == '#')
                {
                    i++;
                    break;
                }
                else
                    intstr.push_back(s[i++]);
            }
            int len = stoi(intstr);
            res.push_back(s.substr(i, len));
            i += len;
        }

        return res;
    }
};

int main()
{
    Solution solution;
    vector<string> encode_strs = {"test", "c#ode", "mor4#"};
    assert(solution.encode(encode_strs) == "4#test5#c#ode5#mor4#");
    assert(solution.decode("4#test5#c#ode5#mor4#") == encode_strs);
}
