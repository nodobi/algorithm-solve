#include <bits/stdc++.h>

using namespace std;

bool checkDiagonal1(vector<vector<int>> &v)
{
    for (int i{0}; i < 5; i++)
    {
        if (v[i][i] != -1)
        {
            return false;
        }
    }
    return true;
}
bool checkDiagonal2(vector<vector<int>> &v)
{
    for (int i{0}; i < 5; i++)
    {
        if (v[i][4 - i] != -1)
        {
            return false;
        }
    }
    return true;
}

bool checkRow(vector<vector<int>> &v, int row)
{
    for (int i{0}; i < 5; i++)
    {
        if (v[row][i] != -1)
        {
            return false;
        }
    }
    return true;
}

bool checkColumn(vector<vector<int>> &v, int column)
{
    for (int i{0}; i < 5; i++)
    {
        if (v[i][column] != -1)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    vector<vector<int>> v(5, vector<int>(5, 0));
    map<int, int> map;
    int bingo{0}, num{0};

    for (int i{0}; i < 25; i++)
    {
        cin >> num;
        map[num] = i;
        v[i / 5][i % 5] = num - 1;
    }

    for (int i{0}; i < 25; i++)
    {
        cin >> num;
        num = map[num];
        v[num / 5][num % 5] = -1;

        if (checkColumn(v, num % 5))
        {
            bingo++;
        }
        if (checkRow(v, num / 5))
        {
            bingo++;
        }
        if (num % 6 == 0)
        {
            if (checkDiagonal1(v))
            {
                bingo++;
            }
        }
        if (num % 4 == 0 && num != 0 && num != 24)
        {
            if (checkDiagonal2(v))
            {
                bingo++;
            }
        }
        if (bingo >= 3)
        {
            cout << i + 1;
            break;
        }
    }
}