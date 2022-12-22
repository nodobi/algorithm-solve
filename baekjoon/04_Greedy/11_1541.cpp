#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int ret{0};
    bool flag{false};
    string line, buf;
    cin >> line;

    for(size_t i{0}; i <= line.size(); i++) {
        if(line[i] == '-' || line[i] == '+' || i == line.size()) {
            if(flag) {
                ret -= stoi(buf);
            } else {
                ret += stoi(buf);
                if(line[i] == '-') 
                    flag = true;
            }
            buf.clear();
        } else {
            buf += line[i];
        }
    }
    cout << ret;
}