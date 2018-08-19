#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ (h2<<32);  
    }
};

int main(int argc, char const *argv[])
{
	gp_hash_table<pair<int,int>,int,pair_hash> mp;

	mp[{1,2}] = 5;
	mp[{3,5}] = 7;

	cout<<mp[{1,2}]<<endl;

	
	
	return 0;
}
