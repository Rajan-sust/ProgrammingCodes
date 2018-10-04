#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout<<#x<<" is "<<(x)<<'\n'
const int mx = 1e4 + 1;


vector < int > edges[mx];
bitset< mx > vis;
int matched[mx];
int N;

int bpm(int u) {

    for(int v: edges[u]){
        if(vis.test(v))continue;
        vis.set(v);

        if(matched[v]==-1 or bpm(matched[v])){
            matched[v] = u;
            return 1;
        }
    }

    return 0;
}

int matching() {

   int cnt = 0;

   for(int u = 0; u < N; u++) {
      vis.reset();
      cnt += bpm(u);
   }

   return cnt;
}
void clear(int n) {
	
    for(int i=0;i<=n;i++)
        edges[i].clear();
    for(int i=0;i<=n;i++)
        matched[i] = -1;


}
