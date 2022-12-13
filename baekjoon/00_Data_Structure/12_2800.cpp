#include <bits/stdc++.h>

using namespace std;

int main() {
    string line;
    cin >> line;
    
    vector<pair<int, int>> bracket;
    bracket.reserve(10);
    int idx{0};
    stack<int> s;
    for(int i {0}; i < line.size(); i++) {
        if(line[i] == '(') {
            s.push(i);
        }
        else if(line[i] == ')') {
            bracket.push_back(make_pair(s.top(), i));
            s.pop();
        }
    }
    
    int intSet[bracket.size()];
    for(int i{0}; i < bracket.size(); i++) {
        intSet[i] = i;
    }
    
    vector<string> subSet;
    subSet.reserve(1024);
    // vector<int> intSubSet;
    // intSubSet.reserve(1024);
    for(int i{0}; i < (1 << bracket.size()); i++) {
        string expression;
        // 부분 집합 구하고 어떻게 해결 ?
        for(int j{0}; j < bracket.size(); j++)
            if(i & (1 << j))
                cout << intSet[j] << ' ';
        
        cout << '\n';
    }
    
    
}