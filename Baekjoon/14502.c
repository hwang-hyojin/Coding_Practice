#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int map[8][8];
int copymap[8][8];
int n,m;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
vector<pair<int,int> > v;
void bfs(int x, int y) {
	queue<pair<int,int> > q;
	q.push(make_pair(x,y));
	
	while(!q.empty()) {
		x=q.front().first;
		y=q.front().second;
		q.pop();
		
		for(int i=0; i<4; i++) {
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(0<=nx&&nx<n&&0<=ny&&ny<m) {
				if(copymap[nx][ny]==0) {
					copymap[nx][ny]=2;
					q.push(make_pair(nx,ny));
				}
			}
		}
	}
}
int main() {
	scanf("%d %d", &n, &m);
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			scanf("%d",&map[i][j]);
			copymap[i][j]=map[i][j];
			if(map[i][j]==0) { v.push_back(make_pair(i,j)); }
		}
	}
	
	int MAX=0;
	for(int i=0; i<v.size()-2; i++) {
		for(int j=i+1; j<v.size()-1; j++) {
			for(int k=j+1; k<v.size(); k++) {
				pair<int,int> a=v[i];
				pair<int,int> b=v[j];
				pair<int,int> c=v[k];
				
				for(int i=0; i<n; i++) {
					for(int j=0; j<m; j++) {
						copymap[i][j]=map[i][j];
					}
				}
				
				copymap[a.first][a.second] =1;
				copymap[b.first][b.second] =1;
				copymap[c.first][c.second] =1;
				
				for(int i=0; i<n; i++) {
					for(int j=0; j<m; j++) {
						if(copymap[i][j]==2) { bfs(i,j); }
					}
				}
				
				int cnt=0;
				
				for(int i=0; i<n; i++) {
					for(int j=0; j<m; j++) {
						if(copymap[i][j]==0) { cnt++; }
					}
				}
				
				MAX= max(MAX,cnt);
				
			}
		}
	}
	printf("%d\n", MAX);
	
}
