#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int cowPos[11];
    memset(cowPos, -1, sizeof(cowPos));
    int N{0}, ret{0};;
    cin >> N;

    for(int n{0}; n < N; n++) {
        int num, pos;
        cin >> num >> pos;
        if(cowPos[num] == -1) {
            cowPos[num] = pos;
        }
        else if(cowPos[num] != pos){
            cowPos[num] = pos;
            ret++;
        }
    }

    cout << ret;
}