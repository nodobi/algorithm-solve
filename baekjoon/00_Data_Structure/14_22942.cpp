#include <bits/stdc++.h>
#define MIDDLE 1010004

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N{0};
    cin >> N;

    vector<int> axis(MIDDLE * 2, 0);
    axis.reserve(MIDDLE * 2);
    
    for(int i{1}; i <= N; i++) {
        int x{0}, r{0};
        cin >> x >> r;
        if(axis[x - r + MIDDLE] != 0 || axis[x + r + MIDDLE] != 0) {
            cout << "NO";
            return 0;
        }
        axis[x - r + MIDDLE] = -i;
        axis[x + r + MIDDLE] = i;
    }

    stack<int> s;
    for(int i{0}; i < MIDDLE * 2; i++) {
        int tmp{axis[i]};

        if(tmp != 0) {
            if(s.empty()) {
                s.push(tmp);
            } else {
                if(tmp < 0) {
                    s.push(tmp);
                } else {
                    if((s.top() * -1) == tmp) {
                        s.pop();
                    } else {
                        cout << "NO";
                        return 0;
                    }
                }
            }
        }
    }
    cout << "YES";

}