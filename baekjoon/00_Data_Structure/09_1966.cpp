#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int T{0}, N{0}, M{0};
    cin >> T;
    while(T--) {
        cin >> N >> M;
        int pntSheetsCnt{0}, priority[N];
        queue<int> q;
        for(int n{0}; n < N; n++) {
            int temp;
            cin >> temp;
            q.push(temp);
            priority[n] = temp;
        }
        sort(priority, priority + N, greater<int>());

        while(!q.empty()) {
            if(priority[pntSheetsCnt] == q.front()) {
                pntSheetsCnt++;
                if(M == 0) break;
            }
            else {
                q.push(q.front());
            }

            q.pop();

            if(M == 0) M += q.size();
            M--;
        }

        cout << pntSheetsCnt << '\n';
    }
}