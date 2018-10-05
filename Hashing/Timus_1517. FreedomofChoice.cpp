#include <bits/stdc++.h>
using namespace std;

char a[100005],b[100005];

const int mod1 = 1000000007,base1 = 57;
const int mod2 = 1000000223,base2 = 31;

int prea1[100005],prea2[100005],preb1[100005],preb2[100005],pw1[100005],pw2[100005];


int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);

	scanf("%s",a+1);
	scanf("%s",b+1);

	//string s1(a+1),s2(b+1);

	//cout<<s1<<" "<<s2<<"\n";

	pw1[0] = pw2[0] = 1;


	for(int i=1;i<=n;i++) {
		prea1[i] = (1ll*a[i]*pw1[i-1]+prea1[i-1])%mod1;
		prea2[i] = (1ll*a[i]*pw2[i-1]+prea2[i-1])%mod2;


		
		preb1[i] = (1ll*b[i]*pw1[i-1]+preb1[i-1])%mod1;
		preb2[i] = (1ll*b[i]*pw2[i-1]+preb2[i-1])%mod2;
		pw1[i] = (1ll*pw1[i-1]*base1)%mod1;
		pw2[i] = (1ll*pw2[i-1]*base2)%mod2;
	}



	int mx = 0,pos = -1;


	int lo = 1,hi = n;

	while(lo<=hi) {
		int mid = (lo+hi)/2;
        
        vector< pair<int,int> > v;

		int l = 1,r = mid,idx = n;

		while(r<=n){
			int x = (prea1[r]-prea1[l-1])%mod1;
			x = (x+mod1)%mod1;
			x = (1ll*pw1[idx]*x)%mod1;
			int y = (prea2[r]-prea2[l-1])%mod2;
			y = (y+mod2)%mod2;
			y = (1ll*pw2[idx]*y)%mod2;
			v.push_back({x,y});
			idx--,l++,r++;
		}

		l = 1,r = mid,idx = n;
		bool ok = false;

		sort(v.begin(),v.end());


		while(r<=n) {
			int x = (preb1[r]-preb1[l-1])%mod1;
			x = (x+mod1)%mod1;
			x = (1ll*pw1[idx]*x)%mod1;
			int y = (preb2[r]-preb2[l-1])%mod2;
			y = (y+mod2)%mod2;
			y = (1ll*pw2[idx]*y)%mod2;

			if(binary_search(v.begin(),v.end(),make_pair(x,y)))
			{
				pos = l;
				mx = max(mx,mid);
				ok = true;
				break;
			}
			
			idx--,l++,r++;
		}

		if(ok){
			lo = mid + 1;
		}else{
			hi = mid - 1;
		}

		




	}

	//cout<<mx<<" "<<pos<<"\n";

	for(int i=1;i<=mx;i++){
		printf("%c",b[pos]);
		pos++;
	}

	printf("\n");


	



	return 0;
}
