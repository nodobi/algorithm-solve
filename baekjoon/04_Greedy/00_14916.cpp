#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n{0}, cnt{0};
    cin >> n;
 
    if(n >= 5) {
        while(n >= 5) {
            n -= 5;
            cnt++;
        }
        if(n % 2 == 1) {
            cnt--;
            cnt += (n + 5) / 2;
        } else {
            cnt += n / 2;
        }
    } else {
        if(n % 2 == 1) {
            cnt = -1;
        }
        else {
            cnt += n / 2;
        }
    }
    cout << cnt;
}
