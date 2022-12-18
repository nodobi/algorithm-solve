#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T{0}, ret{0};
    string bits;
    cin >> T;

    for(int t{0}; t < T; t++) {
        cin >> bits;
        ret = 0;
        for(int i {0}; i < 24; i++) {
            if(bits[23 - i] == '0') continue;
            ret += pow((bits[23 - i] - '0') * 2, i);
        }
        cout << ret << '\n';
    }
}