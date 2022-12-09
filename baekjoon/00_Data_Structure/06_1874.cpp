#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N{0};
    stack<int> s;
    queue<char> q;
    cin >> N;
    vector<int> seq(N, -1);
    for(int i{0}; i < seq.size(); i++) {
        cin >> seq[i];
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i{1}; i <= N; i++) pq.push(i);
    
    int cursor{0};
    
    for(int i{0}; i < N * 2; i++) {
        if(s.empty()){
            s.push(pq.top());
            q.push('+');
            pq.pop();
        } else {
            if(s.top() == seq[cursor]) {
                cursor++;
                q.push('-');
                s.pop();
            } else {
                s.push(pq.top());
                pq.pop();
                q.push('+');
            }
        }
    }

    if(!s.empty() || !pq.empty())
        cout << "NO" << '\n';
    else{
        while(!q.empty()) {
            cout << q.front() << '\n';
            q.pop();
        }
    }
}