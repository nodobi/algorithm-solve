#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N{0};
    cin >> N;
    
    int tension[N];

    for(int i{0}; i < N; i++) {
        cin >> tension[i];
    }

    sort(tension, tension + N, greater<int>());

    int max{tension[0]};
    for(int i{1}; i < N; i++) {
        int curMax{tension[i] * (i + 1)};
        if(curMax > max) max = curMax;
    }
    
    cout << max;
}  