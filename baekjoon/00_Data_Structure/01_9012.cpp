#include <bits/stdc++.h>

using namespace std;

int main() {
    int N{0};
    string input;
    cin >> N;
    while(N--) {
        int base{0};
        cin >> input;
        for(auto &ele : input) {
            base += ((ele == '(') - (ele == ')'));
            if(base < 0) break;
        }
        cout << (base == 0 ? "YES" : "NO") << endl;
    }
    return 0;   
}