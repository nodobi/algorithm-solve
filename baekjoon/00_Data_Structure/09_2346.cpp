#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N{0};
    cin >> N;
    deque<pair<int, int>> dq;

    for(int i{1}; i <= N; i++) {
        int move{0};
        cin >> move;
        dq.push_back(make_pair(i, move));
    }

    while(dq.size() != 1) {
        int move{dq.front().second};
        cout << dq.front().first << ' ';
        dq.pop_front();
        if(move < 0) {
            while(move++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        } else {
            move--;
            while(move--) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
    }
    cout << dq.front().first;
}