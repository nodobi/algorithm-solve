#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T{0};
    cin >> T;

    for(int t{0}; t < T; t++) {
        int N{0}, max{-1000001}, min{1000001};
        cin >> N;

        for(int n{0}; n < N; n++) {
            int tmp{0};
            cin >> tmp;
            max = max < tmp ? tmp : max;
            min = min < tmp ? min : tmp;
        }
        cout << min << ' ' << max << '\n';
    }
}