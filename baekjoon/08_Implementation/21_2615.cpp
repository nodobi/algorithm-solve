#include <bits/stdc++.h>

using namespace std;


// 우측 대각선, 우측, 우측 하단, 하단
pair<int,int> dir[4] = {
    {-1, 1},
    {0, 1},
    {1, 1}, 
    {1, 0}
};

bool sol(vector<vector<int>> &field, int i, int j, int cnt, int d) {
    if(cnt > 5)
        return false;
    
    // 초기 입력시 모든 방향에 대해 탐색
    if(d == -1) {
        for(int k{0}; k < 4; k++) {
            if(i + dir[k].first > 19 || i + dir[k].first < 1 || j + dir[k].second > 19)
                break;
            if(field[i + dir[k].first][j + dir[k].second] == field[i][j]) {
                return sol(field, i + dir[k].first, j + dir[k].second, cnt + 1, k);
            }
        }
    }
    // 방향이 결정된 경우, 해당 방향으로 탐색
    else {
        // 5개를 탐색했고, 다음 좌표의 값과, 초기 좌표 반대편의 값을 비교하여 참 반환
        if(cnt == 5 && field[i + dir[d].first][j + dir[d].second] != field[i][j]) {
            if(field[i][j] == field[i - (dir[d].first * 5)][j - (dir[d].second * 5)])
                return false;
            return true;
        }
        
        // 아직 탐색횟수가 모자르다면, 값 확인 후 같은 경우 다음 칸 탐색
        if(field[i + dir[d].first][j + dir[d].second] == field[i][j])
            return sol(field, i + dir[d].first, j + dir[d].second, cnt+ 1, d);
    }
    return false;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    vector<vector<int>> field(21, vector<int>(21, 0));

    for(int i{1}; i <= 19; i++) {
        for(int j{1}; j <= 19; j++) {
            cin >> field[i][j];
        }
    }

    for(int i{1}; i <= 19; i++) {
        for(int j{1}; j <= 19; j++) {
            if(field[i][j] > 0) {
                if(sol(field, i, j, 1, -1)) {
                    cout << field[i][j] << '\n';
                    cout << i << ' ' << j;
                    return 0;
                }
            }
        }
    }
    cout << 0;
    return 0;
}