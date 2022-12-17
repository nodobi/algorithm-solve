#include <bits/stdc++.h>

using namespace std;

int main() {
    int N{0}, total{0};
    cin >> N;

    int P[N];
    for (int i{0}; i < N; i++) {
        cin >> P[i];
    }

    sort(P, P + N);

    for(int i {0}; i < N; i++) {
        total += P[i] * (N - i);
    }

    cout << total;
}