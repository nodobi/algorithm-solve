#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N{0};
    cin >> N;

    int price[N];
    for(int i {0}; i < N; i++) {
        cin >> price[i];
    }

    sort(price, price + N, greater<int>());

    int total{0};
    for(int i {0}; i < N / 3; i++) {
        for(int j{0}; j < 2; j++) {
            total += price[j + (i * 3)];
        }
    }
    for(int i {(N / 3) * 3}; i < N; i++) {
        total += price[i];
    }

    cout << total;
}