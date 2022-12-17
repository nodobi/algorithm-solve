#include <bits/stdc++.h>

using namespace std;

int alpToInt(int alp) {
    return alp -'A' + 1;
}
char intToAlp(int num) {
    return num - 1 + 'A';
}

int main() {
    string plain;
    string result;
    cin >> plain;
    cin >> result;

    int N{(int)plain.size()};
    vector<int> vec;
    vec.reserve(N);
    for(int i {0}; i < N; i++) {
        if(plain[i] >= result[i])
            vec.push_back(alpToInt(result[i]) + 26);
        else 
            vec.push_back(alpToInt(result[i]));
        vec[i] -= alpToInt(plain[i]);
        ret = intToAlp(vec[i]);
    }

    string ret;
    

    cin >> N;
}