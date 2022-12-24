#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N{0}, K{0}, cost{0};
    cin >> N >> K;
    vector<int> v(N, 0);

    cin >> v[0];
    for(int n{1}; n < N; n++) {
        cin >> v[n];
        v[n - 1] = v[n] - v[n - 1];
    }

    v.pop_back();  
    sort(v.begin(), v.end());

    for(size_t i{0}; i < N - K; i++) {
        cost += v[i];
    }

    cout << cost;
}