#include <stdio.h>
#include <algorithm>
using namespace std;
int n;
int day[15],T[15],P[15];
int check[15];
int solve(int day){
  if(day > n) return -987654321;
  if(day ==n) return 0;
  int ret = max(solve(day+1), solve(day+T[day])+P[day]);
  return ret;
}
int main () {
  scanf("%d", &n);
  for(int i=0; i<n; ++i){
    scanf("%d %d", &T[i], &P[i]);
    check[i] = -1;
  }
  int ret = solve(0);
  printf("%d",ret);
  return 0;
}
