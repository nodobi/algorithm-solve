#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N{0}, K{0};

    cin >> N >> K;

    vector<int> D, S, P;
    D.resize(N + 1, 0);
    S.resize(N + 1, 0);
    P.resize(N + 1, 0);

    for(int i{1}; i <= N; i++) {
        cin >> S[i];
    }
    for(int i{1}; i <= N; i++) {
        cin >> D[i];
    }
    
    while(K--) {
        for(int i{1}; i <= N; i++) {
            P[D[i]] = S[i];
        }
        S = P;
    }

    for(int i{1}; i <= N; i++) {
        cout << S[i] << ' ';
    }
}