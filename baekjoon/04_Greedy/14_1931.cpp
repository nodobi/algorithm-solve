#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first) {
        return a.second > b.second;
    }
    return a.first > b.first;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    vector<pair<int, int>> v;
    int cnt{0}, endTime{0}, N{0};
    cin >> N;
    v.reserve(N);
    while(N--) {
        pair<int, int> input;
        cin >> input.first >> input.second;
        v.push_back(input);
    }

    sort(v.begin(), v.end(), cmp);

    endTime = v[0].first;
    cnt++;
    for(size_t i{1}; i < v.size(); i++){
        if(v[i].second <= endTime) {
            endTime = v[i].first;
            cnt++;
        }
    }

    cout << cnt;

}