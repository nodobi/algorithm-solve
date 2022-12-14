#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    map<int, string> idMap;
    map<string, int> nameMap;

    int N{0}, M{0};
    cin >> N >> M;

    for(int i{1}; i <= N; i++) {
        string buf;
        cin >> buf;
        idMap[i] = buf;
        nameMap[buf] = i;
    }

    for(int i{0}; i < M; i++) {
        string line;
        cin >> line;
        if(isdigit(line[0])) cout << idMap[stoi(line)];
        else cout << nameMap[line];
        cout << '\n';
    }
}