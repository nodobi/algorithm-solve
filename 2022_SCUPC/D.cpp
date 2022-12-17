#include <bits/stdc++.h>

using namespace std;

int main() {
    int N{0};
    cin >> N;

    int X[N], T[N], C[N];

    map<int, int> sum;

    for(int i{0}; i < N; i++) {
        cin >> X[i] >> T[i] >> C[i];
        sum[ T[i] - X[i] ] = sum[T[i] - X[i]] + C[i];
    }

    int max{-1};
    for(auto ele : sum) {
        if(ele.second > max) max = ele.second;
    }

    cout << max;
}