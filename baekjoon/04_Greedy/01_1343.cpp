#include <bits/stdc++.h>

using namespace std;

int main() {
    string line;
    cin >> line;

    string ret;
    for(int i{0}; i < line.size(); i++) {
        if(line[i] == 'X') {
            int cnt{0};
            while(line[i] == 'X' && i < line.size()) {
                cnt++;
                i++;
            }
            if(cnt % 2) {
                ret = "-1";
                break;
            }

            for(int j{0}; j < cnt / 4; j++) {
                ret += "AAAA";
            }
            if(cnt % 4 == 2) {
                ret += "BB";
            } 
        }
        if(line[i] == '.') {
            ret += ".";
        }
    }

    cout << ret;
}