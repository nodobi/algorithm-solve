#include <bits/stdc++.h>

using namespace std;

int main() {
    int A{0}, B{0}, cnt{0};

    cin >> A >> B;

    while(A < B) {
        cnt++;
        if(B % 2) {
            if(B % 10 == 1) {
                B /= 10;
            } else {
                break;
            }
        } else {
            B /= 2;
        }
    }
    cout << (A == B ? cnt + 1 : -1);
}