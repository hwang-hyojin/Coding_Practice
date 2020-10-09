#include <stdio.h>
#define MIN(a,b) (a<b?a:b);
#define MAX(a,b) (a>b?a:b);
int n, sum = 0;
int map[21][21];

int solve(int x, int y, int d1, int d2){
  int temp[21][21] = { 0, };
  temp[x][y] = 5;
  for(int i=1; i<=d1; ++i){
    temp[x+i][y-i] = 5;
    temp[x+d2+i][y+d2-i]=5;
  }
  for(int i=1; i<=d2; ++i){
    temp[x+i][y+i]=5;
    temp[x+d1+i][y-d1+i] = 5;
  }

  int a=0;
  for(int r=1; r<x+d1; ++r){
    for(int c=1; c<=y; ++c){
      if(temp[r][c] == 5) break;
      else a += map[r][c];
    }
  }
  int b=0;
  for(int r=1; r<x+d2; ++r){
    for(int c=n; c>y; --c){
      if(temp[r][c] == 5) break;
      else b += map[r][c];
    }
  }
  int c=0;
  for(int r=x+d1; r<=n; ++r){
    for(int c=1; c<y-d1+d2; ++c){
      if(temp[r][c] == 5) break;
      else c += map[r][c];
    }
  }
  int d=0;
  for(int r=x+d2+1; r<=n; ++r){
    for(int c=n; c>=y-d1+d2; --c){
      if(temp[r][c] == 5) break;
      else d += map[r][c];
    }
  }
  int e = sum - a- b-c-d;
  int max_val = (MAX(a,MAX(b,MAX(c,MAX(d,e)))));
  int min_val = (MIN(a,MIN(b,MIN(c,MIN(d,e)))));
  return max_val - min_val;
}

int main()
{
  scanf("%d", &n);
  for(int x=1; x<=n; ++x){
    for(int y=1; y<=n; ++y){
      scanf("%d", &map[x][y]);
      sum += map[x][y;]
    }
  }
  int ret = 0x7fffffff;
  for(int x=1; x<=n; ++x){
    for(int y=1; y<=n; ++y){
      for(int d1 =1; d1<=n; ++d1){
        for(int d2=1; d2<=n; ++d2){
          if(x+d1+d2 > n)continue;
          if(1 > y-d1)   continue;
          if(y+d2 > n)   continue;
          ret = MIN(ret, solve(x,y,d1,d2));
        }
      }
    }
  }
  printf("%d\n",ret);
  return 0;
}
