#include <bits/stdc++.h>

using namespace std;

pair<int, int> operator+(const pair<int, int> &l, const pair<int, int> &r)
{
    return {l.first + r.first, l.second + r.second};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N{0}, X{0}, curNum{2};
    cin >> N >> X;
    vector<vector<int>> v(N, vector<int>(N, 0));
    pair<int, int> tarPnt = {0, 0};
    pair<int, int> curPnt = {N / 2 - 1, N / 2};
    pair<int, int> dr[] = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}};

    v[N / 2][N / 2] = 1;
    if (X == 1)
        tarPnt = {N / 2, N / 2};
    for (int r{3}; r <= N; r += 2)
    {
        pair<int, int> startPnt = curPnt;

        for (int d{0}; d < 4;)
        {
            if ((curPnt + dr[d]).second < startPnt.second - 1 ||
                (curPnt + dr[d]).second > startPnt.second + (r - 2) ||
                (curPnt + dr[d]).first < startPnt.first - 1 ||
                (curPnt + dr[d]).first > startPnt.first + (r - 1))
            {
                d++;
            }
            else
            {
                if (curNum == X)
                {
                    tarPnt = curPnt;
                }
                v[curPnt.first][curPnt.second] = curNum;
                curPnt = curPnt + dr[d];
                curNum++;
            }
        }

        startPnt.first--;
        startPnt.second--;
    }

    for (int i{0}; i < N; i++)
    {
        for (int j{0}; j < N; j++)
        {
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << tarPnt.first + 1 << ' ' << tarPnt.second + 1;
}