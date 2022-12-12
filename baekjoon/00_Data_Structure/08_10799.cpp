#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    stack<int> s;
    string str;
    int ret{0};

    cin >> str;

    for(size_t i{0}; i < str.size(); i++) {
        if(str[i] == '(') {
            if(str[i+1] == ')') {
                i++;
                ret += s.size();
            } else {
                s.push(i);
                ret++;
            }
        } else {
            s.pop();
        }
    }
    
    cout << ret;
}