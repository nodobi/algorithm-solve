#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    string sec = "security";
    string big = "bigdata";

    int N{0};
    string line;
    
    cin >> N;
    cin >> line;
    int base{0};
    for(int i{0}; i < line.size();) {
        if(line[i] == 's') {
            i += sec.size();
            base++;
        } else if(line[i] == 'b') {
            i += big.size();
            base--;
        }
    }
    if(base <= 0) cout << "bigdata?";
    if(base == 0) cout << ' ';
    if(base >= 0) cout << "security!";

}