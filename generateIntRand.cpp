#include <bits/stdc++.h>
using namespace std;


void genIntRand()
{
	auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	mt19937 generator(seed);

	/*generate in close [a,b]*/

    uniform_int_distribution<int> distribution(1,10);

    for(int i=1;i<=10;i++){
    	cout<<distribution(generator)<<endl;
    }

    
}

int main()
{
	genIntRand();
	
}
