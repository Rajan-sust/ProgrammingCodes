#include <bits/stdc++.h>
using namespace std;

using pt = pair<int,int>;

int main(int argc, char const *argv[])
{
	auto cmp = [](const pt &a,const pt &b) {
		return (a.first<b.second) or ((a.first==b.second) and (a.second<b.second));
	};

	set<pt,decltype(cmp)>s(cmp);

	s.insert({1,2});

	auto it = *s.begin();
	cout<<it.first<<endl;

	
	
	return 0;
}
