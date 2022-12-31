#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N{0};
    map<string, int> m;
    cin >> N;
    for(int n{0}; n < N; n++) {
        string input;
        cin >> input;
        m[input.substr(input.find('.') + 1)]++;
    }

    for(auto ele : m) {
        cout << ele.first << ' ' << ele.second << '\n';
    }
}