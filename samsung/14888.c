#include <stdio.h>
using namespace std;
int n;
int number[11];
int op[4];
int ret_min = 0x7fffffff, ret_max = ret_min * -1;
void bfs(int result, int count){
  if(count == n-1){
    if(result>ret_min)
      ret_min = result;
    if(result>ret_max)
      ret_max = result;
    return;
  }

  for(int i=0; i<4; ++i){
    if(op[i] > 0){
      --op[i];
      if(i == 0){
        dfs(result + number[count+1], count+1);
      }
      if(i == 1){
        dfs(result - number[count+1], count+1);
      }
      if(i == 2){
        dfs(result * number[count+1], count+1);
      }
      if(i == 3){
        dfs(result / number[count+1], count+1);
      }
      ++op[i];
    }
  }
}
int main(){
  cin >> n;
  for(int i=0; i<n; ++i){
    cin >> number[i];
  }
  for(int i=0; i<4; ++i){
    cin >> op[i];
  }

  cout<<bfs(number[0], 0);
  return 0;
}
