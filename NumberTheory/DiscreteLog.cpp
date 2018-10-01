/*input
3
3 9 11
2 3 5
2 1 5
*/

/*

Assuming answer exist

a^x = b (mod m)
n = sqrt(m)
a^i*n-j = b (mod m)
a^i*n = b*a^j (mod m)

*/

#include <bits/stdc++.h>
using namespace std;


typedef long long ll;


inline ll dis_log(ll a,ll b,ll m) {

	if(b==1) return 0;

	
	ll n = sqrt(1.0*m) + 1;
	ll an = 1;

	for(int i=1;i<=n;i++) {
		an = (an*a)%m;
	}

	map<ll,ll> mp;
    ll mul = an;

	for(int i=1;i<=n;i++) {
       mp[mul] = i;
       mul = (mul*an)%m;
	}

	for(ll j=0,cur=b;j<n;j++) {

		if(mp.count(cur)){
			return n*mp[cur]-j;
		}
		cur = (cur*a)%m;
	}
}


int main(int argc, char const *argv[])
{
	int test;
	scanf("%d",&test);

	while(test--){
		ll a,b,m;
		scanf("%lld %lld %lld",&a,&b,&m);
		printf("%lld\n",dis_log(a,b,m));

		
	}

	
	
	return 0;
}
