/* gives real number in [0,1] */

#include <bits/stdc++.h>
using namespace std;

void gen_realrand()
{

    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 rng(seed);

    for (int i = 1; i <= 10; i++)
        cout << rng() / (1.0 * rng.max()) << endl;
}

int main()
{
    gen_realrand();
}
