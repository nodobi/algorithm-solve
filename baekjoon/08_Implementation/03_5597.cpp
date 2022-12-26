#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    bool check[31];
    memset(check, false, sizeof(check));
    for(int i{0}; i < 28; i++) {
        int num;
        cin >> num;
        check[num] = true;
    }
    
    for(int i{1}; i <= 30; i++) {
        if(!check[i])
            cout << i << '\n';
    }
}