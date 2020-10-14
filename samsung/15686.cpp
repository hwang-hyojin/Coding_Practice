#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
struct POSI{
  int y,x;
};
vector<POSI> house, shop, pick;
int n, m, type, ret=0x7fffffff;
void dfs(int pos){
	if(pick.size() == m){
		int candi = 0;
		for(int i=0; i<house.size(); ++i){
			int ans = 0x7fffffff;
			for(int j=0; j<pick.size(); ++j){
				ans = min(ans, abs(house[i].y-pick[j].y) +
									abs(house[i].x-pick[j].x));
			}
			candi += ans;
		}
		if (candi < ret){
			ret = candi;
		}
		return;
	}
	for(int i=pos; i<shop.size(); ++i){
		pick.push_back(shop[i]);
		dfs(i+1);
		pick.pop_back();
	}
}
int main(){

  scanf("%d %d",&n,&m);
  for(int y=0; y<n; ++y){
    for(int x=0; x<n; ++x){
      scanf("%d",&type);
      if(type == 1){
        house.push_back({y,x});
      }
			if(type == 2){
        shop.push_back({y,x});
      }
    }
  }

  dfs(0);
  printf("%d",ret);
  return 0;
}
