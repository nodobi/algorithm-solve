#include <bits/stdc++.h>

using namespace std;

void printLine(int num, int curNum)
{
    for (int i{0}; i < num - curNum; i++)
        cout << '*' << ' ';

    for (int i{0}; i < 4 * curNum - 3; i++)
        cout << '*';

    for (int i{0}; i < num - curNum; i++)
        cout << ' ' << '*';

    cout << '\n';
}

void printSpaceLine(int num, int curNum)
{
    for (int i{0}; i < num - curNum; i++)
        cout << '*' << ' ';

    for (int i{0}; i < 4 * curNum - 3; i++)
    {
        if (i == 0 || i == 4 * curNum - 4)
            cout << '*';
        else
            cout << ' ';
    }
    for (int i{0}; i < num - curNum; i++)
        cout << ' ' << '*';

    cout << '\n';
}

void print(int num, int curNum)
{
    if (curNum == 1)
    {
        printLine(num, curNum);
        return;
    }
    printLine(num, curNum);
    printSpaceLine(num, curNum);

    print(num, curNum - 1);

    printSpaceLine(num, curNum);
    printLine(num, curNum);

    return;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N{0};
    cin >> N;

    print(N, N);

    return 0;
}