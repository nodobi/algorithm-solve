#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T{0}, N{0};
    cin >> T;
    
    for(int t{0}; t < T; t++) {
        cin >> N;
        if(N % 2 == 1) N++;
        
        cout << pow(N / 2 ,2) << '\n';
    }
}