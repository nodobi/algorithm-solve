#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T{0}, N{0}, D{0};
    cin >> T;
    while (T--)
    {
        cin >> N >> D;
        vector<vector<pair<int, int>>> position(8, vector<pair<int, int>>(N / 2));\
        vector<vector<int>> field(N, vector<int>(N, 0));
        int rotationCnt{(D / 45) % 8}, middle{N / 2};
        for (int i{0}; i < N; i++)
        {
            for (int j{0}; j < N; j++)
            {
                cin >> field[i][j];
            }
        }

        for (int i{1}; i <= (N / 2); i++)
        {
            position[0][i - 1] = {middle - i, middle};
            position[1][i - 1] = {middle - i, middle + i};
            position[2][i - 1] = {middle, middle + i};
            position[3][i - 1] = {middle + i, middle + i};
            position[4][i - 1] = {middle + i, middle};
            position[5][i - 1] = {middle + i, middle - i};
            position[6][i - 1] = {middle, middle - i};
            position[7][i - 1] = {middle - i, middle - i};
        }

        while (rotationCnt != 0)
        {
            vector<int> tmp;
            if (rotationCnt < 0)
            {
                for (int i{0}; i < position[0].size(); i++)
                {
                    tmp.push_back(field[position[0][i].first][position[0][i].second]);
                }
                for (int i{0}; i < position.size() - 1; i++)
                {
                    for (int j{0}; j < position[i].size(); j++)
                    {
                        field[position[i][j].first][position[i][j].second] = field[position[i + 1][j].first][position[i + 1][j].second];
                    }
                }
                for (int i{0}; i < position[0].size(); i++)
                {
                    field[position[7][i].first][position[7][i].second] = tmp[i];
                }
            }
            else
            {
                for (int i{0}; i < position[0].size(); i++)
                {
                    tmp.push_back(field[position[7][i].first][position[7][i].second]);
                }

                for (int i{0}; i < position.size() - 1; i++)
                {
                    for (int j{0}; j < position[i].size(); j++)
                    {
                        field[position[7 - i][j].first][position[7 - i][j].second] = field[position[7 - (i + 1)][j].first][position[7 - (i + 1)][j].second];
                    }
                }

                for (int i{0}; i < position[0].size(); i++)
                {
                    field[position[0][i].first][position[0][i].second] = tmp[i];
                }
            }
            rotationCnt < 0 ? rotationCnt++ : rotationCnt--;
        }

        for (int i{0}; i < N; i++)
        {
            for (int j{0}; j < N; j++)
            {
                cout << field[i][j] << ' ';
            }
            cout << '\n';
        }
    }
}