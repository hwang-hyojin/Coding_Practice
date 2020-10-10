#include <iostream>
#include <queue>
using namespace std;
int n,m;
int map[51][51];
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
struct ROBOT{
    int y,x,dir;
};
ROBOT robot;
queue<ROBOT> q;

int main() {
  scanf("%d %d",&n, &m);
  scanf("%d %d %d",&robot.y, &robot.x, &robot.dir);
  for(int i=0; i<n; ++i){
    for(int j=0; j<m; ++j){
      scanf("%d",&map[i][j]);
    }
  }
  q.push(robot);
  int ret = 0;
  while(!q.empty()){
    ROBOT cur = q.front(); q.pop();
    if(map[cur.y][cur.x] == 0){
      map[cur.y][cur.x] = 2;
      ++ret;
    }

    for(int d=0; d<4; ++d){
      ROBOT next;
      next.dir = (cur.dir + 3 -d) %4;
      next.y = cur.y + dy[next.dir];
      next.x = cur.x + dx[next.dir];

      if(next.y<0||next.y>n||next.x<0||next.x>m||map[next.y][next.x]!=0){
        continue;
      }
      q.push(next);
      break;
    }
    if(q.empty()){
      ROBOT next;
      next.dir = cur.dir;
      next.y = cur.y + dy[(next.dir+2)%4];
      next.x = cur.x + dx[(next.dir+2)%4];

      if(next.y<0||next.y>n||next.x<0||next.x>m||map[next.y][next.x]==1){
        break;
      }
      q.push(next);
    }
  }
  printf("%d", ret);
  return 0;
}
