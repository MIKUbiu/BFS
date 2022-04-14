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
int n, m;
void  bfs(int x, int y) {
	queue<pair<int, int>>Q;
	Q.push(make_pair(x, y));
	book[x][y] = 1;
	while (!Q.empty()) {
		auto p = Q.front();
		for (int i = 0; i < 4; i++) {
			int nx = p.first + d[i][0];
			int ny = p.second + d[i][1];//遍历四周
			if (nx<0 || ny<0 || nx>=n || ny>=m)continue;
			if (!g[nx][ny])continue;
			if (book[nx][ny])continue;
			Q.push(make_pair(nx, ny));
			book[nx][ny] = 1;
		}
		Q.pop();
	}
}
int main() {
	/*ifstream cin("A.in");*/
	int T;
	cin >> T;
	while (T--) {
	
		cin >> n>>m;
		memset(book, 0, sizeof(book));
		int area = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)cin >> g[i][j];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				if (book[i][j])continue;//被探索过的地方跳过
				if (g[i][j]) {
					++area;
					bfs(i, j);//以水池为起点探索四周，并设探索过的地方为1
				}
			}
		cout << area << endl;
	}
	return 0;
}