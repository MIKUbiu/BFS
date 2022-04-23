#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
const int maxn=5;
int m[maxn][maxn];
int book[maxn][maxn];
struct Node{
    int x,y;
}pa[maxn][maxn];
int drt[][2]={{0,1},{1,0},{0,-1},{-1,0}
};
void Putin(){
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            cin>>m[i][j];
}
void bfs(){
    queue<pair<int,int>>Q;
    Q.push(make_pair(4,4));
    book[4][4]=1;
    while(!Q.empty()){
        auto p=Q.front();
        for(int i=0;i<4;i++){
            int nx=p.first+drt[i][0];
            int ny=p.second+drt[i][1];
            if(nx<0||ny<0||nx>=5||ny>=5)continue;
            if(m[nx][ny])continue;
            if(book[nx][ny])continue;
            book[nx][ny]=1;
            Q.push(make_pair(nx,ny));
            pa[nx][ny].x=p.first;//每一个扩散节点的内容记录了父节点的坐标
            pa[nx][ny].y=p.second;//唯独根节点没有记录坐标，所以他的值是默认值

        }
        Q.pop();
    }
}
int main() {
    Putin();
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
        {pa[i][j].x=-1;
            pa[i][j].y=-1;}
    bfs();
    int x=0;int y=0;

//    for(int i=0;i<5;i++){
//    	for(int j=0;j<5;j++)
//    	cerr<<pa[i][j].x<<" "<<pa[i][j].y<<endl;
//    	cout<<endl;
//	}
//	 for(int i=0;i<5;i++){
//    	for(int j=0;j<5;j++)
//    	cerr<<book[i][j]<<" "<<book[i][j]<<endl;
//    	cerr<<endl;
//	}
    while(true){
        cout<<"("<<x<<","<<y<<")"<<endl;
        int nx=pa[x][y].x;
        int ny=pa[x][y].y;
        if(nx==-1&&ny==-1)break;
        x=nx;
        y=ny;
    }


    return 0;
}
