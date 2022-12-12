#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    stack<double> s;
    string operation;
    int N{0};
    cin >> N;
    cin >> operation;

    int varVal[N];
    for(int i{0}; i < N; i++) {
        cin >> varVal[i];
    }

    for(auto ele : operation) {
        if(ele >= 'A' && ele <= 'Z') {
            s.push(varVal[ele - 'A']);
        }else {
            double var1, var2;
            var2 = s.top();
            s.pop();
            var1 = s.top();
            s.pop();
            if(ele == '+') {
                s.push(var1 + var2);
            } else if(ele == '-') {
                s.push(var1 - var2);
            } else if(ele == '*') {
                s.push(var1 * var2);
            } else if(ele == '/') {
                s.push(var1 / var2);
            }
        }
    }

    cout << fixed;
    cout.precision(2);

    cout << s.top();
}