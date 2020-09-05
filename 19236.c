#include <iostream>
#include <algorithm>
using namespace std;

struct FISH {
	int x;
	int y;
	int dir;
	bool live;
};

int dy[] = {0,-1,-1,-1,0,1,1,1};
int dx[] = {-1,-1,0,1,1,1,0,-1};

int dfs(int originmap[4][4], int x, int y, int dir,FISH originfish[17])
{
	//이전 값 복사해놓기
	int map[4][4];
	FISH fish[17];
	
	for(int i=0; i<4; ++i){
		for(int j=0; j<4; ++j){
			map[i][j] = originmap[i][j];
		}
	}
	for(int i=0; i<17; ++i)
		fish[i] = originfish[i];
	
	//상어위치 설정
	int eat = map[x][y];
	dir = fish[map[x][y]].dir;
	
	//상어 위치 -1로 표시, live false로 바꿔주기
	fish[map[x][y]].x = -1;
	fish[map[x][y]].y = -1;
	fish[map[x][y]].live = false;
	map[x][y] = 0; //상어가 먹음
	
	int ans = 0;
	
	//물고기 이동 작은 물고기부터 16칸 다 돌기
	for(int i = 1; i<= 16; ++i){
		if(fish[i].live == true){
			
			int cx = fish[i].x;
			int cy = fish[i].y;
			
			//방향 바꾸기
			//조건에 맞는 8방향을 모두 탐색해야하니까 d는 7까지
			for(int d=0; d<=7; ++d){
				int nx = fish[i].x + dx[fish[i].dir];
				int ny = fish[i].y + dy[fish[i].dir];
				
				//next 값이 상어의 위치와 같다면 45도 회전
				if(nx == x && ny == y) { 
					fish[i].dir = (fish[i].dir+1)%8;
					continue;
				}
				
				//범위를 벗어난다면 45도 회전
				if(nx<0||nx>3||ny<0||ny>3){
					fish[i].dir = (fish[i].dir+1)%8;
					continue;
				}
				
				//조건에 걸리지않는다면 위치 저장 후 종료
				cx = nx;
				cy = ny;
				break;
			}
			//이부분은 뭐지 ?
			//next위치의 물고기와 자리 바꾸기
			if(map[cx][cy] == 0) { //물고기가 없다면?
				map[fish[i].x][fish[i].y] = 0;
				map[cx][cy] = i;
				fish[i].x = cx;
				fish[i].y = cy;
			}
			else {
				int tx, ty, tmp;
				tx = fish[i].x;
				ty = fish[i].y;
				fish[i].x = cx;
				fish[i].y = cy;
				fish[map[cx][cy]].x = tx;
				fish[map[cx][cy]].y = ty;
				
				map[tx][ty] = map[cx][cy];
				map[cx][cy] = i;
			}
		}
	} //물고기 이동 종료
	
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	
	while(!(nx<0||nx>3||ny<0||ny>3)){
		if(map[nx][ny] != 0)
			ans = max(ans, dfs(map,nx,ny,dir,fish));
		nx += dx[dir];
		ny += dy[dir];
	}
	return ans + eat;
}

int main() {

	int map[4][4] = {0};
	FISH fish[17];
	
	for(int i=0; i<4; ++i){
		for(int j=0; j<4; ++j){
			int n, d;
			scanf("%d %d", &n, &d);
			map[i][j] = n; //map 정보 저장
			fish[n] = { i, j, d-1, true}; //fish 정보 저장
		}
	}
	
	printf("%d\n",dfs(map,0,0,0,fish));
	return 0;
}
