#include <bits/stdc++.h>

using namespace std;
pair<int, int> dir[4] = {
	{0, 1},		// 오른쪽
	{1, 0},		// 아래
	{0, -1},	// 왼쪽
	{-1, 0}};	// 위

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N{0}, M{0}, R{0};
	cin >> N >> M >> R;

	vector<vector<int>> field(N + 2, vector<int>(M + 2, -1));
	queue<int> q[min(N, M) / 2];

	for (int i{1}; i <= N; i++)
	{
		for (int j{1}; j <= M; j++)
		{
			cin >> field[i][j];
		}
	}

	for (int i{0}; i < min(N, M) / 2; i++)
	{
		int width{M - 2 * i}, height{N - 2 * i};
		int cy{i + 1}, cx{i + 1};
		int d{0};
		// 큐에 채워야 하는 원소 개수만큼 반복
		while (q[i].size() < (width - 2) * 2 + (height * 2))
		{
			int ny{cy + dir[d].first}, nx{cx + dir[d].second};

			q[i].push(field[cy][cx]);
			// 범위가 넘어가면, 방향전환하고 다음 좌표값 설정
			if (nx > width + i || nx < i + 1 || ny > height + i || ny < i + 1)
			{
				d++;
				ny = cy + dir[d].first;
				nx = cx + dir[d].second;
			}
			// 다음 좌표값으로 이동
			cy = ny;
			cx = nx;
		}
	}

	while(R--) {
		for (int j{0}; j < min(N, M) / 2; j++)
		{
			q[j].push(q[j].front());
			q[j].pop();
		}
	}

	for (int i{0}; i < min(N, M) / 2; i++)
	{
		int width{M - 2 * i}, height{N - 2 * i};
		int d{0};
		int cy{i + 1}, cx{i + 1};
		while (!q[i].empty())
		{
			int ny{cy + dir[d].first}, nx{cx + dir[d].second};

			field[cy][cx] = q[i].front();
			q[i].pop();
			// 범위가 넘어가면, 방향전환하고 다음 좌표값 대입
			if (nx > width + i || nx < i + 1 || ny > height + i || ny < i + 1)
			{
				d++;
				ny = cy + dir[d].first;
				nx = cx + dir[d].second;
			}
			// 좌표 변경
			cy = ny;
			cx = nx;
		}
	}

	for (int i{1}; i <= N; i++)
	{
		for (int j{1}; j <= M; j++)
		{
			cout << field[i][j] << ' ';
		}
		cout << '\n';
	}
}