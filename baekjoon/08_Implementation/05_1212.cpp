#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int curNum{0};
    string line;
    cin >> line;
    
    if(line[0] == '0') {
        cout << '0';
    }
    else if(line[0] == '1') {
        cout << '1';
    }
    else if(line[0] == '2') {
        cout << "10";
    }
    else if(line[0] == '3') {
        cout << "11";
    }
    else {
        curNum = line[0] - '4';
        cout << '1';
        cout << curNum / 2;
        cout << (curNum % 2) / 1;
    }
    
    for(size_t i{1}; i < line.size(); i++) {
        curNum = line[i] - '0';
        cout << curNum / 4;
        cout << (curNum % 4) / 2;
        cout << ((curNum % 4) % 2) / 1;
    }
}