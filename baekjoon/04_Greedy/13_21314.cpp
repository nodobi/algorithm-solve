#include <bits/stdc++.h>

using namespace std;

int main() {
    string line, min, max;
    int cnt{0};
    cin >> line;
    
    for(size_t i{0}; i < line.size(); i++) {
        if(line[i] == 'M') {
            cnt++;
        } else {
            if(cnt > 0){
                min += '1';
                min += string(cnt - 1, '0');
                cnt = 0;
            }
            min += '5';
        }
    }
    if(cnt > 0){
        min += '1';
        min += string(cnt - 1, '0');
    }

    cnt = 0;
    for(size_t i{0}; i < line.size(); i++) {
        if(line[i] == 'M') {
            cnt++;
        } else {
            max += '5';
            max += string(cnt, '0');
            cnt = 0;
        }
    }
    if(cnt > 0) {
        max += string(cnt, '1');
    }
    


    cout << max << '\n';
    cout << min;
}