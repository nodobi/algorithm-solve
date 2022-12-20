#include <bits/stdc++.h>

using namespace std;

int main() {
    long long total{0}, curPrice{0};
    int N{0};
    cin >> N;

    int distance[N], price[N];

    distance[0] = 0;
    for(int i{1}; i < N; i++) {
        cin >> distance[i];
    }
    for(int i{0}; i < N; i++) {
        cin >> price[i];
    }

    curPrice = price[0];
    for(int i{0}; i < N - 1; i++) {
        total += curPrice * distance[i + 1];
        if(curPrice > price[i + 1]) curPrice = price[i + 1];
    }
    cout << total;
}