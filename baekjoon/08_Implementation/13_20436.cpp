#include <bits/stdc++.h>

using namespace std;

void init(map<char, pair<int, int>> &keyboard)
{
    string str[] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
    for(int i{0}; i < 3; i++) {
        for(size_t j{0}; j < str[i].size(); j++) {
            keyboard[str[i][j]] = {i, j};
        }
    }
}

int distance(pair<int, int> p1, pair<int, int> p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

bool isLeft(char c) {
    string leftBtn = "qwertasdfgzxcv";
    for(char ele : leftBtn) {
        if(ele == c)
            return true;
    }
    return false;
}

int main()
{
    pair<int, int> leftCursor{0, 0}, rightCursor{0, 0};
    map<char, pair<int, int>> keyboard;
    char ls, rs;
    int ret{0};
    string inputStr;

    init(keyboard);
    cin >> ls >> rs;
    leftCursor = keyboard[ls];
    rightCursor = keyboard[rs];

    cin >> inputStr;
    for(size_t i{0}; i < inputStr.size(); i++) {
        if(isLeft(inputStr[i])) {
            ret += distance(keyboard[inputStr[i]], leftCursor);
            leftCursor = keyboard[inputStr[i]];
        } else {
            ret += distance(keyboard[inputStr[i]], rightCursor);
            rightCursor = keyboard[inputStr[i]];
        }
        ret++;
    }

    cout << ret;
}