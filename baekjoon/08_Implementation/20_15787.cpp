#include <bits/stdc++.h>

using namespace std;

int getSeatValue(int seatNum)
{
    if (seatNum == 0)
        return 0;
    return 1 << seatNum - 1;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N{0}, M{0}, cmd{0}, arg1{0}, arg2{0}, ret{0};
    cin >> N >> M;

    map<int, int> m;
    vector<int> trains(N + 1, 0);

    while (M--)
    {
        cin >> cmd >> arg1;
        switch (cmd)
        {
        case 1:
            cin >> arg2;
            trains[arg1] |= getSeatValue(arg2);
            break;
        case 2:
            cin >> arg2;
            trains[arg1] &= ~getSeatValue(arg2);
            break;
        case 3:
            trains[arg1] <<= 1;
            trains[arg1] &= (1 << 20) - 1;
            break;
        case 4:
            trains[arg1] = trains[arg1] & (~1);
            trains[arg1] >>= 1;
            break;
        }
    }

    for (size_t i{1}; i <= N; i++)
    {
        if (m[trains[i]] == 0)
            ret++;
        m[trains[i]]++;
    }
    cout << ret << '\n';
}