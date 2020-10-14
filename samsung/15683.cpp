#include <stdio.h>
using namespace std;
int n,m,cnt,ret = 0x7fffffff;
int map[8][8];
int rot[] = {4,2,4,4,1};
struct CCTV{
  int y,x,type;
};
CCTV cctv[8];
void copy(int desc[8][8],int src[8][8]){
  for(int y=0; y<n; ++y){
    for(int x=0; x<m; ++x){
      desc[y][x] = src[y][x];
    }
  }
}
void update(int dir, CCTV cctv){
  dir = (dir%4);

  if(dir == 0){
    for(int x= cctv.x+1; x<m;++x){
      if(map[cctv.y][x]==6) break;
      map[cctv.y][x] = -1;
    }
  }

  if(dir == 1){
    for(int y= cctv.y-1; y>=0; --y){
      if(map[y][cctv.x]==6) break;
      map[y][cctv.x] = -1;
    }
  }

  if(dir == 2){
    for(int x= cctv.x-1; x>=0;--x){
      if(map[cctv.y][x]==6) break;
      map[cctv.y][x] = -1;
    }
  }

  if(dir == 3){
    for(int y= cctv.y+1; y<n; ++y){
      if(map[y][cctv.x]==6) break;
      map[y][cctv.x] = -1;
    }
  }

}
void dfs(int index){
  if(index == cnt){
    int candi = 0;
    for(int y=0; y<n; ++y){
      for(int x=0; x<m; ++x){
        if(map[y][x] == 0)
          ++candi;
      }
    }
    if(candi < ret)
      ret = candi;
    return;
  }
  int backup[8][8];
  int type = cctv[index].type;
  for(int i=0; i<rot[type]; ++i){
    copy(backup, map);
    if(type == 0){
        update(i, cctv[index]);
    }
    if(type == 1){
        update(i, cctv[index]);
        update(i + 2, cctv[index]);
    }
    if(type == 2){
      update(i, cctv[index]);
      update(i+1, cctv[index]);
    }
    if(type == 3){
      update(i, cctv[index]);
      update(i+1, cctv[index]);
      update(i+2, cctv[index]);
    }
    if(type == 4){
      update(i, cctv[index]);
      update(i+1, cctv[index]);
      update(i+2, cctv[index]);
      update(i+3, cctv[index]);
    }
    dfs(index + 1);
    copy(map,backup);
  }
}
int main() {
  scanf("%d %d",&n, &m);
  for(int y=0; y<n; ++y){
    for(int x=0; x<m; ++x){
      scanf("%d", &map[y][x]);
      if(map[y][x]!=0 && map[y][x]!=6){
        cctv[cnt].y = y;
        cctv[cnt].x = x;
        cctv[cnt].type = map[y][x]-1;
        ++cnt;
      }
    }
  }
  dfs(0);
  printf("%d", ret);
  return 0;
}
