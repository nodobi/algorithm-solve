#include <bits/stdc++.h>

using namespace std;

int main() {
    string input;
    int num[2] = {0, };

    cin >> input;
    num[input[0] - '0']++;
    for(int i{0}; i < input.size() - 1; i++) {
        if(input[i] == input[i + 1])
            continue;
        num[input[i + 1] - '0']++;
    }
    
    cout << (num[0] > num[1] ? num[1] : num[0]);
}