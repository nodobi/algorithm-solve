#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N{0}, M{0}, ret{0};

    cin >> N >> M;

    int lamp[M + 1] = {0, };
    vector<int> switches[N];
    for(int i {0}; i < N; i++) {
        switches[i].reserve(M);
    }
    for(int i{0}; i < N; i++) {
        int tmp{0};
        cin >> tmp;
        while(tmp--) {
            int connect{0};
            cin >> connect;
            lamp[connect]++;
            switches[i].push_back(connect);
        }
    }

    for(int i{0}; i < N; i++) {
        ret = 1;
        for(auto ele : switches[i]) {
            if(lamp[ele] < 2) ret = 0;
        }
        if(ret) break;
    }

    cout << ret;
}