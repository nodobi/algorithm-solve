#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N{0}, M{0}, gender{0}, num{0};
    cin >> N;

    bool status[N + 1];
    memset(status, false, sizeof(status));
    for (int i{1}; i <= N; i++)
    {
        cin >> status[i];
    }

    cin >> M;
    while (M--)
    {
        cin >> gender >> num;

        if (gender == 1)
        {
            for(int i{num}; i <= N; i += num) 
            {
                status[i] = !status[i];
            }
        }
        else if (gender == 2)
        {
            status[num] = !status[num];
            for(int i{1}; i <= N / 2; i++) 
            {
                if(num - i < 1 || N < num + i)
                    break;
                if(status[num - i] != status[num + i])
                    break;
                status[num - i] = !status[num - i];
                status[num + i] = !status[num + i];
            }
        }
    }
    for(int i{1}; i <= N; i++) {
        cout << status[i] << ' ';
        if(i % 20 == 0) {
            cout << '\n';
        }
    }
}