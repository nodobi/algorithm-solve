#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N{0};
    long long ret{0};
    cin >> N;
    unordered_map<int, long long> m;

    while(N--) {
        int X{0}, T{0}, C{0};
        cin >> X >> T >> C;
        m[T-X] += C;
    }
    
    for(auto e : m) {
        ret = max(ret, e.second);
    }

    cout << ret;
}