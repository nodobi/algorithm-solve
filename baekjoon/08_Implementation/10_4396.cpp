#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N{0};
    char input;
    bool isBoom{0};
    cin >> N;
    vector<vector<char>> field(N + 2, vector<char>(N + 2, '0'));
    vector<vector<bool>> revealed(N + 2, vector<bool>(N + 2, false));

    for (int i{1}; i <= N; i++)
    {
        for (int j{1}; j <= N; j++)
        {
            cin >> input;
            if (input != '*')
                continue;
            field[i][j] = '*';
            for (int y{-1}; y <= 1; y++)
            {
                for (int x{-1}; x <= 1; x++)
                {
                    if (field[i + y][j + x] != '*')
                    {
                        field[i + y][j + x]++;
                    }
                }
            }
        }
    }

    for (int i{1}; i <= N; i++)
    {
        for (int j{1}; j <= N; j++)
        {
            cin >> input;
            if (input != 'x')
                continue;
            revealed[i][j] = true;
            if (field[i][j] == '*')
                isBoom = true;
        }
    }

    for (int i{1}; i <= N; i++)
    {
        for (int j{1}; j <= N; j++)
        {
            if (revealed[i][j])
                cout << field[i][j];
            else if (isBoom && field[i][j] == '*')
                cout << field[i][j];
            else
                cout << '.';
        }
        cout << '\n';
    }
}