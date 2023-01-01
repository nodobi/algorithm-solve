#include <bits/stdc++.h>

using namespace std;

void reversal(string &str, int from, int to)
{
    for (int i{0}; i < (to - from + 1) / 2; i++)
    {
        swap(str[from + i], str[to - i]);
    }
}

int main()
{
    bool isTag{false}, isWord{false};
    int from{0};
    vector<char> ret;
    string line;
    getline(cin, line);

    ret.reserve(line.size() + 1);
    for (int i{0}; i < line.size(); i++)
    {
        if (line[i] == '<')
        {
            isTag = true;
            if(isWord){
                reversal(line, from, i - 1);
                isWord = false;
            }
        }
        if (isTag)
        {
            if (line[i] != '>')
            {
                continue;
            }
            isTag = !isTag;
        }
        else {
            if (isdigit(line[i]) || isalpha(line[i]))
            {
                if (!isWord)
                {
                    isWord = true;
                    from = i;
                }
            }
            else
            {
                reversal(line, from, i - 1);
                isWord = false;
            }
        }
    }
    if (isWord)
    {
        reversal(line, from, line.size() - 1);
    }
    cout << line;
}