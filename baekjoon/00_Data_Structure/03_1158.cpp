#include <bits/stdc++.h>

using namespace std;

int main() {
    queue<int> q, ret;
    int N{0}, K{0};
    cin >> N >> K;

    for(int i {1}; i <= N; i++) q.push(i);

    while(!q.empty()) {
        for(int i {1}; i <= K; i++) {
            if(i == K) ret.push(q.front());
            else q.push(q.front());
            q.pop();
        }
    }
    cout << "<";
    for(int i{0}; i < N-1; i++) {
        cout << ret.front() << ", ";
        ret.pop();
    }
    cout << ret.front() << '>';

}