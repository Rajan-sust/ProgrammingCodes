#include<bits/stdc++.h>
using namespace std;

void genRealRand() {
  
  auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
  mt19937 generator(seed);
  uniform_real_distribution<double> distribution(0.0,1.0); /*generate in close-open [a,b)*/

  for (int i = 1; i <= 10; i++) 
    cout << distribution(generator) << endl;
}

int main() {
  genRealRand();

}
