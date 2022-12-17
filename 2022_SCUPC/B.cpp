#include <bits/stdc++.h>

using namespace std;

bool comp(pair<string, string> p1, pair<string, string> p2) {
    if(p1.first == p2.first)
        return p1.second > p2.second;
    else 
        return p1 < p2;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N{0};
    cin >> N;

    vector<pair<string, string>> list;
    list.reserve(N);

    for(int i{0}; i < N; i++) {
        string mentor, mentee;
        cin >> mentor >> mentee;
        list.push_back(make_pair(mentor, mentee));
    }

    sort(list.begin(), list.end(), comp);
    
    for(int i {0}; i < N; i++) {
        cout << list[i].first << ' ' << list[i].second << '\n';
    }
}