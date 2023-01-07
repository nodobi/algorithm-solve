#include <bits/stdc++.h>

using namespace std;

struct cmp
{
    bool operator()(const pair<int, int> &p1, const pair<int, int> &p2)
    {
        return p1.second > p2.second;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N{0}, height{0}, sum{0}, end{0}, start{0};
    cin >> N;

    vector<pair<int, int>> task(N);
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    for (int i{0}; i < N; i++)
    {
        cin >> task[i].first >> task[i].second;
    }

    sort(task.begin(), task.end());

    pq.push(task[0]);
    height = 1;
    start = task[0].first;
    end = task[0].second;
    for (int i{1}; i <= N; i++)
    {
        if (i == N)
        {
            sum += height * (end - start + 1);
            break;
        }
        while (pq.top().second < task[i].first && !pq.empty())
        {
            pq.pop();
        }
        if (pq.empty() && pq.top().second + 1 != task[i].first)
        {
            sum += height * (end - start + 1);
            height = 0;
            start = task[i].first;
            end = 0;
        }
        pq.push(task[i]);
        height = height < pq.size() ? pq.size() : height;
        end = end < task[i].second ? task[i].second : end;
    }

    cout << sum;
}