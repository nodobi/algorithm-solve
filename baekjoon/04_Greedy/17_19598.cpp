#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N{0}, ret{0}, tmp{0};

    cin >> N;

    vector<pair<int, int>> v;
    v.reserve(2* N);

    for(int n{0}; n < N; n++) {
        int start{0}, end{0};
        cin >> start >> end;
        v.push_back(make_pair(start, 1));
        v.push_back(make_pair(end, -1));
    }
    
    sort(v.begin(), v.end());

    for(auto ele : v) {
        tmp += ele.second;
        ret = max(ret, tmp);
    }

    cout << ret;
}