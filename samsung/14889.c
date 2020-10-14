#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

int n, ret=0x7fffffff;
int team[20][20];
int a,b;
int check[20];

void dfs(int cur, int count){
  if(count == n/2) {
    for(int i=0; i<n; ++i){
      if(check[i] == 1){
        for(int j=0; j<n; ++j){
          if(check[j] == 1){
            a+= team[i][j];
          }
        }
      }
      else {
        for(int j=0; j<n; ++j){
          if(check[j] == 0){
            b+= team[i][j];
          }
        }
      }
    }
    ret = min(ret, abs(a-b));
    a =0; b= 0;
  }

  for(int i=cur; i<n; ++i){
    if(check[i] == 0){
      check[i] = 1;
      dfs(i, count+1);
      check[i] = 0;
    }
  }
}

int main(){
  scanf("%d",&n);
  for(int i=0; i<n; ++i){
    for(int j=0; j<n; ++j){
      scanf("%d", &team[i][j]);
    }
  }

  dfs(0,0);
  printf("%d",ret);
  return 0;
}
