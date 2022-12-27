#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N{0}, M{0};
    cin >> N >> M;
    
    bool switches[N + 1] {false ,};
    
    for(int i{1}; i <= N; i++) {
        cin >> switches[i];
    }

    for(int m{0}; m < M; m++) {
        int cmd, arg1, arg2;
        cin >> cmd >> arg1 >> arg2;
        switch(cmd) {
            case 1:
                switches[arg1] = arg2;
                break;
            case 2:
                for(int i{arg1}; i <= arg2; i++)
                    switches[i] = !switches[i];
                break;
            case 3:
                for(int i{arg1}; i <= arg2; i++)
                    switches[i] = false;
                break;
            case 4:
                for(int i{arg1}; i <= arg2; i++)
                    switches[i] = true;
                break;
        }
        
    }

    for(int i{1}; i <= N; i++) {
        cout << switches[i] << ' ';
    }
}