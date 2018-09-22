void getDivisor(int n,vector<int>&v) {

	/* v for storing all divisor and prime has been alresdy calculated using sieve. */
	v.emplace_back(1);
	for(int i=0;prime[i]*prime[i]<=n;i++) {
		int mul = 1;
        int tem = v.size();

		while(n%prime[i]==0) {
			n/=prime[i];
			mul*=prime[i];
			for(int j=0;j<tem;j++){
				v.emplace_back(mul*v[j]);
			}
		}
	}

	if(n!=1){
		int tem = v.size();
		for(int j=0;j<tem;j++){
			v.emplace_back(v[j]*n);
		}
	}
}
