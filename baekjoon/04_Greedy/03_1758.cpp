#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N{0};
    cin >> N;
    
    int tips[N];
    for(int i{0}; i < N; i++) {
        cin >> tips[i];
    }

    sort(tips, tips + N, greater<int>());

    long long ret{0};
    for(int i{0}; i < N; i++) {
        if(tips[i] - i > 0)
            ret += tips[i] - i;
        else 
            break;
    }

    cout << ret;
}