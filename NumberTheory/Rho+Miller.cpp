#include <bits/stdc++.h>
#define fore(i,a,n) for(int i = a,to = n;i<to;i++)
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define abs_val(a) (((a)>0)?(a):-(a))
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

const int N = 100000;

ll mulmod(ll a, ll b, ll c) {
	ll x = 0, y = a %c;
	while(b > 0) {
		if(b % 2 == 1) x = (x+y)%c;
		y = (y*2)%c;
		b /=2;
	}
	return x%c;
}
ll gcd(ll a, ll b){ return !b ? a : gcd(b,a%b);}
ll expmod(ll b, ll e, ll m) {
	if(!e) return 1;
	ll q = expmod(b,e/2,m); q = mulmod(q,q,m);
	return e%2 ? mulmod(b,q,m) : q;
}

bool es_primo(ll n, int a) {
	if(n == a) return 1;
	ll s = 0, d = n-1;
	while(d%2 == 0) s++,d/=2;
	
	ll x = expmod(a,d,n);
	if((x == 1) || (x+1 == n)) return 1;
	
	fore(i,0,s-1) {
		x = mulmod(x,x,n);
		if(x == 1) return 0;
		if(x+1 == n) return 1;
	}
	return 0;
}

bool rabin(ll n) {
	if(n == 1) return 0;
	const int ar[] = {2,3,5,7,11,13,17,19,23};
	fore(j,0,9)
		if(!es_primo(n,ar[j]))	return 0;
		
	return 1; 
}
ll rho(ll n) {
	if( (n & 1LL) == 0) return 2;
	ll x = 2, y = 2, d = 1;
	ll c = rand() % n +1;
	while(d == 1) {
	
		x = (mulmod(x,x,n) + c)% n;
		y = (mulmod(y,y,n) + c)% n;
		y = (mulmod(y,y,n) + c)% n;
		if( x - y >= 0) d = gcd(x-y,n);
		else d = gcd(y-x,n);
	}
	return d == n ? rho(n):d;
}
map<ll,ll> p;
int h;
void fact(ll n) {	
	if(n == 1LL) 	return;
	if(rabin(n)) {
		p[n]++;
		return;
	}
	ll factor = rho(n);
	fact(factor);
	fact(n/factor);
}
int main() {
	ll n;//= 2063512844981574047LL; 
	/*ll ans = pollard(n); 
	if(ans > n / ans) 
		ans = n / ans;
	printf("%lld %lld\n", ans, n / ans);*/
	scanf("%lld",&n);
	fact(n);
	ll ans = 1LL;
	for(map<ll,ll>::iterator it = p.begin();it != p.end();it++)
		ans *= (it->snd+1LL);
	printf("%lld\n",ans);
}
