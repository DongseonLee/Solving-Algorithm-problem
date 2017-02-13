#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dp;
vector<vector<int>> map;

int dy[4] = {0, 0, 1, -1};
int dx[4] = { 1, -1, 0, 0 };

bool isInRange(int y, int x, int m, int n)
{
	if (y < 0 || x < 0 || y > m - 1 || x > n - 1)
		return false;
	return true;
}

void solve(int y, int x, int m, int n)
{
	for (int dir = 0; dir < 4; ++dir)
	{
		int nextY = y + dy[dir];
		int nextX = x + dx[dir];
		if (isInRange(nextY, nextX, m, n) && dp[nextY][nextX] != 0 && map[nextY][nextX] > map[y][x])
			dp[y][x] += 1;
	}
}

int main(void)
{
	int m = 0; //세로
	int n = 0; //가로

	cin >> m >> n;
	vector<int>(m, 0);
	dp = vector<vector<int>>(m, vector<int>(n, 0));
	map = vector<vector<int>>(m, vector<int>(n, 0));

	dp[0][0] = 1;

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			solve(i, j, m, n);
		}
	}

	return 0;
}