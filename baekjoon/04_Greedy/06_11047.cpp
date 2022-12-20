#include <bits/stdc++.h>

using namespace std;

int main() {
    int N{0}, K{0}, ret{0};

    cin >> N >> K;
    int coins[N];

    for(int i{0}; i < N; i++) {
        cin >> coins[i];
    }

    while(K > 0) {
        if(coins[N-1] <= K) {
             ret += (K / coins[N-1]);
             K -= (K / coins[N-1]) * coins[N-1]; 
        }
        N--;
    }

    cout << ret;
}