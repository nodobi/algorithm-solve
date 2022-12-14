#include <bits/stdc++.h>

using namespace std;

void printExpression(string& line, vector<int> &subSet) {

}
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
    // bracket 은 first를 내림차순으로 정렬
    
    int intSet[bracket.size()];
    for(int i{0}; i < bracket.size(); i++) {
        intSet[i] = i;
    }
    
    vector<string> subSet;
    subSet.reserve(1024);
    vector<vector<bool>> printFlag(((1 << bracket.size()) - 1), vector<bool>(line.size(), true));
    for(int i{0}; i < ((1 << bracket.size()) - 1); i++) {
        // 부분 집합 구하고 어떻게 해결 ?
        vector<int> deletedBracketIdx;
        deletedBracketIdx.reserve(bracket.size());
        for(int j{0}; j < bracket.size(); j++)
            if(i & (1 << j))
                deletedBracketIdx.push_back(intSet[j]);
        
        for(int j{0}; j < deletedBracketIdx.size(); j++) {
            printFlag[i][deletedBracketIdx[j]] = false;
        }

        for(int j{0}; j < line.size(); j++) {
            if(printFlag[i][j])
                cout << line[j];
        }
        cout << '\n';

    }
    
    
}