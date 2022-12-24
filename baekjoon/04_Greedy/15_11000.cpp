#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N{0}, roomCnt{0}, tmp{0};
    vector<pair<int,int>> v;
    cin >> N;
    v.reserve(N * 2);
    
    for(int n{0}; n < N; n++) {
        int start{0}, end{0};
        cin >> start >> end;
        v.push_back(make_pair(start, 1));
        v.push_back(make_pair(end, -1));
    }

    sort(v.begin(), v.end());

    for(auto e : v) {
        tmp += e.second;
        roomCnt = max(tmp, roomCnt);
    }

    cout << roomCnt;
}