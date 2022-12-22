#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N{0}, cnt{1};
    string line;
    cin >> N;
    cin >> line;
    
    for(int i{0}; i < N - 1; i++) {
        if(line[i] == line[0]) {
            if(line[i] != line[i + 1]) {
                cnt++;
            }
        }
    }

    cout << cnt;
}