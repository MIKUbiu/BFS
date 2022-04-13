#include<iostream>
#include<vector>
#include<queue>
#include<fstream>
//#include<bits/stdc++.h>
using namespace std;
const int maxn = 100;
int g[maxn][maxn];
int book[maxn][maxn];
int d[][2] = { {0,1},{1,0},{-1,0},{0,-1} };//方向数组
int  bfs(int x, int y) {
	queue<pair<int,int>>Q;
	Q.push(make_pair(x, y));
	book[x][y] = 1;
	int cnt = 0;
	while (!Q.empty()) {
		auto p = Q.front();
		for (int i = 0; i < 4; i++) {
			int nx = p.first+ d[i][0];
			int ny = p.second + d[i][1];
			if (nx<0 || ny<0 || nx>maxn || ny>maxn)continue;
			if (!g[nx][ny])continue;
			if (book[nx][ny])continue;
			Q.push(make_pair(nx, ny));
			book[nx][ny] = 1;
		}
		Q.pop();
		cnt++;
	}
	return cnt;
}
int main() {
	/*ifstream cin("A.in");*/
	int m, n, x, y;
	while (cin >> m >> n >> x >> y) {
		memset(book, 0, sizeof(book));
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)cin >> g[i][j];
		
		cout << bfs(x, y) << endl;
	}
	return 0;
}
