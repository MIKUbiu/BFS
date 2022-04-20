#include<iostream>
#include<vector>
#include<queue>
//#include<bits/stdc++.h>
using namespace std;
//第一行有两个数n 和m。n表示迷宫的行，m表示迷宫的列。接来下来n行m列为迷宫，0表示空地，1表示障碍物。最后一行4个数，前两个数为迷宫入口的x和y坐标。后两个为小哈的x和y坐标。


//一个整数表示小哼到小哈的最短步数。如果不能解救小哈则输出No Way!
const int maxn = 101;
int g[maxn][maxn];
int book[maxn][maxn];
int dp[maxn][maxn];
int dir[][2] = { {0,1},{1,0},{-1,0},{0,-1} };
int n, m;
int sx, sy, ex, ey;
int bfs(int x, int y) {
	queue<pair<int, int>>Q;
	book[x][y] = 1;
	dp[x][y] = 0;
	Q.push(make_pair(x, y));
	int cnt = 0;
	while (!Q.empty())
	{	
		auto p = Q.front();
		int d = dp[p.first][p.second];
		for (int i = 0; i < 4; i++) {
			int nx = p.first + dir[i][0];
			int ny = p.second + dir[i][1];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (book[nx][ny] || g[nx][ny])continue;
			book[nx][ny] = 1;
			Q.push(make_pair(nx, ny));
			dp[nx][ny] = d + 1;
		}
		Q.pop();//忘记pop()了！
		cnt++;
	}
	return cnt;
}
int main() {

	while (cin >> n >> m ) {
		memset(dp, -1, sizeof(dp));
		memset(book, 0, sizeof(book));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)cin >> g[i][j];
		}
		cin >> sx >> sy >> ex >> ey;
		sx--; sy--; ex--; ey--;
		bfs(sx, sy);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
			{
				cerr << dp[i][j] << " ";
			}cerr << endl;
		}
		if (dp[ex][ey] == -1)cout << "No Way!" << endl;
		else cout << dp[ex][ey] << endl;
	}
	return 0;
}
